// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetNPC_Controller.h"
#include "BrainComponent.h"

void AStreetNPC_Controller::PauseBehaviorTree()
{
    GetBrainComponent()->StopLogic("");
}

void AStreetNPC_Controller::StartBehaviorTree()
{
    GetBrainComponent()->RestartLogic();
}
