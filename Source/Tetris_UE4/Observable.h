// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Observable.generated.h"

UCLASS()
class TETRIS_UE4_API AObservable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObservable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Notify() PURE_VIRTUAL(AObservable::Notify, );
};
