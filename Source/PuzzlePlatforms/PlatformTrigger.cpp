﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include<Components/PrimitiveComponent.h>
#include"MovingPlatform.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	TriggerVolume = CreateDefaultSubobject < UBoxComponent>(FName("TriggerVolume"));

	if (!ensure(TriggerVolume != nullptr)) return;


	RootComponent = TriggerVolume;

}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::MyCustomOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::MyCustomOverlapEnd);

}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::MyCustomOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	UE_LOG(LogTemp, Display, TEXT("TriggerOn"));



	for (auto platform : PlatformsToTrigger)
	{
		platform->AddActiveTrigger();
	}



}

void APlatformTrigger::MyCustomOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Display, TEXT("TriggerOff"));

	for (auto platform : PlatformsToTrigger)
	{
		platform->RemoveActiveTrigger();
	}
}



