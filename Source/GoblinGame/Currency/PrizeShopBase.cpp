// Fill out your copyright notice in the Description page of Project Settings.


#include "PrizeShopBase.h"
#include "PrizeBaseComponent.h"

// Sets default values
APrizeShopBase::APrizeShopBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrizeShopWallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrizeShopWallMesh"));
	PrizeShopWallMesh->SetupAttachment(RootComponent);

	PrizeShopAttendantMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PrizeShopAttendantMesh"));
	PrizeShopAttendantMesh->SetupAttachment(PrizeShopWallMesh);

	//Default value
	CasinoChipsType = ECasinoChipsType::CASINO1;

	

}

// Called when the game starts or when spawned
void APrizeShopBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APrizeShopBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APrizeShopBase::Interact_Implementation(AGoblinGambline_PlayerBase* Player)
{
}

