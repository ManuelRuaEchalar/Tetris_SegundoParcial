// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS(Abstract)
class TETRIS_UE4_API ABlock : public AActor
{
	GENERATED_BODY()
protected:
	int vida;
public:
	ABlock();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	virtual void MostrarInfo() PURE_VIRTUAL(ABlock::MostrarInfo, );
	virtual void AsignarColor(int NumColor) PURE_VIRTUAL(ABlock::AsignarColor, );
	/*virtual void reducirVida() PURE_VIRTUAL(ABlock::reducirVida, );*/

};
