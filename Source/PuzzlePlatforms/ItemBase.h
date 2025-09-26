// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class PUZZLEPLATFORMS_API AItemBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;;

	UFUNCTION()
	virtual void  OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	virtual void AquireItem(AActor* OtherActor);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshCom;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;


	UPROPERTY(EditAnywhere)
	float RotateSpeed = 40.0f;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* AquireEffect;


	UPROPERTY(EditAnywhere)
	class USoundBase* AquireSound;

	class UNiagaraComponent* AquireEffectCom;


protected:
	UPROPERTY(EditAnywhere)
	float DurationTime = 3.0f;

};
