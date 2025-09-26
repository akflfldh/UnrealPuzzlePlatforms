// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpItem.h"
#include<GameFramework/Character.h>
#include<GameFramework/CharacterMovementComponent.h>
#include "TimerManager.h"
void AJumpItem::BeginPlay()
{
	Super::BeginPlay();




}


void AJumpItem::AquireItem(AActor* OtherActor)
{

	if (HasAuthority())
	{
		AItemBase::AquireItem(OtherActor);

		ACharacter* player = Cast<ACharacter>(OtherActor);

		if (player == nullptr)
			return;

		float orignalJump = player->GetCharacterMovement()->JumpZVelocity;
		player->GetCharacterMovement()->JumpZVelocity *= JumpUpRate;

		FTimerHandle timer;
		FTimerDelegate timerDelegate;
		timerDelegate.BindLambda([player, orignalJump]() {

			player->GetCharacterMovement()->JumpZVelocity = orignalJump;
			});

		GetWorld()->GetTimerManager().SetTimer(timer, timerDelegate, DurationTime, false);
		Destroy();

	}




}

void AJumpItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
