#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VeeraTrainingTarget.generated.h"

UCLASS()
class VEERA_API AVeeraTrainingTarget : public AActor
{
    GENERATED_BODY()

public:
    AVeeraTrainingTarget();

    bool CompleteDrill();
    bool IsCompleted() const { return bCompleted; }

protected:
    UPROPERTY(VisibleAnywhere, Category = "VEERA|Training")
    TObjectPtr<class UStaticMeshComponent> TargetMesh;

    UPROPERTY(VisibleAnywhere, Category = "VEERA|Training")
    TObjectPtr<class UTextRenderComponent> Label;

private:
    bool bCompleted = false;
};
