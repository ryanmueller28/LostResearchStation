// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bPauseMenuOpen = false;

	HUD = CreateWidget(this, HUDClass);

	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}

	if (PauseMenuClass)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, PauseMenuClass);
		PauseMenu->AddToViewport();
		PauseMenu->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AShooterPlayerController::GameModeOnly()
{
	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
}

void AShooterPlayerController::DisplayPauseMenu_Implementation()
{
	bPauseMenuOpen = true;

	FInputModeGameAndUI InputModeGameAndUI;
	SetInputMode(InputModeGameAndUI);
}

void AShooterPlayerController::TogglePauseMenu()
{
	if (!bPauseMenuOpen)
	{
		DisplayPauseMenu();
	}
	else
	{
		RemovePauseMenu();
	}
}

void AShooterPlayerController::RemovePauseMenu_Implementation()
{
	bPauseMenuOpen = false;

	GameModeOnly();
}

void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();

	if (bIsWinner)
	{
		UUserWidget *WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget *LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}