// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HapticEventPointArgs.h"
#include "BlasterEnums.h"
#include "BlasterBehaviour.generated.h"

class BlasterHapticStorage;
class BlasterHapticPlayer;
class BlasterFSMPlayer;
class BlasterState;
class UBlasterInput;

UCLASS(ClassGroup = (ArenaLive), meta = (BlueprintSpawnableComponent))
class ARENALIVEAPI_API UBlasterBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:
	friend class ABlasterManager;
	friend class UBlaster;

public:
	UBlasterBehaviour();
	~UBlasterBehaviour();

protected:
	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	int32 InitialModeID = 0;

	virtual void OnActivated();
	virtual void OnDeactivated();

	virtual void OnEventPointReached(FHapticEventPointArgs args);

public:
	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	bool IsConnected() const;

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	UBlasterInput * GetBlasterInput() const;

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	int GetInitialModeID() const;

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void SetInitialModeID(int modeID);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void PlayModeSlot(int slotIndex);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void SetUserConditions(EBlasterUserConditions userConditions);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void ChangeMode(int modeID);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void StopPlaying(bool force = false);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void EnableTouchpads();

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void DisableTouchpads();

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void EnableHaptics();

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void DisableHaptics();

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventPointReached, FHapticEventPointArgs, args);
	UPROPERTY(Category = ArenaLive, BlueprintAssignable)
	FEventPointReached EventPointReached;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActivated);
	UPROPERTY(Category = ArenaLive, BlueprintAssignable)
	FActivated Activated;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeactivated);
	UPROPERTY(Category = ArenaLive, BlueprintAssignable)
	FDeactivated Deactivated;

private:
	void SetState(BlasterState * blasterState);

	void InternalUpdate(float deltaTime);

private:
	void ActivateState();
	void DeactivateState();

	void FireActivated();
	void FireDeactivated();
	void FireEventPointReached(FHapticEventPointArgs args);

private:

	UPROPERTY()
	UBlasterInput * mInput = nullptr;

	BlasterHapticPlayer * mHapticPlayer = nullptr;
	BlasterFSMPlayer * mFSMPlayer = nullptr;
	BlasterState * mState = nullptr;
};
