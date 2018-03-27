// Fill out your copyright notice in the Description page of Project Settings.

#include "SingleShotWeapon.h"

#include "BlasterManager.h"
#include "Blaster.h"
#include "BlasterInput.h"

#include "ModeManager.h"


USingleShotWeapon::USingleShotWeapon()
{
}

USingleShotWeapon::~USingleShotWeapon()
{
}

void USingleShotWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void USingleShotWeapon::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (!IsConnected())
		return;

	auto * input = GetBlasterInput();

	if(input->GetButtonDown(EBlasterButtons::Trigger))
	{
		if (IsReadyToFire(FireDelay))
			Fire();
	}
}

void USingleShotWeapon::OnActivated()
{
	Super::OnActivated();
}

void USingleShotWeapon::OnDeactivated()
{
	Super::OnDeactivated();
}

void USingleShotWeapon::OnEventPointReached(FHapticEventPointArgs args)
{
	Super::OnEventPointReached(args);
}
