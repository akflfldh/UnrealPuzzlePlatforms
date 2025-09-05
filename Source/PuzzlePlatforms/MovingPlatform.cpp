// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);

		SetReplicateMovement(true);

		StartLocationWorld = GetActorLocation();

		TargetLocationWorld = GetRootComponent()->GetComponentTransform().TransformPosition(TargetLocation);




	}

}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;

}

void AMovingPlatform::RemoveActiveTrigger()
{
	ActiveTriggers--;


}

bool AMovingPlatform::ActiveState()
{
	return ActiveTriggers >= ActiveTriggersCondition;
}


void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	if (HasAuthority())
	{

		if (ActiveState())
		{
			FVector DirectionToTargetWorld = TargetLocationWorld - StartLocationWorld;
			FVector DirectionToTargetWorldNormal = DirectionToTargetWorld.GetSafeNormal();

			SetActorLocation(GetActorLocation() + DirectionToTargetWorldNormal * Speed * DeltaSeconds);

			float toActorLength = (GetActorLocation() - StartLocationWorld).Length();
			float toTargetLength = DirectionToTargetWorld.Length();

			if (toActorLength > toTargetLength)
			{
				Swap(TargetLocationWorld, StartLocationWorld);
				SetActorLocation(StartLocationWorld);
			}

		}



	}







}

