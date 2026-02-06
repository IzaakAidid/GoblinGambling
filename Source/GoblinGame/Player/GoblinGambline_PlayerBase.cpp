// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinGambline_PlayerBase.h"

/*Stuff for character class*/
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Currency/GoblinWalletComponent.h"
#include "../Currency/StreetBeggingComponent.h"
#include "GameFramework/PlayerState.h"

/*stuff for general use*/
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

/*stuff for inputs*/
#include "EnhancedInputComponent.h"
#include "../GeneralGame/InteractableObject.h"
#include "Components/WidgetInteractionComponent.h"

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

    StreetBeggingRadius = CreateDefaultSubobject<USphereComponent>(TEXT("StreetBeggingRadius"));
    StreetBeggingRadius->SetupAttachment(RootComponent);
    StreetBeggingRadius->SetSphereRadius(300.f); //default number autofill set. could probably change inside street begging component later

    StreetBeggingComp = CreateDefaultSubobject<UStreetBeggingComponent>(TEXT("StreetBeggingComp"));
    StreetBeggingComp->InitBeggingComponent(StreetBeggingRadius, PlayerWallet);
	StreetBeggingComp->DeactivateBegging();

	WidgetInteractComp = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteraction"));
	WidgetInteractComp->bShowDebug = true;
	WidgetInteractComp->InteractionSource = EWidgetInteractionSource::World;
	WidgetInteractComp->SetupAttachment(PlayerCamera);
}

// Called when the game starts or when spawned
void AGoblinGambline_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
	WidgetInteractComp->VirtualUserIndex = FMath::Rand();

}

// Called every frame
void AGoblinGambline_PlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoblinGambline_PlayerBase::ForceFirstPerson()
{
	CameraSpringArm->TargetArmLength = m_minZoomOut;
}

void AGoblinGambline_PlayerBase::GoblinMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}

	StreetBeggingComp->DeactivateBegging(); //TODO: Find a way to remove this
}

void AGoblinGambline_PlayerBase::GoblinLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void AGoblinGambline_PlayerBase::GoblinJump()
{
	StreetBeggingComp->DeactivateBegging(); //TODO: Find a way to remove this
	Jump();
}

void AGoblinGambline_PlayerBase::GoblinInteract()
{
	GEngine->AddOnScreenDebugMessage(555, 3.0f, FColor::Green, FString::Printf(TEXT("interact clicked")));

	FHitResult HitResult;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FVector StartLocation = GetActorLocation();

	FVector EndLocation = StartLocation + GetActorForwardVector() * 150;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params))
	{
		if (HitResult.GetActor()->Implements<UInteractableObject>())
		{
            IInteractableObject::Execute_Interact(HitResult.GetActor(), this);
		}
	}
}

void AGoblinGambline_PlayerBase::GoblinZoom(const FInputActionValue& Value)
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

//ideally this is gonna be like a crouch toggle. if the player moves while begging, they stop begging.
void AGoblinGambline_PlayerBase::GoblinBeg()
{
    StreetBeggingComp->ActivateBegging();
}

void AGoblinGambline_PlayerBase::WidgetInteractPressed()
{
	WidgetInteractComp->PressPointerKey(EKeys::LeftMouseButton);
}

void AGoblinGambline_PlayerBase::WidgetInteractReleased()
{
	WidgetInteractComp->ReleasePointerKey(EKeys::LeftMouseButton);
}