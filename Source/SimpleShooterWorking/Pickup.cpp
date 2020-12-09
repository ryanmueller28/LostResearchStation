// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "ShooterCharacter.h"
#include "Engine/World.h"

APickup::APickup()
{

}

void APickup::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult & SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AShooterCharacter* Main = Cast<AShooterCharacter>(OtherActor);

		if (Main)
		{
			OnPickupBP(Main);
			Main->PickupLocations.Add(GetActorLocation());
		}

		Destroy();
	}
}

void APickup::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}