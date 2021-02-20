// Copyright by Nagy Dávid 2021


#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "..\Public\Tank.h"



ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}
void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP Begin Play to run!
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(Projectile_BP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}