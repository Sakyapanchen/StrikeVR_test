// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HapticEventPointArgs.generated.h"

USTRUCT(BlueprintType)
struct ARENALIVEAPI_API FHapticEventPointArgs
{
	GENERATED_BODY()

public:
	FHapticEventPointArgs();
	FHapticEventPointArgs(int modeID, int hapticID, int eventType);
	~FHapticEventPointArgs();

public:
	int GetModeID() const;
	int GetHapticID() const;
	int GetEventType() const;

protected:
	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	int ModeID = 0;

	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	int HapticID = 0;

	UPROPERTY(Category = ArenaLive, BlueprintReadOnly)
	int EventType = 0;
};
