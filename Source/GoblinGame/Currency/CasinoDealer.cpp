// Fill out your copyright notice in the Description page of Project Settings.


#include "CasinoDealer.h"
#include "GoblinWalletComponent.h"
#include "Components/BoxComponent.h"
#include "../GeneralGame/GoblinGamblingEnums.h"

// Sets default values
ACasinoDealer::ACasinoDealer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractionCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DealerInteractionCollisionBox"));
	DealerWallet = CreateDefaultSubobject<UGoblinWalletComponent>(TEXT("DealerWallet"));

	TEMP_DealerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PROTOTYPE_DealerMesh"));
	DealerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DealerSkeletalMesh"));

	SetRootComponent(DealerMesh);
	TEMP_DealerMesh->SetupAttachment(RootComponent);
	InteractionCollisionBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACasinoDealer::BeginPlay()
{
	Super::BeginPlay();
	InteractionCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACasinoDealer::OnOverlapBegin);
	InteractionCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ACasinoDealer::OnOverlapEnd);
}

// Called every frame
void ACasinoDealer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACasinoDealer::ConvertBucksToChips(int BucksToConvert)
{
}

void ACasinoDealer::ConvertChipsToBucks(int BucksToConvert)
{
}

void ACasinoDealer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//player is close enough to interact
	int x = 2; //debug
}

void ACasinoDealer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//player has left the interaction zone
	int x = 2; //debug
}

