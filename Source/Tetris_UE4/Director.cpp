// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"

// Sets default values
ADirector::ADirector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector::ConstructPiece()
{
	if (!PiezaBuilder) { UE_LOG(LogTemp, Error, TEXT("ConstructLodging(): LodgingBuilder is NULL, make sure it's initialized.")); return; }
	PiezaBuilder->SpawnPieza();
	PiezaBuilder->BuildBloques();
	//PiezaBuilder->BuildTipoBloques();
	//PiezaBuilder->BuildFormas();
}
void ADirector::SetPieceBuilder(AActor* Builder)
{
	PiezaBuilder = Cast<IPiezaBuilder>(Builder);
	if (!PiezaBuilder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
	}
}
APieces* ADirector::GetPiece()
{
	if (PiezaBuilder)
	{
		return PiezaBuilder->GetPiece();
	}
	UE_LOG(LogTemp, Error, TEXT("GetLodging(): Return nullptr"));
	return nullptr;
}

