// Fill out your copyright notice in the Description page of Project Settings.

#include "ModeManager.h"

#include "BlasterManager.h"
#include "Blaster.h"
#include "BlasterBehaviour.h"
#include "BlasterInput.h"


UModeManager::UModeManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

UModeManager::~UModeManager()
{
}

void UModeManager::NextBehavior()
{
	if (++mBehaviorIndex == mBehaviors.Num())
		mBehaviorIndex = 0;

	ChangeBehavior(mBehaviorIndex);
}

void UModeManager::ChangeBehavior(int index)
{
	check(mBehaviors.IsValidIndex(index));

	mBehaviorIndex = index;
	mBehaviorUpdateDelay = 0;
}

void UModeManager::BeginPlay()
{
	Super::BeginPlay();

	SetComponentTickEnabled(true);

	mBlaster = GetOwner()->FindComponentByClass<UBlaster>();
	check(mBlaster);

	for (auto * behavior : GetOwner()->GetComponentsByClass(UBlasterBehaviour::StaticClass()))
		mBehaviors.Add(static_cast<UBlasterBehaviour *>(behavior));

	check(mBehaviors.Num() > 0);
	ChangeBehavior(0);
}

void UModeManager::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction)
{
	mBehaviorUpdateDelay += deltaTime;

	const float updateDelay = 0.1f;
	if (mBlaster->GetBehaviour() != mBehaviors[mBehaviorIndex] && mBehaviorUpdateDelay > updateDelay)
	{
		auto * newBehavior = mBehaviors[mBehaviorIndex];
		mBlaster->SetBehaviour(newBehavior);
	}
}
