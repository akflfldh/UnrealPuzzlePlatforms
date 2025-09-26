// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include<Components/SphereComponent.h>
#include<GameFramework/Character.h>
#include <NiagaraFunctionLibrary.h>
#include <NiagaraSystem.h>
#include<Kismet/GameplayStatics.h>
#include <Engine/TimerHandle.h>
#include <TimerManager.h>
#include "NiagaraComponent.h"
// Sets default values
AItemBase::AItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshCom = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshCom"));

	SphereComponent = CreateDefaultSubobject<USphereComponent>(FName("SphereCom"));


	RootComponent = SphereComponent;

	StaticMeshCom->SetupAttachment(SphereComponent);

	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore); //일단 모든채널에대해서 충돌을 끊다. - 초기화 

	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // 플레이어만 감



}




// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);

	}




}

void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (HasAuthority())
	{

		AquireItem(OtherActor);


	}




}

void AItemBase::AquireItem(AActor* OtherActor)
{


	ACharacter* character = Cast<ACharacter>(OtherActor);

	if (character == nullptr)
		return;

	USceneComponent* rootCom = character->GetRootComponent();


	if (AquireEffect)
	{
		UNiagaraComponent* effectCom = UNiagaraFunctionLibrary::SpawnSystemAttached(AquireEffect, rootCom, NAME_None, { 0,0,0 }, { 0,0,0 }, EAttachLocation::KeepRelativeOffset, false);

		FTimerHandle timerHandle;
		FTimerDelegate timerDelegate;
		timerDelegate.BindLambda([effectCom]() {

			effectCom->DestroyComponent();
			});
		GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, DurationTime, false);



	}


	if (AquireSound != nullptr)
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), AquireSound, OtherActor->GetActorLocation());







}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//회전하자. 
	if (HasAuthority())
	{

		if (StaticMeshCom != nullptr)
		{

			StaticMeshCom->AddLocalRotation(FRotator{ 0,RotateSpeed * DeltaTime,0 });


		}

	}
}

