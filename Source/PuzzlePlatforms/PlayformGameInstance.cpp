// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayformGameInstance.h"
#include"PlatformTrigger.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include"MainMenu/MainMenu.h"
#include"MainMenu/InGameToBackMenu.h"
#include"MainMenu/MenuWidget.h"
UPlayformGameInstance::UPlayformGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));

	if (MainMenuWBPClass.Class == nullptr) return;

	MainMenuClass = MainMenuWBPClass.Class;



	ConstructorHelpers::FClassFinder<UUserWidget> InGameToBackMenuWBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));

	if (InGameToBackMenuWBPClass.Class == nullptr) return;
	InGameToBackMenuClass = InGameToBackMenuWBPClass.Class;



	//에디터 실행시에도, 플레이일때도 호출
	//UE_LOG(LogTemp, Warning, TEXT("Found class : %s"), *MainMenuWBPClass.Class->GetName());
}


void UPlayformGameInstance::Init()
{

	//오직 플레이할때만 호출됨

	//에디터 실행시에도, 플레이일때도 호출
	UE_LOG(LogTemp, Warning, TEXT("Found class : %s"), *MainMenuClass->GetName());
}
void UPlayformGameInstance::LoadMenu()
{


	if (MainMenuClass == nullptr) return;


	//if (MainMenu == nullptr)
	MainMenu = CreateWidget<UMainMenu>(this, MainMenuClass);


	if (MainMenu == nullptr) return;


	MainMenu->SetUp();
	MainMenu->SetIMenuInterface(this);







}



void UPlayformGameInstance::LoadInGameMenu()
{
	if (InGameToBackMenuClass == nullptr) return;


	//if (InGameToBackMenu == nullptr)
	InGameToBackMenu = CreateWidget<UInGameToBackMenu>(this, InGameToBackMenuClass);


	if (InGameToBackMenu == nullptr) return;


	InGameToBackMenu->SetUp();

	InGameToBackMenu->SetIMenuInterface(this);



}

void UPlayformGameInstance::Host()
{
	if (MainMenu != nullptr)
	{
		MainMenu->TearDown();
	}


	if (!ensure(GEngine != nullptr)) return;

	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Green, TEXT("hosting"));


	UWorld* world = GetWorld();
	if (!ensure(world != nullptr)) return;



	world->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");

}



void UPlayformGameInstance::Join(const FString& address)
{

	if (MainMenu != nullptr)
	{
		MainMenu->TearDown();
	}

	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Green, FString::Printf(TEXT("Joining : %s"), *address));



	APlayerController* playerController = GetFirstLocalPlayerController();

	if (!ensure(playerController != nullptr)) return;

	playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);



}

void UPlayformGameInstance::ToMainMenu()
{
	//MainMenu로 이동

	APlayerController* playerController = GetFirstLocalPlayerController();

	if (!ensure(playerController != nullptr)) return;

	playerController->ClientTravel("/Game/MainMenu/MainMenu", ETravelType::TRAVEL_Absolute);
	//main Menu레벨로

}



void UPlayformGameInstance::CancelInGameMenu()
{
	//UE_LOG(LogTemp, Warning, TEXT("aSD"));

	if (InGameToBackMenu != nullptr)
	{
		InGameToBackMenu->TearDown();
	}





}

void UPlayformGameInstance::QuitGame()
{


	APlayerController* playerController = GetFirstLocalPlayerController();

	if (!ensure(playerController != nullptr)) return;

	playerController->ConsoleCommand("quit");

}



