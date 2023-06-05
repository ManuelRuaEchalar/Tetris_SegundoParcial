// Fill out your copyright notice in the Description page of Project Settings.


#include "PiezaClasicaBuilder.h"
#include "Pieces.h"

// Sets default values
APiezaClasicaBuilder::APiezaClasicaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APiezaClasicaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiezaClasicaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APiezaClasicaBuilder::SpawnPieza()
{

	if (Piece == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("NULLPTR DE PIEZA CRUZ!"));
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("SI HAY PIEZA! en PIEZA CRUZ"));
	}
	FVector Location(0.0, 5, 175);
	FRotator Rotation(0.0, 0.0, 0.0);
	Piece = GetWorld()->SpawnActor<APieces>(APieces::StaticClass(), Location, Rotation);
	Piece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

}

void APiezaClasicaBuilder::BuildBloques()
{
	if (!Piece) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	else {
		Piece->SpawnBlocks("Normal", 4);
	}
}

//void APiezaGrandeBuilder::BuildFormas()
//{
//	if (!Piece) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
//	Piece->SetFormas({
//		{TPair<float, float>(-20.0f, 0.0f), TPair<float, float>(-10.0f, 0.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(10.0f, 0.0f)},
//		{TPair<float, float>(0.0f, 10.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(10.0f, 0.0f), TPair<float, float>(20.0f, 0.0f)},
//		{TPair<float, float>(-20.0f, 0.0f), TPair<float, float>(-10.0f, 0.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(0.0f, 10.0f)},
//		{TPair<float, float>(0.0f, 0.0f), TPair<float, float>(10.0f, 0.0f), TPair<float, float>(0.0f, -10.0f), TPair<float, float>(10.0f, -10.0f)},
//		{TPair<float, float>(-10.0f, -10.0f), TPair<float, float>(0.0f, -10.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(10.0f, 0.0f)},
//		{TPair<float, float>(-10.0f, 0.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(0.0f, 10.0f), TPair<float, float>(10.0f, 0.0f)},
//		{TPair<float, float>(-10.0f, 0.0f), TPair<float, float>(0.0f, 0.0f), TPair<float, float>(0.0f, -10.0f), TPair<float, float>(10.0f, -10.0f)}
//		});
//}

APieces* APiezaClasicaBuilder::GetPiece()
{
	return Piece;
}


