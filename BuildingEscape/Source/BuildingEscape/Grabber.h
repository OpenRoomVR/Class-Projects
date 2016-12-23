// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	UGrabber(); // Sets default values for this component's properties
	virtual void BeginPlay() override; // Called when the game starts
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f; // How far ahead of the player can we reach in cm 
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab(); // Ray-cast and grab whats in reach
	void Release(); // Called when grab is released
	void FindPhysicsHandleComponent(); // Find (assumed) attached physics handle
	void SetupInputComponent(); // Setup (assumed) attached input component
	const FHitResult GetFirstPhysicsBodyInReach(); // Return hit for first physics body in reach
	FVector GetReachLineStart(); //Returns current start of reach line
	FVector GetReachLineEnd(); //Returns current end of reach line
};
