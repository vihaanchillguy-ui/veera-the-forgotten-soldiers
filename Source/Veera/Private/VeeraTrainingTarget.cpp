#include "VeeraTrainingTarget.h"

#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "UObject/ConstructorHelpers.h"

AVeeraTrainingTarget::AVeeraTrainingTarget()
{
    PrimaryActorTick.bCanEverTick = false;

    TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
    SetRootComponent(TargetMesh);
    TargetMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    TargetMesh->SetCollisionResponseToAllChannels(ECR_Block);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMesh.Succeeded())
    {
        TargetMesh->SetStaticMesh(CubeMesh.Object);
    }

    Label = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Label"));
    Label->SetupAttachment(TargetMesh);
    Label->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
    Label->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    Label->SetHorizontalAlignment(EHTA_Center);
    Label->SetWorldSize(28.0f);
    Label->SetText(FText::FromString(TEXT("RANGE TARGET")));
}

bool AVeeraTrainingTarget::CompleteDrill()
{
    if (bCompleted)
    {
        return false;
    }

    bCompleted = true;
    Label->SetText(FText::FromString(TEXT("COMPLETE")));
    TargetMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
    TargetMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    return true;
}
