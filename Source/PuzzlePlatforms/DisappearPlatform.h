// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisappearPlatform.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API ADisappearPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADisappearPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void  OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMeshCom;


	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCom;


	UPROPERTY(EditAnywhere)
	float Duration = 5.0f;

};
