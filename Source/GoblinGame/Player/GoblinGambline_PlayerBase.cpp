// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinGambline_PlayerBase.h"

/*Stuff for character class*/
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Currency/GoblinWalletComponent.h"

/*stuff for general use*/
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

/*stuff for inputs*/
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AGoblinGambline_PlayerBase::AGoblinGambline_PlayerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_maxZoomOut = 1000;
	m_minZoomOut = 0;

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->bUsePawnControlRotation = true;
	CameraSpringArm->TargetArmLength = 700;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraSpringArm);
	PlayerCamera->bUsePawnControlRotation = false;

	PlayerWallet = CreateDefaultSubobject<UGoblinWalletComponent>(TEXT("PlayerWallet"));
	PlayerWallet->SetupGoblinWallet(200);

}

// Called when the game starts or when spawned
void AGoblinGambline_PlayerBase::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(GameplayInputContext, 0);
		}
	}
}

// Called every frame
void AGoblinGambline_PlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGoblinGambline_PlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving, duh
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGoblinGambline_PlayerBase::PlayerMove);
		// Moving, duh
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGoblinGambline_PlayerBase::PlayerLook);

		// LEAP MOFO, duh
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AGoblinGambline_PlayerBase::PlayerJump);

		// try to interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AGoblinGambline_PlayerBase::PlayerInteract);

		// try to interact
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &AGoblinGambline_PlayerBase::PlayerZoom);
	}
}

void AGoblinGambline_PlayerBase::PlayerMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AGoblinGambline_PlayerBase::PlayerLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void AGoblinGambline_PlayerBase::PlayerJump()
{
	Jump();
}

void AGoblinGambline_PlayerBase::PlayerInteract()
{

}

void AGoblinGambline_PlayerBase::PlayerZoom(const FInputActionValue& Value)
{
	float zoomDirection = Value.Get<float>();

	if (zoomDirection == -1)
	{
		CameraSpringArm->TargetArmLength += 100;;
		if (CameraSpringArm->TargetArmLength > m_maxZoomOut)
		{
			CameraSpringArm->TargetArmLength = m_maxZoomOut;
		}
	}
	else
	{
		CameraSpringArm->TargetArmLength -= 100;
		if (CameraSpringArm->TargetArmLength < m_minZoomOut)
		{
			CameraSpringArm->TargetArmLength = m_minZoomOut;
		}
	}
}


APlayerController* AGoblinGambline_PlayerBase::GetPlayerController()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		return PlayerController;
	}
	return nullptr;
}
