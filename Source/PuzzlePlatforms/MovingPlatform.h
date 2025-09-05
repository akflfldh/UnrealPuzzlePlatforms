// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()




public:
	AMovingPlatform();



	virtual void Tick(float DeltaSeconds) override;
	void AddActiveTrigger();
	void RemoveActiveTrigger();
protected:
	virtual void BeginPlay() override;

private:


	UPROPERTY(EditAnywhere)
	float Speed = 5;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;





	bool ActiveState();

private:


	FVector StartLocationWorld;
	FVector TargetLocationWorld;




	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 0;


	UPROPERTY(EditAnywhere)
	int ActiveTriggersCondition = 0;

};
