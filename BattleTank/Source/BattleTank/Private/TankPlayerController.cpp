// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto GetTank = GetControlledTank();
	if (!GetTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController does not work"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank is %s"), *(GetTank->GetName()));
	}
	

	UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay"));
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }


}