// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBasicBlockFactory.h"
#include "BloqueNormal.h"
#include "BloqueMadera.h"
#include "BloqueOro.h"

ABlock* AMyBasicBlockFactory::CreateBlock(FString BlockSKU)
{
	if (BlockSKU.Equals("Normal")) {
		class ABloqueNormal* B= GetWorld()->SpawnActor<ABloqueNormal>(ABloqueNormal::StaticClass());
		B->AsignarMesh(NumColor);
		return B;
	}
	else if (BlockSKU.Equals("Madera")) {
		return GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass());
	}
	else if (BlockSKU.Equals("Oro")) {
		return GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid
}


