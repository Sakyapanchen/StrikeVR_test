// Fill out your copyright notice in the Description page of Project Settings.

#include "AbstractWeapon.h"

#include "BlasterManager.h"
#include "Blaster.h"
#include "BlasterInput.h"

#include "ModeManager.h"


UAbstractWeapon::UAbstractWeapon()
{
	PrimaryComponentTick.bCanEverTick = true;
}

UAbstractWeapon::~UAbstractWeapon()
{
}

UModeManager * UAbstractWeapon::GetModes() const
{
	return mModes;
}

float UAbstractWeapon::GetLastShotDelay() const
{
	return mLastShotDelay;
}

bool UAbstractWeapon::GetUserCondition(EBlasterUserConditions userCondition) const
{
	return (mUserConditions & userCondition) != EBlasterUserConditions::None;
}

void UAbstractWeapon::SetUserCondition(EBlasterUserConditions userCondition, bool value)
{
	if (value)
		mUserConditions |= userCondition;
	else
		mUserConditions &= ~userCondition;
}

bool UAbstractWeapon::IsReadyToFire(float delay) const
{
	return mLastShotDelay > delay;
}

int UAbstractWeapon::GetAmmo() const
{
	return mAmmo;
}

bool UAbstractWeapon::HasAmmo(int ammo) const
{
	check(ammo > 0);
	return (mAmmo) >= ammo;
}

bool UAbstractWeapon::Fire(int ammo)
{
	//if (mAmmo == 0)
	//	return false;

	mLastShotDelay = 0;

	if (HasAmmo(ammo))
	{
		mAmmo -= ammo;
	}
	else
	{
		PlayModeSlot(2);
		return false;
	}

	PlayModeSlot(0);

	return true;
}

void UAbstractWeapon::Reload()
{
	if (DisableReload)
	{
		return;
	}

	check(MaxAmmo > 0);

	mAmmo = MaxAmmo;
	PlayModeSlot(1);
}

void UAbstractWeapon::BeginPlay()
{
	Super::BeginPlay();

	SetComponentTickEnabled(true);

	mModes = GetOwner()->FindComponentByClass<UModeManager>();
	check(mModes);

	check(MaxAmmo >= 0);
	mAmmo = MaxAmmo;
}

void UAbstractWeapon::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (!IsConnected())
		return;

	mLastShotDelay += deltaTime;

	auto * input = GetBlasterInput();

	if (input->GetButtonUp(EBlasterButtons::Bottom))
	{
		Reload();
	}

	if ((input->GetButtonUp(EBlasterButtons::LeftBack)
		|| input->GetButtonUp(EBlasterButtons::RightBack)))
	{
		mModes->NextBehavior();
	}

	SetUserConditions(mUserConditions);
}

void UAbstractWeapon::OnActivated()
{
	Super::OnActivated();

	ChangeMode(GetInitialModeID());
}

void UAbstractWeapon::OnDeactivated()
{
	Super::OnDeactivated();
}

void UAbstractWeapon::OnEventPointReached(FHapticEventPointArgs args)
{
	Super::OnEventPointReached(args);
}
