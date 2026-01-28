// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GoblinController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class AGoblinGambline_PlayerBase;

/**
 * 
 */
UCLASS()
class GOBLINGAME_API AGoblinController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void AcknowledgePossession(APawn* aPawn) override;

	virtual void OnPossess(APawn* aPawn) override;

	virtual void OnUnPossess() override;

public:

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	void PlayerMove(const FInputActionValue& Value);
	void PlayerLook(const FInputActionValue& Value);
	void PlayerJump();
	void PlayerInteract();
	void PlayerZoom(const FInputActionValue& Value);
	void PlayerBeg();
	
protected:

    UFUNCTION(Server, Reliable)
	void Server_PlayerMove(const FInputActionValue& Value);
	UFUNCTION(Server, Reliable)
	void Server_PlayerLook(const FInputActionValue& Value);
	UFUNCTION(Server, Reliable)
	void Server_PlayerJump();
	UFUNCTION(Server, Reliable)
	void Server_PlayerInteract();
	UFUNCTION(Server, Reliable)
	void Server_PlayerZoom(const FInputActionValue& Value);
	UFUNCTION(Server, Reliable)
	void Server_PlayerBeg();

	AGoblinGambline_PlayerBase* PlayerGoblin;

	/** Mapping Context */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* GameplayInputContext;

	/** Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ZoomAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BegAction;
};
