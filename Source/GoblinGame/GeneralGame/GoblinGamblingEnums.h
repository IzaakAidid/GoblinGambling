// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * All Enums go in this file
 */

UENUM(BlueprintType)
enum class ECasinoChipsType : uint8 {
	CASINO1 = 0 UMETA(DisplayName = "CasinoOne"),
	CASINO2 = 1  UMETA(DisplayName = "CasinoTwo"),
	CASINO3 = 2  UMETA(DisplayName = "CasinoThree")
};

UENUM(BlueprintType)
enum class ECasinoChipValue : uint8 {
	CHIPVALUEONE = 0 UMETA(DisplayName = "ChipValueOne"),
	CHIPVALUEFIVE = 1  UMETA(DisplayName = "ChipValueFive"),
	CHIPVALUETWENTY = 2  UMETA(DisplayName = "ChipValueTwenty")
};


class GOBLINGAME_API GoblinGamblingEnums
{
public:
	GoblinGamblingEnums();
	~GoblinGamblingEnums();
};
