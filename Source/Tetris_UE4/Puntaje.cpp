// Fill out your copyright notice in the Description page of Project Settings.


#include "Puntaje.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameEngine.h"

// Sets default values
APuntaje::APuntaje()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Search for existing Instances of this class
	TArray<AActor*> Instances;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuntaje::StaticClass(), Instances);
	if (Instances.Num() > 1)
	{
		//If exist at least one of them, set the instance with the first found one
		Instance = Cast<APuntaje>(Instances[0]);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s already exists"), *Instance->GetName()));
		//Then Destroy this Actor
		Destroy();
	}
	score = 0;
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Puntaje: %d"), score));
}

// Called when the game starts or when spawned
void APuntaje::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APuntaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuntaje::UpdateScore()
{
	score += 10;
	FString ValorVariable = FString::FromInt(score);
	FString Mensaje = TEXT("Puntaje: ") + ValorVariable;
	float TiempoDeVisualizacion = 5.0f;
	FColor Color = FColor::Green;
	GEngine->AddOnScreenDebugMessage(-1, TiempoDeVisualizacion, Color, Mensaje);
//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Puntaje: %d"), score));
}
