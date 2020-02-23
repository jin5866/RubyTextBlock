// Fill out your copyright notice in the Description page of Project Settings.


#include "SRubyTextSlate.h"
#include "SlateOptMacros.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Runtime/Engine/Classes/Engine/Engine.h" 


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SRubyTextSlate"

void SRubyTextSlate::Construct(const FArguments& InArgs, const FString* Ruby, FText Body, class UDataTable* RubyFontT)
{
	
	if (RubyFontT) 
	{
		RubyFont = RubyFontT;
	}
	else
	{
		RubyFont = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Game/RubyTextFont")));
	}

	if (RubyFont)
	{
		UE_LOG(LogTemp, Log, TEXT("success"))
	}

	FRubyFontTableRow* RubyRontRow = RubyFont->FindRow<FRubyFontTableRow>(FName("Ruby"), FString(""));
	FRubyFontTableRow* BodyRontRow = RubyFont->FindRow<FRubyFontTableRow>(FName("Body"), FString(""));


	ChildSlot
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(0,0,0,0)
			[
			// Inside lies a text block with these settings
				SNew(STextBlock)
				//.ColorAndOpacity(FLinearColor::Red)
				//.Font(FSlateFontInfo("/Game/Font/Cafe24Ohsquare_Font.Cafe24Ohsquare_Font",16))
				.Font(RubyRontRow->font)
				// localized text to be translated with a generic name HelloSlateText
				.Text(FText::FromString(*Ruby))
				//.Text(LOCTEXT("HelloSlateText", "123456"))
				.ColorAndOpacity(RubyRontRow->color)
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				// Inside lies a text block with these settings
				SNew(STextBlock)
				//.ColorAndOpacity(FLinearColor::Red)
				.Font(BodyRontRow->font)
				// localized text to be translated with a generic name HelloSlateText
				.Text(Body)
				//.Text(LOCTEXT("HelloSlateText", "123456789"))
				.ColorAndOpacity(BodyRontRow->color)
			]
		];
}



#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
