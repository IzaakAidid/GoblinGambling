// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/Userwidget.h"
#include "CasinoDealerMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GOBLINGAME_API UCasinoDealerMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	//UCasinoDealerMenuWidget();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References, meta = (AllowPrivateAccess = "true"))
	class ACasinoDealer* pOwningDealer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	class UGoblinWalletComponent* pPlayerWallet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References, meta = (AllowPrivateAccess = "true"))
	APlayerController* pPlayerController;

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

private:

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
