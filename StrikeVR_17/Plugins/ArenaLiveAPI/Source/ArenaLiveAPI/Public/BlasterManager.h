// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlasterEnums.h"
#include "BlasterManager.generated.h"

class UBlaster;
class BlasterHapticStorage;
class MessageChannel;
struct Message;

UCLASS(ClassGroup = (ArenaLive))
class ARENALIVEAPI_API ABlasterManager : public AActor
{
	GENERATED_BODY()

public:
	ABlasterManager();
	~ABlasterManager();

public:
	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void Connect();

	UFUNCTION(Category = ArenaLive, BlueprintCallable)
	void Disconnect();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnBlasters, int, numberOfBlasters);
	UPROPERTY(Category = ArenaLive, BlueprintAssignable)
	FSpawnBlasters SpawnBlasters;

public:
	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	FString ProjectName = "Unreal API";

	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	FString DataFileName = "HapticModeData.hptm";

	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	FString DaemonHostName = "localhost";

	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	bool AutoConnect = true;

	UPROPERTY(Category = ArenaLive, EditAnywhere, BlueprintReadOnly)
	int MaxNumberOfBlasters = 1;

public:
	const TArray<UBlaster *> & GetBlasters() const;

protected:
	void BeginPlay() override;

public:
	void Tick(float deltaTime) override;

private:
	void RegisterBlasters();
	UBlaster * GetBlasterByPlayerID(int playerID);

	bool HandleMessage(const Message & message);

	void HandleGameStarted(const Message & message);
	void HandleBlasterButtonEvents(const Message & message);
	void HandleBlasterTouchpadEvent(const Message & message, EBlasterTouchpad touchpad);

private:
	BlasterHapticStorage * mHapticStorage = nullptr;
	MessageChannel * mChannel = nullptr;

	TArray<UBlaster *> mBlasters;
};
