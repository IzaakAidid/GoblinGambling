// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../ObjectPooling/ObjectPooledActor.h"
#include "StreetNPC_Base.generated.h"

/*
* TODO:
* - Hook up to a behavior tree (very simple: walk to despawn point, if in range of player do a chance to donate then go back to walking to despawn point)
*/

class UGoblinWalletComponent;
class AStreetNPC_Controller;

UCLASS(Blueprintable)
class GOBLINGAME_API AStreetNPC_Base : public ACharacter, public IObjectPooledActor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStreetNPC_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Begging")
	int AmountToGive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Begging")
    float ChanceToGive;

	AStreetNPC_Controller* NPCController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetBeggedAt(UGoblinWalletComponent* playerWallet);

	void SetDespawnPoint(FVector location);

    // IObjectPooledActor interface
    virtual void ActivateFromPool() override;

    virtual void ReturnToPool() override;
};
