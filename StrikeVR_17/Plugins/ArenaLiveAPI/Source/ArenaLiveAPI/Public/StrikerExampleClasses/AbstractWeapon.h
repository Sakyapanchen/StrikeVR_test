// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlasterBehaviour.h"
#include "AbstractWeapon.generated.h"

class UModeManager;

UCLASS(Abstract)
class UAbstractWeapon : public UBlasterBehaviour
{
	GENERATED_BODY()

public:
	UAbstractWeapon();
	~UAbstractWeapon();

protected:
	UPROPERTY(EditAnywhere, Category = ArenaLive)
	int MaxAmmo = 10;

protected:
	UModeManager * GetModes() const;
	float GetLastShotDelay() const;

	bool GetUserCondition(EBlasterUserConditions userCondition) const;
	void SetUserCondition(EBlasterUserConditions userCondition, bool value);

	bool IsReadyToFire(float delay) const;

	int GetAmmo() const;
	bool HasAmmo(int ammo = 1) const;

	bool Fire(int ammo = 1);
	void Reload();

	bool DisableReload = false;


protected:
	void BeginPlay() override;
	void TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction) override;

	void OnActivated() override;
	void OnDeactivated() override;

	void OnEventPointReached(FHapticEventPointArgs args) override;

private:
	UModeManager * mModes = nullptr;

	int mAmmo = 0;
	float mLastShotDelay = 0;

	EBlasterUserConditions mUserConditions = EBlasterUserConditions::None;
};
