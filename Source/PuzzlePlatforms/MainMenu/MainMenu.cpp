// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include"MenuInterface.h"
#include<Components/EditableTextBox.h>



bool UMainMenu::Initialize()
{

	bool ret = Super::Initialize();

	if (!ret) return false;

	if (HostButton == nullptr) return false;
	if (JoinButton == nullptr) return false;

	HostButton->OnClicked.AddDynamic(this, &UMainMenu::Hosting);

	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	JoinCancelButton->OnClicked.AddDynamic(this, &UMainMenu::CancelJoinMenu);

	JoinGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);

	return true;
}


void UMainMenu::Hosting()
{

	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
	UE_LOG(LogTemp, Warning, TEXT("Host button Clicked"));

}
void UMainMenu::OpenJoinMenu()
{

	if (MenuSwitcher == nullptr)return;

	if (JoinGame == nullptr)return;

	MenuSwitcher->SetActiveWidget(JoinGame);


}

void UMainMenu::JoinServer()
{
	//	UE_LOG(LogTemp, Warning, TEXT("Join button Clicked"));

	if (MenuInterface != nullptr)
	{

		if (IPAddressTextBox == nullptr) return;


		const FString& ipAddress = IPAddressTextBox->GetText().ToString();

		MenuInterface->Join(ipAddress);

	}
}
void UMainMenu::QuitGame()
{

	if (MenuInterface != nullptr)
	{
		MenuInterface->QuitGame();

	}


	//UWorld* world = GetWorld();
	//if (world == nullptr) return;

	//APlayerController* PlayerController = world->GetFirstPlayerController();

	//if (PlayerController == nullptr) return;

	//PlayerController->ConsoleCommand("quit");






}
void UMainMenu::CancelJoinMenu()
{

	if (MenuSwitcher == nullptr) return;

	if (MainMenu == nullptr) return;

	MenuSwitcher->SetActiveWidget(MainMenu);


}
//void UMainMenu::Joining()
//{
//
//
//
//	UE_LOG(LogTemp, Warning, TEXT("Join button Clicked"));
//
//
//
//}