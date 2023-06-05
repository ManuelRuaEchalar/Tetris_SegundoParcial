// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorBloques.h"

void ADecoradorBloques::BuildObstaculo()
{
	Super::BuildObstaculo();
	AgregarBloques();
}
void ADecoradorBloques::AgregarBloques()
{
	B = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass());
	Blocks.Add(B);
	B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	B->SetActorRelativeLocation(FVector(0.0, -20, 40));
	B = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass());
	Blocks.Add(B);
	B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	B->SetActorRelativeLocation(FVector(0.0, 10, 100));
}