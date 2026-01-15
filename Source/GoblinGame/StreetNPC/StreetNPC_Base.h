// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StreetNPC_Base.generated.h"

class UGoblinWalletComponent;

UCLASS(Blueprintable)
class GOBLINGAME_API AStreetNPC_Base : public ACharacter
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetBeggedAt(UGoblinWalletComponent* playerWallet);
};
