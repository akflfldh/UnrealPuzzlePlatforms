// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ToBackMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UToBackMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class PUZZLEPLATFORMS_API IToBackMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//back menu 
	virtual void InGameToMenu() = 0;
	//cancel 
	virtual void InGameCancelToBackMenu() = 0;


};
