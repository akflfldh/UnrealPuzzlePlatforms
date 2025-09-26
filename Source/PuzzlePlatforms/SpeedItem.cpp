// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedItem.h"
#include<GameFramework/Character.h>
#include<GameFramework/CharacterMovementComponent.h>
ASpeedItem::ASpeedItem()
{




}

void ASpeedItem::BeginPlay()
{
	Super::BeginPlay();
}



void ASpeedItem::AquireItem(AActor* OtherActor)
{
	if (HasAuthority())
	{
		AItemBase::AquireItem(OtherActor);

		ACharacter* player = Cast<ACharacter>(OtherActor);

		if (player == nullptr)
			return;

		float originalMaxWalkSpeed = player->GetCharacterMovement()->MaxWalkSpeed;
		player->GetCharacterMovement()->MaxWalkSpeed *= SpeedUpRate;

		FTimerHandle timerHandle;
		FTimerDelegate timerDelegate;
		timerDelegate.BindLambda([player, originalMaxWalkSpeed]() {

			player->GetCharacterMovement()->MaxWalkSpeed = originalMaxWalkSpeed;
			});

		GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, DurationTime, false);
		Destroy();

	}
}

void ASpeedItem::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}
