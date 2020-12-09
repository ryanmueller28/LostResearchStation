// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_BlPLayerLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERWORKING_API UBTService_BlPLayerLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_BlPLayerLocationIfSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
