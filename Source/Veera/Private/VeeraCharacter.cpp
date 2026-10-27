#include "VeeraCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/InputSettings.h"

AVeeraCharacter::AVeeraCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
    bUseControllerRotationPitch = true;
    bUseControllerRotationYaw = true;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->MaxWalkSpeed = 380.0f;
    GetCharacterMovement()->MaxWalkSpeedCrouched = 180.0f;
    GetCharacterMovement()->JumpZVelocity = 360.0f;
    GetCharacterMovement()->AirControl = 0.25f;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 0.0f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bDoCollisionTest = false;

    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(CameraBoom);
    FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
    FirstPersonCamera->bUsePawnControlRotation = false;
}

void AVeeraCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AVeeraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AVeeraCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AVeeraCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AVeeraCharacter::MoveForward(float Value)
{
    if (Controller && FMath::Abs(Value) > KINDA_SMALL_NUMBER)
    {
        AddMovementInput(FRotationMatrix(FRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), Value);
    }
}

void AVeeraCharacter::MoveRight(float Value)
{
    if (Controller && FMath::Abs(Value) > KINDA_SMALL_NUMBER)
    {
        AddMovementInput(FRotationMatrix(FRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), Value);
    }
}

void AVeeraCharacter::TurnAtRate(float Value)
{
    AddControllerYawInput(Value);
}

void AVeeraCharacter::LookUpAtRate(float Value)
{
    AddControllerPitchInput(Value);
}
