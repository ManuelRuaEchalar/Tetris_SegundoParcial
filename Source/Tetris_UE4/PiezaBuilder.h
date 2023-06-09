// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PiezaBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPiezaBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TETRIS_UE4_API IPiezaBuilder
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void BuildBloques() = 0;
	virtual class APieces* GetPiece() = 0;
	virtual void SpawnPieza() = 0;
};
