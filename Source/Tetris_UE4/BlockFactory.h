// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "BlockFactory.generated.h"

UCLASS()
class TETRIS_UE4_API ABlockFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Create Potion and returns it. It's pure virtual, so it doesn't need an
	//implementation in this class
		virtual ABlock* CreateBlock(FString BlockSKU)PURE_VIRTUAL(ABlockFactory::CreateBlock, return nullptr;);
	//Order, concoct and returns a Potion of a specific Category
	ABlock* OrderBlock(FString Category);
	int NumColor;

};
