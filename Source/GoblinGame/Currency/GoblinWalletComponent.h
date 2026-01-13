// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../GeneralGame/GoblinGamblingEnums.h"
#include "GoblinWalletComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

	int GetHeldGoblinChips(ECasinoChipsType typeOfChip);
	void SetHeldGoblinChips(int NewGoblinChips, ECasinoChipsType typeOfChip);
	void AddGoblinChips(int NewGoblinChips, ECasinoChipsType typeOfChip);
	void RemoveGoblinChips(int GoblinChipsToRemove, ECasinoChipsType typeOfChip);
#pragma endregion

#pragma region Member Variables
private:
	//Goblin Bucks
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	int m_HeldGoblinBucks;

	//Goblin Chips | C1 = Casino 1, etc
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	int m_HeldGoblinChips_C1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	int m_HeldGoblinChips_C2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	int m_HeldGoblinChips_C3;


#pragma endregion
};


//class GOBLINGAME_API GoblinChips
//{
//public:
//	GoblinChips();
//	~GoblinChips();
//
//	UPROPERTY(BlueprintReadWrite, Replicated)
//	ECasinoChipsType TypeOfChip;
//
//	UPROPERTY(BlueprintReadWrite, Replicated)
//	ECasinoChipValue ValueOfChip;
//};