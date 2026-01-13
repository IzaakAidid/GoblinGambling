// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinPlayerHUD.h"
#include "Blueprint/UserWidget.h"

AGoblinPlayerHUD::AGoblinPlayerHUD()
{
}

void AGoblinPlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (pGameUI)
	{
		pGameUI->AddToViewport();
	}
}
