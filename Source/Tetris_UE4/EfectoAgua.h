// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EfectoArtificial.h"
#include "EfectoAgua.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEfectoAgua : public AEfectoArtificial
{
	GENERATED_BODY()
public:
	AEfectoAgua();

	virtual void Tick(float DeltaTime) override;
	virtual void Recorrido() override;

	UPROPERTY()
		UStaticMeshComponent* BlockMesh;
};
