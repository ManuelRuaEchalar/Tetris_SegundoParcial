// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PiezaBuilder.h"
#include "Director.generated.h"

UCLASS()
class TETRIS_UE4_API ADirector : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADirector();

protected:
	// Called when the game starts or when spawned
	IPiezaBuilder* PiezaBuilder;
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConstructPiece();
	void SetPieceBuilder(AActor* Builder);
	class APieces* GetPiece();

};
