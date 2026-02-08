// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerHand.generated.h"

class UGoblinWalletComponent;
class UWidgetComponent;

DECLARE_DELEGATE(FOnBetPlaced);

UCLASS()
class GOBLINGAME_API APlayerHand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerHand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated) 
	UGoblinWalletComponent* WalletComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetComponent* BetPlacerComponent;

public:	

	UFUNCTION(Client, Reliable)
	virtual void Client_ShowBetPlacer();

	UFUNCTION(Client, Reliable)
	virtual void Client_HideBetPlacer();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	virtual void Server_PlaceBet(int value);

    virtual void SetActivePlayerWallet(AActor* playerActor);

	virtual void ClearActivePlayerWallet();

	bool IsHandActive() { if (WalletComponent) return true; else return false; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCanBet = true;

	FOnBetPlaced MyBetPlacedDelegate;
};
