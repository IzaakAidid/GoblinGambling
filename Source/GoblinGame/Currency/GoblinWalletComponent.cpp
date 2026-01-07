// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinWalletComponent.h"

// Sets default values for this component's properties
UGoblinWalletComponent::UGoblinWalletComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGoblinWalletComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGoblinWalletComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGoblinWalletComponent::SetupGoblinWallet(int StartingGoblinBucks)
{
	SetHeldGoblinBucks(StartingGoblinBucks);
}

int UGoblinWalletComponent::GetHeldGoblinChips(ECasinoChipsType typeOfChip)
{
	int currencyToReturn = 0;
	if (typeOfChip == ECasinoChipsType::CASINO1)
	{
		currencyToReturn = m_HeldGoblinChips_C1;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO2)
	{
		currencyToReturn = m_HeldGoblinChips_C2;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO3)
	{
		currencyToReturn = m_HeldGoblinChips_C3;
	}
	return currencyToReturn;
}

void UGoblinWalletComponent::SetHeldGoblinChips(int NewGoblinChips, ECasinoChipsType typeOfChip)
{
	if (typeOfChip == ECasinoChipsType::CASINO1)
	{
		m_HeldGoblinChips_C1 = NewGoblinChips;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO2)
	{
		m_HeldGoblinChips_C2 = NewGoblinChips;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO3)
	{
		 m_HeldGoblinChips_C3 = NewGoblinChips;
	}
}

void UGoblinWalletComponent::AddGoblinChips(int NewGoblinChips, ECasinoChipsType typeOfChip)
{
	if (typeOfChip == ECasinoChipsType::CASINO1)
	{
		m_HeldGoblinChips_C1 += NewGoblinChips;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO2)
	{
		m_HeldGoblinChips_C2 += NewGoblinChips;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO3)
	{
		m_HeldGoblinChips_C3 += NewGoblinChips;
	}
}

void UGoblinWalletComponent::RemoveGoblinChips(int GoblinChipsToRemove, ECasinoChipsType typeOfChip)
{
	if (typeOfChip == ECasinoChipsType::CASINO1)
	{
		m_HeldGoblinChips_C1 -= GoblinChipsToRemove;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO2)
	{
		m_HeldGoblinChips_C2 -= GoblinChipsToRemove;
	}
	else if (typeOfChip == ECasinoChipsType::CASINO3)
	{
		m_HeldGoblinChips_C3 -= GoblinChipsToRemove;
	}
}
