// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerHand.generated.h"

class UGoblinWalletComponent;

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

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite) 
	UGoblinWalletComponent* WalletComponent;

public:	

    virtual void SetActivePlayerWallet(AActor* playerActor);

	virtual void ClearActivePlayerWallet() { WalletComponent = nullptr; }
};
