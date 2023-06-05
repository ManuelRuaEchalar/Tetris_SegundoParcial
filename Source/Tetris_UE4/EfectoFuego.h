// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EfectoArtificial.h"
#include "EfectoFuego.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AEfectoFuego : public AEfectoArtificial
{
	GENERATED_BODY()
public:
		AEfectoFuego();

		virtual void Tick(float DeltaTime) override;
		virtual void Recorrido() override;

		UPROPERTY()
			UStaticMeshComponent* BlockMesh;
};
