// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StandardHUD.generated.h"

/**
 * 
 */

class SStandardSlateWidget;

UCLASS()
class HELLOSLATE_API AStandardHUD : public AHUD
{
	GENERATED_BODY()
	

public:
	// ++ Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	// MyUIWidget will not self-destruct as long as refcount > 0. refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<SStandardSlateWidget> MyUIWidget;

	// ++ Called as soon as game starts, create SCompoundWidget and give Viewport access
	void BeginPlay();
};
