// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayformGameInstance.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UPlayformGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPlayformGameInstance(const FObjectInitializer& ObjectInitializer);

	void Init() override;

	UFUNCTION(Exec)
	void Host();


	UFUNCTION(Exec)
	void Join(const FString& address);
};
