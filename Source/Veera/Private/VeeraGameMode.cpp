#include "VeeraGameMode.h"

#include "VeeraCharacter.h"
#include "VeeraTrainingTarget.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

AVeeraGameMode::AVeeraGameMode()
{
    DefaultPawnClass = AVeeraCharacter::StaticClass();
}

void AVeeraGameMode::BeginPlay()
{
    Super::BeginPlay();
    BuildTrainingGround();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(0, 12.0f, FColor(230, 210, 160),
            TEXT("VEERA | TRAINING YARD   Move: WASD   Look: Mouse   Jump: Space   Inspect target: E"));
        GEngine->AddOnScreenDebugMessage(1, 12.0f, FColor::White,
            TEXT("DRILL 01: Inspect all three range targets. This is a prototype training exercise."));
    }
}

void AVeeraGameMode::BuildTrainingGround()
{
    // Engine basic shapes keep the prototype self-contained; replace these with licensed art later.
    SpawnBlock(FVector(0.0f, 0.0f, -150.0f), FVector(40.0f, 40.0f, 0.5f));

    // A simple parade-yard boundary and a few training-lane markers.
    SpawnBlock(FVector(800.0f, -1800.0f, 90.0f), FVector(0.5f, 22.0f, 1.0f));
    SpawnBlock(FVector(800.0f, 1800.0f, 90.0f), FVector(0.5f, 22.0f, 1.0f));
    SpawnBlock(FVector(1150.0f, 0.0f, 40.0f), FVector(0.7f, 0.7f, 0.4f));
    SpawnBlock(FVector(1500.0f, -600.0f, 40.0f), FVector(0.7f, 0.7f, 0.4f));
    SpawnBlock(FVector(1500.0f, 600.0f, 40.0f), FVector(0.7f, 0.7f, 0.4f));

    const FVector TargetLocations[] =
    {
        FVector(520.0f, -180.0f, 64.0f),
        FVector(520.0f, 0.0f, 64.0f),
        FVector(520.0f, 180.0f, 64.0f)
    };

    for (int32 Index = 0; Index < UE_ARRAY_COUNT(TargetLocations); ++Index)
    {
        AVeeraTrainingTarget* Target = GetWorld()->SpawnActor<AVeeraTrainingTarget>(
            AVeeraTrainingTarget::StaticClass(), TargetLocations[Index], FRotator::ZeroRotator);
        if (Target)
        {
            Target->SetActorScale3D(FVector(0.18f, 0.55f, 0.55f));
        }
    }
}

void AVeeraGameMode::SpawnBlock(const FVector& Location, const FVector& Scale, const FRotator& Rotation)
{
    static UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (!CubeMesh || !GetWorld())
    {
        return;
    }

    AStaticMeshActor* Block = GetWorld()->SpawnActor<AStaticMeshActor>(Location, Rotation);
    if (Block)
    {
        Block->GetStaticMeshComponent()->SetStaticMesh(CubeMesh);
        Block->SetActorScale3D(Scale);
    }
}

void AVeeraGameMode::RegisterTargetCompleted()
{
    ++CompletedTargets;
    if (!GEngine)
    {
        return;
    }

    const FString Progress = FString::Printf(TEXT("DRILL 01: Targets inspected %d / %d"), CompletedTargets, TotalTargets);
    GEngine->AddOnScreenDebugMessage(1, 4.0f, FColor(230, 210, 160), Progress);

    if (CompletedTargets >= TotalTargets)
    {
        GEngine->AddOnScreenDebugMessage(2, 8.0f, FColor::Green,
            TEXT("DRILL COMPLETE | Training-yard foundation ready for the next exercise."));
    }
}
