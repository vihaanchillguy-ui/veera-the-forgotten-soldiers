#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VeeraCharacter.generated.h"

UCLASS()
class VEERA_API AVeeraCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AVeeraCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void TurnAtRate(float Value);
    void LookUpAtRate(float Value);

    UPROPERTY(VisibleAnywhere, Category = "VEERA|Camera")
    TObjectPtr<class USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, Category = "VEERA|Camera")
    TObjectPtr<class UCameraComponent> FirstPersonCamera;
};
