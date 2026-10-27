#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VeeraGameMode.generated.h"

UCLASS()
class VEERA_API AVeeraGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AVeeraGameMode();

    virtual void BeginPlay() override;
    void RegisterTargetCompleted();

private:
    void BuildTrainingGround();
    void SpawnBlock(const FVector& Location, const FVector& Scale, const FRotator& Rotation = FRotator::ZeroRotator);

    int32 CompletedTargets = 0;
    int32 TotalTargets = 3;
};
