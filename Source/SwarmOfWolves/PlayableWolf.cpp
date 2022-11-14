// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableWolf.h"

// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayableWolf::APlayableWolf()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APlayableWolf::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayableWolf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayableWolf::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayableWolf::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &APlayableWolf::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &APawn::AddControllerYawInput);
}

void APlayableWolf::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayableWolf::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}




