// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoradorObstaculo.h"
#include "DecoradorBloques.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API ADecoradorBloques : public ADecoradorObstaculo
{
	GENERATED_BODY()
public:
	virtual void BuildObstaculo() override;
	void AgregarBloques();
};
