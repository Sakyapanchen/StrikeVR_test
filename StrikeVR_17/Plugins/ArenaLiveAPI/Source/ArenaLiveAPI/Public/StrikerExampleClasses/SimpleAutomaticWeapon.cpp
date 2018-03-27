// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleAutomaticWeapon.h"

#include "BlasterManager.h"
#include "Blaster.h"
#include "BlasterInput.h"


USimpleAutomaticWeapon::USimpleAutomaticWeapon()
{
}

USimpleAutomaticWeapon::~USimpleAutomaticWeapon()
{
}

void USimpleAutomaticWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void USimpleAutomaticWeapon::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (!IsConnected())
		return;

	auto * input = GetBlasterInput();

	if (input->GetButton(EBlasterButtons::Trigger))
	{
		if (IsReadyToFire(FireDelay) && mContinueFiring)
		{
			mContinueFiring = Fire();
			DisableReload = true;
		}
	}

	if (input->GetButtonUp(EBlasterButtons::Trigger))
	{
		mContinueFiring = true;
		DisableReload = false;
	}
}

void USimpleAutomaticWeapon::OnActivated()
{
	Super::OnActivated();
	DisableReload = false;
}

void USimpleAutomaticWeapon::OnDeactivated()
{
	Super::OnDeactivated();
}

void USimpleAutomaticWeapon::OnEventPointReached(FHapticEventPointArgs args)
{
	Super::OnEventPointReached(args);
}
