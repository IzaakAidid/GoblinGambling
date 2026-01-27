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

	UFUNCTION(BlueprintCallable)
	void TogglePause();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerUI, meta = (AllowPrivateAccess = "true"))
	class UCustomGoblinGameUserWidget* pGameUI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerUI, meta = (AllowPrivateAccess = "true"))
	class UCustomGoblinGameUserWidget* pPauseScreen; //TODO: write custom widget class for PauseScreens and probably revise the custom game widget class I made so It is less specific and more general

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerData, meta = (AllowPrivateAccess = "true"))
	//class AGoblinGambline_PlayerBase* pOwningPlayer;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerData, meta = (AllowPrivateAccess = "true"))
	//int NumOfGoblinBucks;
	//
	//UFUNCTION(BlueprintCallable)
	//int GetGoblinBucksForUI();
	//
	//UFUNCTION(BlueprintCallable)
	//int GetGoblinChipsCasino1ForUI();
	//
	//UFUNCTION(BlueprintCallable)
	//int GetGoblinChipsCasino2ForUI();
	//
	//UFUNCTION(BlueprintCallable)
	//int GetGoblinChipsCasino3ForUI();

};
