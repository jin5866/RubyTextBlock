// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "CustomDataTables.generated.h"

USTRUCT(BlueprintType)
struct FRubyTextFontData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FSlateFontInfo font;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FSlateColor color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FSlateBrush brush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FVector2D shadowOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FLinearColor shadowColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "font")
	FMargin textPadding = FMargin(0, 0, 0, 0);
};


UCLASS()
class HELLOSLATE_API ACustomDataTables : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomDataTables();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
