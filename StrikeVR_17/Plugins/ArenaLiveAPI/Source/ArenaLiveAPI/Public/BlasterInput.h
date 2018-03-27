// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "BlasterEnums.h"
#include "BlasterTouchpadData.h"
#include "BlasterInput.generated.h"

class BlasterState;

UCLASS(ClassGroup = (ArenaLive), meta = (BlueprintType))
class ARENALIVEAPI_API UBlasterInput : public UObject
{
	GENERATED_BODY()

public:
	friend class UBlasterBehaviour;

private:
	UBlasterInput();
	~UBlasterInput();

public:
	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	FBlasterTouchpadData GetTouchpadData(EBlasterTouchpad touchpad);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	bool GetButton(EBlasterButtons button);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	bool GetButtonUp(EBlasterButtons button);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	bool GetButtonDown(EBlasterButtons button);

private:
	void SetState(BlasterState * state);

private:
	BlasterState * mState = nullptr;
};
