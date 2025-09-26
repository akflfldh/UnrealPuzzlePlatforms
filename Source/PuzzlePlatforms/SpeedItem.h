// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "SpeedItem.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API ASpeedItem : public AItemBase
{
	GENERATED_BODY()

public:
	ASpeedItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




	virtual void AquireItem(AActor* OtherActor) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere)
	float SpeedUpRate = 1.5f;



};
