// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlockFactory.h"
#include "MyBasicBlockFactory.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_UE4_API AMyBasicBlockFactory : public ABlockFactory
{
	GENERATED_BODY()
public:

	virtual ABlock* CreateBlock(FString BlockSKU) override;
	
};


