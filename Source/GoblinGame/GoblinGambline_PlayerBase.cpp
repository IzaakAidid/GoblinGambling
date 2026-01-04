// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinGambline_PlayerBase.h"

// Sets default values
AGoblinGambline_PlayerBase::AGoblinGambline_PlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoblinGambline_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
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

}

