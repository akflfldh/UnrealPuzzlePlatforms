// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"


void UMenuWidget::SetIMenuInterface(IMenuInterface* menuInterface)
{
	MenuInterface = menuInterface;

}

void UMenuWidget::SetUp()
{

	this->AddToViewport();

	UWorld* world = GetWorld();
	if (world == nullptr) return;

	APlayerController* playerController = world->GetFirstPlayerController();

	if (!ensure(playerController != nullptr)) return;

	this->bIsFocusable = true;

	FInputModeUIOnly inputMode;
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);


	playerController->SetInputMode(inputMode);

	playerController->SetShowMouseCursor(true);

}

void UMenuWidget::TearDown()
{

	this->RemoveFromViewport();

	UWorld* world = GetWorld();
	if (world == nullptr) return;

	APlayerController* playerController = world->GetFirstPlayerController();
	if (playerController == nullptr) return;

	this->bIsFocusable = false;


	FInputModeGameOnly inputMode;

	playerController->SetInputMode(inputMode);
	playerController->SetShowMouseCursor(false);




}