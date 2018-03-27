// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlasterTouchpadData.generated.h"

class BlasterState;

USTRUCT(BlueprintType)
struct ARENALIVEAPI_API FBlasterTouchpadData
{
	GENERATED_BODY()

public:
	FBlasterTouchpadData();
	FBlasterTouchpadData(FVector2D position, float pressure);
	~FBlasterTouchpadData();

public:
	FVector2D GetPosition() const;
	float GetPressure() const;

protected:
	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	float PositionX = 0;

	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	float PositionY = 0;

	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	float Pressure = 0;
};
