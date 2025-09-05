// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayformGameInstance.h"

UPlayformGameInstance::UPlayformGameInstance(const FObjectInitializer& ObjectInitializer)
{

	//에디터 실행시에도, 플레이일때도 호출
	UE_LOG(LogTemp, Warning, TEXT("생성자"));
}


void UPlayformGameInstance::Init()
{

	//오직 플레이할때만 호출됨
	UE_LOG(LogTemp, Warning, TEXT("Init"));
}

void UPlayformGameInstance::Host()
{


	if (!ensure(GEngine != nullptr)) return;

	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Green, TEXT("hosting"));


	UWorld* world = GetWorld();
	if (!ensure(world != nullptr)) return;



	world->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");

}



void UPlayformGameInstance::Join(const FString& address)
{


	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Green, FString::Printf(TEXT("Joining : %s"), *address));



	APlayerController* playerController = GetFirstLocalPlayerController();

	if (!ensure(playerController != nullptr)) return;

	playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);


}
