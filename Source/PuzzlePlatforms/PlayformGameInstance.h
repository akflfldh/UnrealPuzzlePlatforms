// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include"MainMenu/MenuInterface.h"
#include"MainMenu/ToBackMenuInterface.h"
#include "PlayformGameInstance.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UPlayformGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
public:
	UPlayformGameInstance(const FObjectInitializer& ObjectInitializer);

	void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();


	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(Exec)
	virtual void Host() override;

	void Join(const FString& address) override;



	virtual void ToMainMenu() override;
	virtual void CancelInGameMenu() override;

	virtual void QuitGame() override;


private:




private:
	TSubclassOf <class UUserWidget> MainMenuClass;
	TSubclassOf<class UUserWidget> InGameToBackMenuClass;

	class UMainMenu* MainMenu;
	class UInGameToBackMenu* InGameToBackMenu;
}


;
