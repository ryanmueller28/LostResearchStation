// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterWorkingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERWORKING_API ASimpleShooterWorkingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public: 
	virtual void PawnKilled(APawn* PawnKilled);
};
