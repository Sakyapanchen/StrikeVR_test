// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractWeapon.h"
#include "SingleShotWeapon.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class USingleShotWeapon : public UAbstractWeapon
{
	GENERATED_BODY()

public:
	USingleShotWeapon();
	~USingleShotWeapon();

protected:
	UPROPERTY(EditAnywhere, Category = ArenaLive)
	float FireDelay = 1;

protected:
	void BeginPlay() override;
	void TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction * thisTickFunction) override;

	void OnActivated() override;
	void OnDeactivated() override;

	void OnEventPointReached(FHapticEventPointArgs args) override;
};
