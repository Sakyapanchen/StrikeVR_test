// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ModeManager.generated.h"

class ABlasterManager;
class UBlaster;
class UBlasterBehaviour;

UCLASS(meta = (BlueprintSpawnableComponent))
class UModeManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UModeManager();
	~UModeManager();

public:
	void NextBehavior();
	void ChangeBehavior(int index);

protected:
	void BeginPlay() override;
	void TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction) override;

private:
	UBlaster * mBlaster = nullptr;

	TArray<UBlasterBehaviour *> mBehaviors;
	int mBehaviorIndex = 0;
	float mBehaviorUpdateDelay = 0;
};
