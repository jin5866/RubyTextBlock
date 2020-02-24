// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "Engine/DataTable.h"
#include "CustomDataTables.h"
#include "RubyTextBlockDecorator.generated.h"

/**
 * 
 */
UCLASS()
class HELLOSLATE_API URubyTextBlockDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()
public:
	URubyTextBlockDecorator(const FObjectInitializer& ObjectInitializer);

	virtual TSharedPtr<ITextDecorator> CreateDecorator(URichTextBlock* InOwner) override;

	//UPROPERTY(EditAnywhere, Category = Appearance, meta = (RowType = "RubyFontTableRow"))
	//class UDataTable* RubyFontSet;

	UPROPERTY(EditAnywhere, Category = Appearance)
	FRubyTextFontData RubyFont;

	UPROPERTY(EditAnywhere, Category = Appearance)
	FRubyTextFontData BodyFont;
};
