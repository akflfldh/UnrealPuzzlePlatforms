// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

protected:
	virtual bool Initialize() override;

	UFUNCTION()
	void Hosting();

	UFUNCTION()		//동적으로 바인딩할려면 이 매크로를 명시해야하는것을 잊지말자.
		void OpenJoinMenu();


	UFUNCTION()
	void CancelJoinMenu();

	UFUNCTION()
	void JoinServer();


	UFUNCTION()
	void QuitGame();

private:

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinCancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinGameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;


	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinGame;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;


	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextBox;



};
