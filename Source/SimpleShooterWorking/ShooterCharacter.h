// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTERWORKING_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	UPROPERTY(EditAnywhere)
		float RotationRate;

	UPROPERTY(EditAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	float MaxHealth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	UFUNCTION(BlueprintCallable)
	class AGun* GetCurrentGun(){ return CurrentGun; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items)
	class AItem* ActiveOverlappingItem;

	TArray<FVector> PickupLocations;

	void Shoot();

	void CharacterReload();


	UFUNCTION(BlueprintCallable)
	void IncrementHealth(float Amount);

private:
	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);

	void LookUpRate(float AxisRate);

	void LookRightRate(float AxisRate);


	// Getting the class
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGun> GunClass;

	UPROPERTY()
		AGun* CurrentGun;

};
