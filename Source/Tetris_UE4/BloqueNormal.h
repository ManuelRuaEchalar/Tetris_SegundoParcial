// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BloqueNormal.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ABloqueNormal : public ABlock
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloqueNormal();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void MostrarInfo() override;

	UPROPERTY()
		UStaticMeshComponent* BlockMesh;
	UPROPERTY()
		TArray<class UMaterial*> Colors;

	void AsignarMesh(int NumColor);
};
