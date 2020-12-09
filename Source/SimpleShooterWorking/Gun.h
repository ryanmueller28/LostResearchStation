// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTERWORKING_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	UPROPERTY(EditAnywhere)
		int CurrentAmmo;

	UPROPERTY(EditAnywhere)
		int MaxAmmo;

	UFUNCTION(BlueprintCallable)
	int GetCurrentAmmo() { return CurrentAmmo; }

	UFUNCTION(BlueprintCallable)
	int GetMaxAmmo() { return MaxAmmo; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

	void Reload();
private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float Damage = 10.f;

	bool bCanShoot();

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	

	AController* GetOwnerController() const;
};
