// Fill out your copyright notice in the Description page of Project Settings.


#include "../Player/GoblinController.h"
#include "../Player/GoblinGambline_PlayerBase.h"
#include "../Gambling/PlayerSeat.h"

/*stuff for inputs*/
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AGoblinController::BeginPlay()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GameplayInputContext, 0);
	}

	bEnableClickEvents = true;
}

void AGoblinController::AcknowledgePossession(APawn* aPawn)
{
	Super::AcknowledgePossession(aPawn);

	PlayerGoblin = Cast<AGoblinGambline_PlayerBase>(aPawn);
}

void AGoblinController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

	PlayerGoblin = CastChecked<AGoblinGambline_PlayerBase>(aPawn);
}

void AGoblinController::OnUnPossess()
{
    PlayerGoblin = nullptr;

    Super::OnUnPossess();
}

void AGoblinController::SwapToSeatedInput()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(SeatedInputContext, 0);
		Subsystem->RemoveMappingContext(GameplayInputContext);
	}
}

void AGoblinController::SwapToGoblinInput()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GameplayInputContext, 0);
		Subsystem->RemoveMappingContext(SeatedInputContext);
	}
}

void AGoblinController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Moving, duh
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGoblinController::PlayerMove);
		// Moving, duh
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGoblinController::PlayerLook);

		// LEAP MOFO, duh
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AGoblinController::PlayerJump);

		// try to interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AGoblinController::PlayerInteract);

		// try to interact
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &AGoblinController::PlayerZoom);

		EnhancedInputComponent->BindAction(BegAction, ETriggerEvent::Triggered, this, &AGoblinController::PlayerBeg);

		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Triggered, this, &AGoblinController::SeatExit);

		EnhancedInputComponent->BindAction(WidgetInteractAction, ETriggerEvent::Started, this, &AGoblinController::WidgetInteractPressed);
		EnhancedInputComponent->BindAction(WidgetInteractAction, ETriggerEvent::Completed, this, &AGoblinController::WidgetInteractReleased);
	}
}

void AGoblinController::PlayerMove(const FInputActionValue& Value)
{
	if(PlayerGoblin)
	{
		PlayerGoblin->GoblinMove(Value);
	}
}

void AGoblinController::PlayerLook(const FInputActionValue& Value)
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinLook(Value);
	}
}

void AGoblinController::PlayerJump()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinJump();
	}
}

void AGoblinController::PlayerInteract()
{
	Server_PlayerInteract();

	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinInteract();
	}
}

void AGoblinController::PlayerZoom(const FInputActionValue& Value)
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinZoom(Value);
	}

	Server_PlayerZoom(Value);
}

void AGoblinController::PlayerBeg()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinBeg();
	}
}

void AGoblinController::SeatExit()
{
	Server_SeatExit();

	if (PlayerSeat)
	{
        PlayerSeat->EmptySeat();
		SwapToGoblinInput();
		PlayerSeat = nullptr;
	}
}

void AGoblinController::WidgetInteractPressed()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->WidgetInteractPressed();
	}
}

void AGoblinController::WidgetInteractReleased()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->WidgetInteractReleased();
	}
}

void AGoblinController::Server_PlayerMove_Implementation(const FInputActionValue& Value)
{
}

void AGoblinController::Server_PlayerLook_Implementation(const FInputActionValue& Value)
{
}

void AGoblinController::Server_PlayerJump_Implementation()
{
}

void AGoblinController::Server_PlayerInteract_Implementation()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinInteract();
	}
}

void AGoblinController::Server_PlayerZoom_Implementation(const FInputActionValue& Value)
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinZoom(Value);
	}
}

void AGoblinController::Server_PlayerBeg_Implementation()
{
}

void AGoblinController::Server_SeatExit_Implementation()
{
	if (PlayerSeat)
	{
		PlayerSeat->EmptySeat();
		SwapToGoblinInput();
		PlayerSeat = nullptr;
	}
}
