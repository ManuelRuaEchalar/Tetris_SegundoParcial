// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaBuilder.h"
#include "PiezaSimpleBuilder.generated.h"

UCLASS()
class TETRIS_UE4_API APiezaSimpleBuilder : public AActor, public IPiezaBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiezaSimpleBuilder();
	class APieces* Piece;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildBloques() override;
	virtual void SpawnPieza() override;

	virtual class APieces* GetPiece() override;
};
