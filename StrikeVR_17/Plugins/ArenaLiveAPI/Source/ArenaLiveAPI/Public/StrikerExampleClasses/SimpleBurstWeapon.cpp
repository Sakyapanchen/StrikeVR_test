// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleBurstWeapon.h"

#include "BlasterManager.h"
#include "Blaster.h"
#include "BlasterInput.h"


USimpleBurstWeapon::USimpleBurstWeapon()
{
}

USimpleBurstWeapon::~USimpleBurstWeapon()
{
}

void USimpleBurstWeapon::BeginPlay()
{
	Super::BeginPlay();

	ResetBurstState();
}

void USimpleBurstWeapon::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (!IsConnected())
		return;

	auto * input = GetBlasterInput();

	if (input->GetButton(EBlasterButtons::Trigger))
	{
		const float delay = mInBurst ? FireRate : FireDelay;

		if (IsReadyToFire(delay) && mShotCount > 0)
		{
			mInBurst = true;
			--mShotCount;

			if (!Fire())
			{
				mShotCount = 0;
				mInBurst = false;
			}
		}
	}

	if (input->GetButtonUp(EBlasterButtons::Trigger))
	{
		ResetBurstState();
	}
}

void USimpleBurstWeapon::OnActivated()
{
	Super::OnActivated();
}

void USimpleBurstWeapon::OnDeactivated()
{
	Super::OnDeactivated();
}

void USimpleBurstWeapon::OnEventPointReached(FHapticEventPointArgs args)
{
	Super::OnEventPointReached(args);
}

void USimpleBurstWeapon::ResetBurstState()
{
	mInBurst = false;
	mShotCount = 3;
}
