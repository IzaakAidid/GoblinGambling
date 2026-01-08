// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblingGambling_SlotMachine.h"

AGoblingGambling_SlotMachine::AGoblingGambling_SlotMachine()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGoblingGambling_SlotMachine::BeginPlay()
{
	Super::BeginPlay();

}

void AGoblingGambling_SlotMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoblingGambling_SlotMachine::PlayerEnteredPlayArea()
{

}

void AGoblingGambling_SlotMachine::LeaveMinigame()
{

}

bool AGoblingGambling_SlotMachine::CheckBuyIn()
{
	return false;
}

void AGoblingGambling_SlotMachine::PayOutPlayer()
{

}

void AGoblingGambling_SlotMachine::PlayMinigame()
{

}
