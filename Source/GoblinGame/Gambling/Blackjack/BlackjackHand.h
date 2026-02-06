// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gambling/PlayerHand.h"
#include "BlackjackHand.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class GOBLINGAME_API ABlackjackHand : public APlayerHand
{
	GENERATED_BODY()

    ABlackjackHand();
	
public:

	virtual void SetActivePlayerWallet(AActor* playerActor) override;
	virtual void ClearActivePlayerWallet() override;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_PlaceBet(int value);

protected:

	UFUNCTION(Client, Reliable)
	void Client_ShowBetPlacer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UWidgetComponent* BetPlacerComponent;
};
