// Fill out your copyright notice in the Description page of Project Settings.


#include "PiezaGrandeBuilder.h"
#include "Pieces.h"

// Sets default values
APiezaGrandeBuilder::APiezaGrandeBuilder()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APiezaGrandeBuilder::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void APiezaGrandeBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APiezaGrandeBuilder::SpawnPieza()
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

void APiezaGrandeBuilder::BuildBloques()
{
	if (!Piece) { UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); return; }
	else {
		Piece->SpawnBlocks("Madera", 6);
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

APieces* APiezaGrandeBuilder::GetPiece()
{
	return Piece;
}

