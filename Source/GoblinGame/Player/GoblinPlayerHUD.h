// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GoblinPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class GOBLINGAME_API AGoblinPlayerHUD : public AHUD
{
	GENERATED_BODY()

	
public:
	// Sets default values for this character's properties
	AGoblinPlayerHUD();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerUI, meta = (AllowPrivateAccess = "true"))
	class UUserWidget* pGameUI;
};
