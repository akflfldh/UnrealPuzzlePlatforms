// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameToBackMenu.generated.h"


class IToBackMenuInterface;
/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameToBackMenu : public UMenuWidget
{
	GENERATED_BODY()


public:
	virtual bool Initialize() override;

protected:

	UFUNCTION()
	void Cacnel();

	UFUNCTION()
	void ToMenu();



private:

	//button 2개 

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;


	UPROPERTY(meta = (BindWidget))
	class UButton* ToMenuButton;







};
