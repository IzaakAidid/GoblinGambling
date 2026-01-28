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

	int m_maxZoomOut;
	int m_minZoomOut;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GoblinMove(const FInputActionValue& Value);
	void GoblinLook(const FInputActionValue& Value);
	void GoblinJump();
	void GoblinInteract();
	void GoblinZoom(const FInputActionValue& Value);
    void GoblinBeg();

	APlayerController* GetPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Wallet, meta = (AllowPrivateAccess = "true"))
	class UGoblinWalletComponent* PlayerWallet;

};
