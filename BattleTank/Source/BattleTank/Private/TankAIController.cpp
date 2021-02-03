// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto GetTank = GetControlledTank();
	if (!GetTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController does not work"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank is %s"), *(GetTank->GetName()));
	}

	auto GetPTank = GetPlayerTank();
	if (!GetPTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank is found and is %s"), *(GetPTank->GetName()));
	}


	UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay"));
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}