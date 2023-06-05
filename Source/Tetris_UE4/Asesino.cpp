// Fill out your copyright notice in the Description page of Project Settings.


#include "Asesino.h"


void AAsesino::Notify()
{
    for (AObserver* Sub : Subs)
    {
        Sub->Reportar();
    }
}

void AAsesino::Accion()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("REALIZANDO EL ASESINATO")));
    Notify();
}

void AAsesino::attach(AObserver* Observer)
{
    Subs.Add(Observer);
}

