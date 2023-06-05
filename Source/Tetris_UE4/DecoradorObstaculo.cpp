// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorObstaculo.h"

// Sets default values
ADecoradorObstaculo::ADecoradorObstaculo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoradorObstaculo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADecoradorObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoradorObstaculo::SetObs(IComponenteObstaculo* Obstaculo)
{
	Estorbo = Cast<IComponenteObstaculo>(Obstaculo);
}

void ADecoradorObstaculo::BuildObstaculo()
{
	Estorbo->BuildObstaculo();
}

