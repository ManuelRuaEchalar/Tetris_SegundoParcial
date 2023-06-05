// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueNormal.h"

ABloqueNormal::ABloqueNormal() {
	PrimaryActorTick.bCanEverTick = true;

    struct FConstructorStatics
    {
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_0;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_1;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_2;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_3;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_4;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_5;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_6;
        FConstructorStatics()
            : Color_0(TEXT("Material'/Game/Mesh/Material_0.Material_0'"))
            , Color_1(TEXT("Material'/Game/Mesh/Material_1.Material_1'"))
            , Color_2(TEXT("Material'/Game/Mesh/Material_2.Material_2'"))
            , Color_3(TEXT("Material'/Game/Mesh/Material_3.Material_3'"))
            , Color_4(TEXT("Material'/Game/Mesh/Material_4.Material_4'"))
            , Color_5(TEXT("Material'/Game/Mesh/Material_5.Material_5'"))
            , Color_6(TEXT("Material'/Game/Mesh/Material_6.Material_6'"))
        {
        }
    };
    static FConstructorStatics ConstructorStatics;
    Colors.Add(ConstructorStatics.Color_0.Get());
    Colors.Add(ConstructorStatics.Color_1.Get());
    Colors.Add(ConstructorStatics.Color_2.Get());
    Colors.Add(ConstructorStatics.Color_3.Get());
    Colors.Add(ConstructorStatics.Color_4.Get());
    Colors.Add(ConstructorStatics.Color_5.Get());
    Colors.Add(ConstructorStatics.Color_6.Get());

    BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
    RootComponent = BlockMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

    if (BlockMeshAsset.Succeeded())
    {
        BlockMesh->SetStaticMesh(BlockMeshAsset.Object);

        BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

        UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));
        //UMaterialInterface* MyMaterial1 = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Metal_Rust.M_Metal_Rust'"));
        //BlockMesh->SetMaterial(1, MyMaterial1);
        BlockMesh->SetMaterial(0, MyMaterial);
        //BlockMesh->SetMaterial(1, Colors[NumColor]);

    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
    }


}
void ABloqueNormal::MostrarInfo() {

	UE_LOG(LogTemp, Log, TEXT("BLOQUE NORMAL"));
}

void ABloqueNormal::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloqueNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABloqueNormal::AsignarMesh(int NumColor)
{
   
    BlockMesh->SetMaterial(1, Colors[NumColor]);


    // Attach the movable block component to the root component
    //MovableBlockComponent->SetupAttachment(RootComponent);
}
