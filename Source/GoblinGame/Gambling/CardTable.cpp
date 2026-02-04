// Fill out your copyright notice in the Description page of Project Settings.


#include "CardTable.h"
#include "PlayerSeat.h"
#include "DeckOfCards.h"
#include "Components/ArrowComponent.h"

// Sets default values
ACardTable::ACardTable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ACardTable::BeginPlay()
{
	Super::BeginPlay();

	DeckOfCards = NewObject<UDeckOfCards>(this, DeckBP);
	
	DeckOfCards->ShuffleDeck();
}
