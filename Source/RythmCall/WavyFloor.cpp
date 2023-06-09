// Fill out your copyright notice in the Description page of Project Settings.


#include "WavyFloor.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AWavyFloor::AWavyFloor()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AWavyFloor::DelayFunction(float DelayTime)
{
    // GetWorld() 함수를 사용하여 월드 객체를 가져옵니다.
    UWorld* World = GetWorld();

    if (World)
    {
        // 타이머 매니저를 가져옵니다.
        FTimerManager& TimerManager = World->GetTimerManager();

        // 타이머를 설정하여 딜레이를 적용합니다.
        TimerManager.SetTimer(TimerHandle_Delay, DelayTime, false);
    }
}


void AWavyFloor::TriggerPinsSequence(const TArray<int32>& PinOrder)
{
    for (int32 PinIndex : PinOrder)
    {
        if (PinIndex == 0)
        {
            // 인덱스 0번 핀에 실행해야 할 함수를 호출합니다.
            
        }
        else if (PinIndex == 1)
        {
            // 인덱스 1번 핀에 실행해야 할 함수를 호출합니다.

            // foreach loop
        }

    }
}

// Called when the game starts or when spawned
void AWavyFloor::BeginPlay()
{
	Super::BeginPlay();
	
    DelayFunction(BeatLength);


}
//AActor* GetActorOfClass(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass)
//{
//    if (WorldContextObject)
//    {
//        UWorld* World = WorldContextObject->GetWorld();
//        if (World)
//        {
//            for (TActorIterator<AActor> ActorItr(World, ActorClass); ActorItr; ++ActorItr)
//            {
//                return *ActorItr;
//            }
//        }
//    }
//
//    return nullptr;
//}
void AWavyFloor::Trigger(bool bDelay, FVector Color, float DelayTime)
{
	bDelay = false;
	bTriggered = false;
	if (!bTriggered)
	{
		bTriggered = true;
        DelayFunction(bDelay * DelayTime);
        if (bDelay)
        {
            AddedColor = Color;
        }
        else
        {
            FMath::SRandInit(FMath::FRand());
            float Alpha = FMath::FRand();

            FVector LerpedVector = FMath::Lerp(ColorImpact1, ColorImpact2, Alpha);
            AddedColor = LerpedVector;
        }
        // 호출하고자 하는 Sequence 함수를 여기에 작성합니다.
        TArray<int32> PinOrder;
        PinOrder.Add(0);
        PinOrder.Add(1);
        TriggerPinsSequence(PinOrder);
	}
}

// Called every frame
void AWavyFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

