// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractWeapon.h"
#include "SimpleBurstWeapon.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class USimpleBurstWeapon : public UAbstractWeapon
{
	GENERATED_BODY()

public:
	USimpleBurstWeapon();
	~USimpleBurstWeapon();

protected:
	UPROPERTY(EditAnywhere, Category = ArenaLive)
	float FireDelay = 1;

	UPROPERTY(EditAnywhere, Category = ArenaLive)
	float FireRate = 0.3;

protected:
	void BeginPlay() override;
	void TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction) override;

	void OnActivated() override;
	void OnDeactivated() override;

	void OnEventPointReached(FHapticEventPointArgs args) override;

private:
	void ResetBurstState();

private:
	bool mInBurst = false;
	int mShotCount = 0;
};
