// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GoblingGambling_MinigameBase.h"
#include "GoblingGambling_SlotMachine.generated.h"

/**
 *
 */
UCLASS()
class GOBLINGAME_API AGoblingGambling_SlotMachine : public AGoblingGambling_MinigameBase
{
	GENERATED_BODY()

public:
	AGoblingGambling_SlotMachine();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void PlayerEnteredPlayArea() override;

	//Player leaves minigame and gets payed
	virtual void LeaveMinigame() override;

	//check if player's wallet is fat enough to join
	virtual bool CheckBuyIn() override;

	//give player winnings 
	virtual void PayOutPlayer() override;


	//custom code per machine, the actual game
	virtual void PlayMinigame() override;
};
