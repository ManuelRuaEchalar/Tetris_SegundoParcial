// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BloqueOro.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ABloqueOro : public ABlock
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ABloqueOro();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void MostrarInfo() override;

	UPROPERTY()
		UStaticMeshComponent* BlockMesh;

};
