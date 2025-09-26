// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameToBackMenu.h"
#include<Components/Button.h>
#include"MenuInterface.h"

bool UInGameToBackMenu::Initialize()
{

	bool ret = Super::Initialize();

	if (!ret) return false;


	if (CancelButton == nullptr)return false;
	if (ToMenuButton == nullptr) return false;



	CancelButton->OnClicked.AddDynamic(this, &UInGameToBackMenu::Cacnel);
	ToMenuButton->OnClicked.AddDynamic(this, &UInGameToBackMenu::ToMenu);


	return true;
}


void UInGameToBackMenu::Cacnel()
{

	if (MenuInterface != nullptr)
	{
		MenuInterface->CancelInGameMenu();
	}

}

void UInGameToBackMenu::ToMenu()
{
	if (MenuInterface != nullptr)
	{

		TearDown();
		MenuInterface->ToMainMenu();
	}

}
