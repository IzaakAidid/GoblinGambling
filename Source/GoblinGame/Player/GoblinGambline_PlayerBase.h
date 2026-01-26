// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GoblinGambline_PlayerBase.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class USpringArmComponent;
class USphereComponent;
class UStreetBeggingComponent;


UCLASS()
class GOBLINGAME_API AGoblinGambline_PlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblinGambline_PlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



#pragma region Player Defaults
	/** Player Camera Spring Arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraSpringArm;

	/** Player Camera  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	//class AGoblinPlayerHUD* PlayerHUD;

	/** Street Begging */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StreetBegging, meta = (AllowPrivateAccess = "true"))
	USphereComponent* StreetBeggingRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StreetBegging, meta = (AllowPrivateAccess = "true"))
	UStreetBeggingComponent* StreetBeggingComp;

#pragma endregion

#pragma region Player Inputs
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

#pragma endregion


	int m_maxZoomOut;
	int m_minZoomOut;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PlayerMove(const FInputActionValue& Value);
	void PlayerLook(const FInputActionValue& Value);
	void PlayerJump();
	void PlayerInteract();
	void PlayerZoom(const FInputActionValue& Value);

        UFUNCTION(Server, Reliable)
        void PlayerBeg();

	APlayerController* GetPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	class UGoblinWalletComponent* PlayerWallet;

};
