// Fill out your copyright notice in the Description page of Project Settings.


#include "EfectoAgua.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"

AEfectoAgua::AEfectoAgua()
{
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* SphereComponent = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(5.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 150.0f, 30.0f));
		SphereVisual->SetWorldScale3D(FVector(0.1f));
	}
	UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	//ParticleSystem=CreateAbstractDefaultSubobject<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"))
	SphereVisual->SetMaterial(0, MyMaterial);
}

void AEfectoAgua::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Recorrido();
}

void AEfectoAgua::Recorrido()
{
	UE_LOG(LogTemp, Warning, TEXT("EFECTO FUEGO!"));
	FVector limite = GetActorLocation();
	if (limite.Y > -80)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Y -= 0.2;
		SetActorLocation(NewLocation);
	}
	if (limite.Y <= -80)
	{
		Destroy();
	}
}
