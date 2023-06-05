// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockFactory.h"

// Sets default values
ABlockFactory::ABlockFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NumColor = FMath::RandRange(0, 6);
}

// Called when the game starts or when spawned
void ABlockFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABlock* ABlockFactory::OrderBlock(FString Category)
{
	ABlock* Block = CreateBlock(Category);

	return Block;

}
