// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoblinWalletComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOBLINGAME_API UGoblinWalletComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoblinWalletComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupGoblinWallet(int StartingGoblinBucks);

#pragma region Helper Functions
	//Goblin Buck Functions

	const int GetHeldGoblinBucks() { return m_HeldGoblinBucks; };
	void SetHeldGoblinBucks(int NewGoblinBucks) { m_HeldGoblinBucks = NewGoblinBucks; };
	void AddGoblinBucks(int NewGoblinBucks) { m_HeldGoblinBucks += NewGoblinBucks; };
	void RemoveGoblinBucks(int GoblinBucksToRemove) { m_HeldGoblinBucks -= GoblinBucksToRemove; };

	//Goblin Chip Functions

	const int GetHeldGoblinChips() { return m_HeldGoblinChips; };
	void SetHeldGoblinChips(int NewGoblinChips) { m_HeldGoblinChips = NewGoblinChips; };
	void AddGoblinChips(int NewGoblinChips) { m_HeldGoblinChips += NewGoblinChips; };
	void RemoveGoblinChips(int GoblinChipsToRemove) { m_HeldGoblinChips -= GoblinChipsToRemove; };
#pragma endregion

#pragma region Member Variables
private:
	int m_HeldGoblinBucks;
	int m_HeldGoblinChips;

#pragma endregion
};
