// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "EfectoFuego.h"
#include "EfectoAgua.h"

// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacade::CrearEfectos()
{
	int ale = FMath::FRandRange(0, 1);
	switch (ale)
	{
	case 0:
		Fuego = GetWorld()->SpawnActor<AEfectoFuego>(AEfectoFuego::StaticClass());
		break;
	case 1:
		Agua = GetWorld()->SpawnActor<AEfectoAgua>(AEfectoAgua::StaticClass());
		break;
	default:
		Agua = GetWorld()->SpawnActor<AEfectoAgua>(AEfectoAgua::StaticClass());
		break;
	}
	
	
}