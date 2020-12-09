// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERWORKING_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:


	virtual void GameHasEnded(class AActor *EndGameFocus = nullptr, bool bIsWinner = false) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> WinScreenClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> PauseMenuClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
		class UUserWidget* PauseMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
		bool bPauseMenuOpen;

	void GameModeOnly();

	UFUNCTION(BlueprintNativeEvent)
		void DisplayPauseMenu();

	UFUNCTION(BlueprintNativeEvent)
		void RemovePauseMenu();

	UFUNCTION(BlueprintCallable)
		void TogglePauseMenu();

protected:
	virtual void BeginPlay() override;

private:



	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.f;

	FTimerHandle RestartTimer;

	UUserWidget *HUD;
};
