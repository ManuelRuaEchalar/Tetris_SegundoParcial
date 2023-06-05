// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Observable.h"
#include <functional>
#include <Observer.h>
#include "Asesino.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AAsesino : public AObservable
{
	GENERATED_BODY()
public:

	TArray<AObserver*> Subs;
	virtual void Notify() override;
	void Accion();
	void attach(AObserver* Observer);
};
