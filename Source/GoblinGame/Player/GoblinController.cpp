// Fill out your copyright notice in the Description page of Project Settings.


#include "../Player/GoblinController.h"
#include "../Player/GoblinGambline_PlayerBase.h"

/*stuff for inputs*/
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AGoblinController::BeginPlay()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GameplayInputContext, 0);
	}
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

void AGoblinController::SwapToTableInput()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(CardTableInputContext, 0);
		Subsystem->RemoveMappingContext(GameplayInputContext);
	}
}

void AGoblinController::SwapToGoblinInput()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(GameplayInputContext, 0);
		Subsystem->RemoveMappingContext(CardTableInputContext);
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

		EnhancedInputComponent->BindAction(ExitAction, ETriggerEvent::Triggered, this, &AGoblinController::TableExit);

		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AGoblinController::PlayerStartSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AGoblinController::PlayerEndSprint);
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
}

void AGoblinController::PlayerBeg()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinBeg();
	}
}

void AGoblinController::PlayerStartSprint()
{
	Server_PlayerSprint();
	//if (PlayerGoblin)
	//{
	//	PlayerGoblin->GoblinStartSprint();
	//}
}

void AGoblinController::PlayerEndSprint()
{
	Server_PlayerEndSprint();
	//if (PlayerGoblin)
	//{
	//	PlayerGoblin->GoblinEndSprint();
	//}
}

void AGoblinController::TableExit()
{
	SwapToGoblinInput();
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
}

void AGoblinController::Server_PlayerBeg_Implementation()
{
}

void AGoblinController::Server_PlayerSprint_Implementation()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinStartSprint();
	}
}

void AGoblinController::Server_PlayerEndSprint_Implementation()
{
	if (PlayerGoblin)
	{
		PlayerGoblin->GoblinEndSprint();
	}
}
