// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"

// Sets default values
AObstaculo::AObstaculo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstaculo::BuildObstaculo()
{
	for (int i = 0; i < 2; ++i)
	{

		B = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass());
		Blocks.Add(B);
		B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		B->SetActorRelativeLocation(FVector(0.0, pos, 100));
		pos += 10;
	}
}
