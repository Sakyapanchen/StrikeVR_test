// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumProperty.h"
#include "BlasterEnums.generated.h"


UENUM(meta = (Bitflags), BlueprintType)
enum class EBlasterUserConditions : uint8
{
	None = 0,

	OutOfAmmo = 1,
	UserCondition0 = 2,
	UserCondition1 = 4,
	UserCondition2 = 8,
	UserCondition3 = 16,
	UserCondition4 = 32,
	UserCondition5 = 64,
};

ENUM_CLASS_FLAGS(EBlasterUserConditions)

UENUM(meta = (Bitflags), BlueprintType)
enum class EBlasterButtons : uint8
{
	None = 0,

	Trigger = 1,
	LeftFront = 2,
	RightFront = 4,
	LeftBack = 8,
	RightBack = 16,
	Bottom = 32,
};

ENUM_CLASS_FLAGS(EBlasterButtons)

UENUM(BlueprintType)
enum class EBlasterTouchpad : uint8
{
	Right = 0,
	Left = 1,
};

ENUM_CLASS_FLAGS(EBlasterTouchpad)
