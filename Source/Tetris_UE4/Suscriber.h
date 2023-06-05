// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Observer.h"
#include "Observable.h"
#include "Suscriber.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ASuscriber : public AObserver
{
	GENERATED_BODY()
public:
	ASuscriber();

	UPROPERTY()
		UStaticMeshComponent* BlockMesh;

	AObservable* Observable;
	void SetObservable(AObservable* Observado);
	virtual void Reportar() override;


};
