// Copyright by Nagy D�vid 2021


#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "..\Public\Tank.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; 
}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATank::Fire(){
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			Projectile_BP,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
