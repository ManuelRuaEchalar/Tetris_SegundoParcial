// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "EngineUtils.h"
#include "Director.h"
#include "PiezaGrandeBuilder.h"
#include "PiezaClasicaBuilder.h"
#include "PiezaSimpleBuilder.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Puntaje.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<USoundCue> LineRemove_Sound(TEXT("SoundCue'/Game/Sounds/line-remove_Cue.line-remove_Cue'"));
    if(LineRemove_Sound.Succeeded())
    {
        LineRemoveSoundCue = LineRemove_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> MoveToEnd_Sound(TEXT("SoundCue'/Game/Sounds/force-hit_Cue.force-hit_Cue'"));
    if(MoveToEnd_Sound.Succeeded())
    {
        MoveToEndSoundCue = MoveToEnd_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> GameStart_Sound(TEXT("SoundCue'/Game/Sounds/start_Cue.start_Cue'"));
    if(GameStart_Sound.Succeeded())
    {
        GameStartSoundCue = GameStart_Sound.Object;
    }
    
    static ConstructorHelpers::FObjectFinder<USoundCue> GameOver_Sound(TEXT("SoundCue'/Game/Sounds/gameover_Cue.gameover_Cue'"));
    if(GameOver_Sound.Succeeded())
    {
        GameOverSoundCue = GameOver_Sound.Object;
    }
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

    PiezaGrandeBuilder = GetWorld()->SpawnActor<APiezaGrandeBuilder>(APiezaGrandeBuilder::StaticClass());
    PiezaClasicaBuilder= GetWorld()->SpawnActor<APiezaClasicaBuilder>(APiezaClasicaBuilder::StaticClass());
    PiezaSimpleBuilder= GetWorld()->SpawnActor<APiezaSimpleBuilder>(APiezaSimpleBuilder::StaticClass());
    Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());

    Facade= GetWorld()->SpawnActor<AFacade>(AFacade::StaticClass());

    Asesino = GetWorld()->SpawnActor<AAsesino>(AAsesino::StaticClass());
    Suscriber1= GetWorld()->SpawnActor<ASuscriber>(ASuscriber::StaticClass());
    Asesino->attach(Suscriber1);

    Wall= GetWorld()->SpawnActor<AWallState>(AWallState::StaticClass());

    //Create 4 Inventory
    for (int i = 0; i <= 4; i++)
    {
        APuntaje* SpawnedInventory = GetWorld() -> SpawnActor<APuntaje>(APuntaje::StaticClass());
        if (SpawnedInventory)
        {
            //If the Spawn succeeds, set the Spawned inventory to the local one
            //and log the success string
            Puntaje = SpawnedInventory;
            GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"),*Puntaje->GetName()));
        }
    }

	
    for(TActorIterator<APieces> it(GetWorld()); it; ++it)
    {
        if(it->GetFName() == TEXT("DissmissPieces"))
        {
            it->Dismiss();
            it->Destroy();
        }
    }
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    if(bGameOver)
    {
        return;
    }

    switch(Status)
    {
        case PS_NOT_INITED:
            NewPieces();
            CoolLeft = CoolDown;
            Status = PS_MOVING;
            break;
        case PS_MOVING:
            CoolLeft -= DeltaTime;
            if(CoolLeft <= 0.0f)
            {
                MoveDown();
            }
            break;
        case PS_GOT_BOTTOM:
            CoolLeft -= DeltaTime;
            if(CoolLeft <= 0.0f)
            {
                if(CurrentPieces)
                {
                    CurrentPieces->Dismiss();
                    CurrentPieces->Destroy();
                    Puntaje->UpdateScore();
                }
                CurrentPieces = nullptr;
                NewPieces();
                CoolLeft = CoolDown;
                Status = PS_MOVING;
            }
            break;
        default:
            break;
    }
}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Rotate", IE_Pressed, this, &ABoard::Rotate);
    PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ABoard::MoveLeft);
    PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABoard::MoveRight);
    PlayerInputComponent->BindAction("MoveDownToEnd", IE_Pressed, this, &ABoard::MoveDownToEnd);
    //PlayerInputComponent->BindAction("NewPieces", IE_Pressed, this, &ABoard::NewPieces);
    //PlayerInputComponent->BindAction("CheckLine", IE_Pressed, this, &ABoard::CheckLine);
}

void ABoard::Rotate()
{
    if(CurrentPieces && Status != PS_GOT_BOTTOM)
    {
        CurrentPieces->TestRotate();
    }
}

void ABoard::MoveLeft()
{
    if(CurrentPieces)
    {
        CurrentPieces->MoveLeft();
        if(Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveRight()
{
    if(CurrentPieces)
    {
        CurrentPieces->MoveRight();
        if(Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveDown()
{
    if(CurrentPieces)
    {
        if(!CurrentPieces->MoveDown())
        {
            Status = PS_GOT_BOTTOM;
        }
        CoolLeft = CoolDown;
    }
}

void ABoard::NewPieces()
{
    CheckLine();
    if(CurrentPieces)
    {
        CurrentPieces->Dismiss();
        CurrentPieces->Destroy();
    }
    
    FVector Location(0.0, 5.0, 195.0);
    FRotator Rotation(0.0, 0.0, 0.0);
    
    int selectorBuilders = FMath::RandRange(0, 5);
    switch (selectorBuilders)
    {
    case 0:
        Director->SetPieceBuilder(PiezaSimpleBuilder);
        break;
    case 1:
        Director->SetPieceBuilder(PiezaSimpleBuilder);
        break;
    case 2:
        Director->SetPieceBuilder(PiezaSimpleBuilder);
        break;
    case 3:
        break;
    case 4:
        Director->SetPieceBuilder(PiezaClasicaBuilder);
        break;
    case 5:
        Director->SetPieceBuilder(PiezaGrandeBuilder);
        break;
    }

    Director->ConstructPiece();
    CurrentPieces = Director->GetPiece();

    if (selectorBuilders < 3)
    {
        int ale = FMath::FRandRange(0, 10);
        UE_LOG(LogTemp, Warning, TEXT("Num aleatorio: %d"), ale);
        if (ale < 3)
        {
            UE_LOG(LogTemp, Warning, TEXT("LA PIEZA TIENE MENOS DE TRES BLOQUES!"));
            MovimientoAleatorio();
            GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoard::Terminar, 3.0f, false);

        }
    }

    if (Puntaje->score == 50)
    {
        Obstaculo = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass());
        Obstaculo->BuildObstaculo();

        Asesino->Accion();
    }

    if (Puntaje->score == 70)
    {
        Facade->CrearEfectos();
    }
    if (Puntaje->score == 100)
    {
        DecoradorBloques = GetWorld()->SpawnActor<ADecoradorBloques>(ADecoradorBloques::StaticClass());
        DecoradorBloques->SetObs(Obstaculo);
        DecoradorBloques->BuildObstaculo();
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoard::DestruirObstaculo, 6.0f, false);
    }

    bGameOver = CheckGameOver();
    if(bGameOver)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game Over!!!!!!!!"));
        if(GameOverSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameOverSoundCue, GetActorLocation(), GetActorRotation());
        }
    }
}

void ABoard::CheckLine()
{
    auto MoveDownFromLine = [this](int z){
        FVector Location(0.0f, 0.0f, 5.0*z + 100.0);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        FVector Extent(4.5f, 49.5f, 95.0+4.5-5.0*z);
        CollisionShape.SetBox(Extent);
        DrawDebugBox(GetWorld(), Location, Extent, FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        if(GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam))
        {
            for(auto&& Result: OutOverlaps)
            {
                FVector NewLocation = Result.GetActor()->GetActorLocation();
                NewLocation.Z -= 10.0f;
                Result.GetActor()->SetActorLocation(NewLocation);
            }
        }
    };
    
    int z = 0;
    while(z < 20)
    {
        FVector Location(0.0f, 0.0f, 10.0f * z + 5.0f);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        CollisionShape.SetBox(FVector(4.0f, 49.0f, 4.0f));
        //DrawDebugBox(GetWorld(), Location, FVector(4.5f, 49.5f, 4.5f), FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        bool b = GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam);
        if(!b || OutOverlaps.Num() < 10)
        {
            ++z;
            continue;
        }
        else // this line is full, remove the line
        {
            UE_LOG(LogTemp, Warning, TEXT("Find FULL LINE at z=%d"), z);
            for(auto&& Result: OutOverlaps)
            {
                Result.GetActor()->Destroy();
            }
            MoveDownFromLine(z);
            
            if(LineRemoveSoundCue)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), LineRemoveSoundCue, GetActorLocation(), GetActorRotation());
            }
        }
    }
}

void ABoard::MoveDownToEnd()
{
    if(!CurrentPieces)
    {
        return;
    }
    
    while(CurrentPieces->MoveDown())
    {
    }
    
    if(MoveToEndSoundCue)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveToEndSoundCue, GetActorLocation(), GetActorRotation());
    }
    
    switch(Status)
    {
        case PS_MOVING:
            Status = PS_GOT_BOTTOM;
            CoolLeft = CoolDown;
            break;
        case PS_GOT_BOTTOM:
            break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("Wrong status for MoveDownToEnd"));
            break;
    }
}

bool ABoard::CheckGameOver()
{
    if(!CurrentPieces)
    {
        UE_LOG(LogTemp, Warning, TEXT("NoPieces"));
        return true;
    }
    
    return CurrentPieces->CheckWillCollision([](FVector OldVector){ return OldVector; });
}

void ABoard::MovimientoAleatorio()
{
    AdaptadorMovimientoAleatorio1 = NewObject<UAdaptadorMovimientoAleatorio_CA>(CurrentPieces);
    AdaptadorMovimientoAleatorio1->RegisterComponent();
}

void ABoard::Terminar()
{
    AdaptadorMovimientoAleatorio1->DestroyComponent();
}

void ABoard::DestruirObstaculo()
{
    DecoradorBloques->Destroy();
}