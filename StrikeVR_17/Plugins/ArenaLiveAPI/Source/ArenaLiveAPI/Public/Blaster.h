// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blaster.generated.h"

class ABlasterManager;
class UBlasterBehaviour;
class BlasterState;

UCLASS(ClassGroup = (ArenaLive), meta = (BlueprintSpawnableComponent))
class ARENALIVEAPI_API UBlaster : public UActorComponent
{
	GENERATED_BODY()

public:
	friend class ABlasterManager;

public:
	UBlaster();
	~UBlaster();

public:
	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	UBlasterBehaviour * GetBehaviour() const;

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void SetBehaviour(UBlasterBehaviour * behaviour);

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	bool IsConnected() const;
	
private:
	BlasterState * GetState() const;
	void SetState(TUniquePtr<BlasterState> state);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ArenaLive)
	UBlasterBehaviour * Behaviour = nullptr;

private:
	BlasterState * mState = nullptr;
};
