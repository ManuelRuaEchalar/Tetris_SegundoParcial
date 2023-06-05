// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponenteObstaculo.h"
#include "DecoradorObstaculo.generated.h"

UCLASS()
class TETRIS_UE4_API ADecoradorObstaculo : public AActor, public IComponenteObstaculo
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	ADecoradorObstaculo();
	IComponenteObstaculo* Estorbo;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildObstaculo() override;

	

	void SetObs(IComponenteObstaculo* Obstaculo);

	

};
