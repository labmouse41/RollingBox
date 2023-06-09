// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WavyFloor.generated.h"

UCLASS()
class RYTHMCALL_API AWavyFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWavyFloor();

	UFUNCTION(BlueprintCallable)
	void Trigger(bool bDelay, const FVector Color, float DelayTime);

	UPROPERTY()
	bool bTriggered;

	UPROPERTY()
	float BeatLength;

	UPROPERTY()
	FVector AddedColor;

	UPROPERTY()
	float Glow;

	UPROPERTY()
	TArray <AWavyFloor*> NeighborList;
	
	UPROPERTY()
	FLinearColor ColorImpact1;

	UPROPERTY()
	FLinearColor ColorImpact2;

	UPROPERTY()
	FTimerHandle TimerHandle_Delay;

	UFUNCTION()
	void DelayFunction(float DelayTime);

	UFUNCTION(Category = "Pin Sequence")
	void TriggerPinsSequence(const TArray<int32>& PinOrder);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
