// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOro.h"

ABloqueOro::ABloqueOro() {
	PrimaryActorTick.bCanEverTick = true;
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	RootComponent = BlockMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMeshAsset(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockMeshAsset.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockMeshAsset.Object);

		BlockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

		UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
		//UMaterialInterface* MyMaterial1 = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/M_Metal_Rust.M_Metal_Rust'"));
		//BlockMesh->SetMaterial(1, MyMaterial1);
		BlockMesh->SetMaterial(0, MyMaterial);

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No existe la malla para Block"));
	}



	// Attach the movable block component to the root component
	//MovableBlockComponent->SetupAttachment(RootComponent);


}
void ABloqueOro::MostrarInfo() {

	UE_LOG(LogTemp, Log, TEXT("BLOQUE DE ORO"));
}

void ABloqueOro::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloqueOro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
