// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundCueVolume.generated.h"

UCLASS()
class SIMPLESHOOTERWORKING_API ASoundCueVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundCueVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* SoundTriggerVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundCue* SoundToPlay;

	class UBillboardComponent* Billboard;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
