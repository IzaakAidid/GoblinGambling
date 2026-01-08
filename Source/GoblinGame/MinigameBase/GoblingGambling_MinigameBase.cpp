// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblingGambling_MinigameBase.h"
#include "Components/BoxComponent.h"
#include "../Player/GoblinGambline_PlayerBase.h"



// Sets default values
AGoblingGambling_MinigameBase::AGoblingGambling_MinigameBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_MinigameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineMesh"));
	SetRootComponent(m_MinigameMesh);

	m_PlayAreaHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayAreaHitBox"));
	m_PlayAreaHitBox->SetupAttachment(RootComponent);
	m_PlayAreaHitBox->SetBoxExtent(FVector(100, 10, 100));

}

// Called when the game starts or when spawned
void AGoblingGambling_MinigameBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGoblingGambling_MinigameBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoblingGambling_MinigameBase::PlayMinigame()
{
	//Make A Default Placehold Minigame

}

void AGoblingGambling_MinigameBase::PlayerEnteredPlayArea()
{

}

void AGoblingGambling_MinigameBase::LeaveMinigame()
{

}

bool AGoblingGambling_MinigameBase::CheckBuyIn()
{
	//check if the players money is high enough for buy in

	return false;
}

void AGoblingGambling_MinigameBase::PayOutPlayer()
{

}

