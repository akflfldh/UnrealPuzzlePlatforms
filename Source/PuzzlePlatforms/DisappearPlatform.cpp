// Fill out your copyright notice in the Description page of Project Settings.


#include "DisappearPlatform.h"
#include "Components/BoxComponent.h"
// Sets default values
ADisappearPlatform::ADisappearPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	StaticMeshCom = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshCom"));

	BoxCom = CreateDefaultSubobject<UBoxComponent>(FName("BoxTriggerCom"));

	RootComponent = BoxCom;
	StaticMeshCom->SetupAttachment(BoxCom);

	BoxCom->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	BoxCom->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	BoxCom->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);


}

// Called when the game starts or when spawned
void ADisappearPlatform::BeginPlay()
{
	Super::BeginPlay();

	BoxCom->OnComponentBeginOverlap.AddDynamic(this, &ADisappearPlatform::OnOverlapBegin);



}

void  ADisappearPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//오버랩되면 time 후 에 이 pawn 파괴 


	if (HasAuthority())
	{
		FTimerHandle timerHandle;

		FTimerDelegate timerDelegate;
		timerDelegate.BindLambda([platform = this]() {

			platform->Destroy();
			});

		GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, Duration, false);
	}

}



// Called every frame
void ADisappearPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

