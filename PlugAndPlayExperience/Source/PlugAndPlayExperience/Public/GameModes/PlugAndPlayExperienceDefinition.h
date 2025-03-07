// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlugAndPlayExperienceDefinition.generated.h"

class UGameFeatureAction;
/**
 * Definition of an experience
 */
UCLASS(BlueprintType, Const)
class PLUGANDPLAYEXPERIENCE_API UPlugAndPlayExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPlugAndPlayExperienceDefinition();

	//~UObject interface
#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(TArray<FText>& ValidationErrors) override;
#endif
	//~End of UObject interface

	//~UPrimaryDataAsset interface
#if WITH_EDITORONLY_DATA
	virtual void UpdateAssetBundleData() override;
#endif
	//~End of UPrimaryDataAsset interface

public:
	// List of Game Feature Plugins this experience wants to have active
	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TArray<FString> GameFeaturesToEnable;

	/** @TODO: The default pawn class to spawn for players */
	//@TODO: Make soft?

	// List of actions to perform as this experience is loaded/activated/deactivated/unloaded
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Actions")
	TArray<TObjectPtr<UGameFeatureAction>> Actions;

	// @TODO: List of additional action sets to compose into this experience
};
