// Fill out your copyright notice in the Description page of Project Settings.


#include "WallState.h"

// Sets default values
AWallState::AWallState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);

		BlockMesh->SetRelativeLocation(FVector(0.0f, -150.0f, 0.0f));
		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
		BlockMesh->SetMaterial(0, MyMaterial);

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
	}
}

// Called when the game starts or when spawned
void AWallState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

