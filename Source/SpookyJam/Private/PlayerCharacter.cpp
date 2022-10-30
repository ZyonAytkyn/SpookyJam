// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::SpawnObject()
{
	FActorSpawnParameters SpawnParams;
	FVector loc = GetActorLocation();
	FTransform(FVector(0, 0, 0), FVector(0, 0, 0), FVector(0, 0, ), loc);
	FRotator rot = GetActorRotation();
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, loc, rot, SpawnParams);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::SpawnObject);
}

void APlayerCharacter::MoveUp(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void APlayerCharacter::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

