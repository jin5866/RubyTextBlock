// Fill out your copyright notice in the Description page of Project Settings.


#include "SStandardSlateWidget.h"
#include "SlateOptMacros.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Runtime/Engine/Classes/Engine/Engine.h" 

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SStandardSlateWidget"


void SStandardSlateWidget::Construct(const FArguments& InArgs)
{
	/*
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTable(TEXT("DataTable'/Game/RubyTextFont'"));
	if (DataTable.Succeeded())
	{
		
	}*/
	// font from datatable
	UDataTable* RubyFont = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Game/RubyTextFont")));

	if (RubyFont)
	{
		UE_LOG(LogTemp, Log, TEXT("success"))
	}
	
	FRubyFontTableRow* fontRow = RubyFont->FindRow<FRubyFontTableRow>(FName("Ruby"),FString(""));

	ChildSlot
	.VAlign(VAlign_Top)
	.HAlign(HAlign_Fill)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		[
			// Inside lies a text block with these settings
			SNew(STextBlock)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ColorAndOpacity(FLinearColor::Red)
			.ShadowOffset(FIntPoint(-1, 1))
			//.Font(FSlateFontInfo("/Game/Font/Cafe24Ohsquare_Font.Cafe24Ohsquare_Font",16))
			.Font(fontRow->font)
			// localized text to be translated with a generic name HelloSlateText
			.Text(LOCTEXT("HelloSlateText", "123456"))
		]
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Center)
		[
			// Inside lies a text block with these settings
			SNew(STextBlock)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ColorAndOpacity(FLinearColor::Red)
			.ShadowOffset(FIntPoint(-1, 1))
			.Font(FSlateFontInfo("Veranda", 16))
			// localized text to be translated with a generic name HelloSlateText
			.Text(LOCTEXT("HelloSlateText", "123456789"))
		]
	];
	
}

#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
