// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

ABloqueMadera::ABloqueMadera() {
	PrimaryActorTick.bCanEverTick = true;
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);

		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
		BlockMesh->SetMaterial(0, MyMaterial);

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
	}

}
void ABloqueMadera::MostrarInfo() {

	UE_LOG(LogTemp, Log, TEXT("BLOQUE DE MADERA"));
}

void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

