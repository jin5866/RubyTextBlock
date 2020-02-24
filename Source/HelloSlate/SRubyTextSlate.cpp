// Fill out your copyright notice in the Description page of Project Settings.


#include "SRubyTextSlate.h"
#include "SlateOptMacros.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Runtime/Engine/Classes/Engine/Engine.h" 


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SRubyTextSlate"

void SRubyTextSlate::Construct(const FArguments& InArgs, const FText Ruby, const FText Body, FRubyTextFontData RubyFont, FRubyTextFontData BodyFont)
{
	/*
	if (RubyFontT) 
	{
		RubyFont = RubyFontT;
	}
	else
	{
		RubyFont = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Game/RubyTextFont")));
	}*/

	//FRubyTextFontData* RubyFontRow = RubyFont;
	//FRubyTextFontData * BodyFontRow = BodyFont;

	ChildSlot
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(0,-15,0,-5)
			[
				// Ruby Text Block
				SNew(STextBlock)
				.Font(RubyFont.font)
				.Text(Ruby)
				.ColorAndOpacity(RubyFont.color)
				.ShadowColorAndOpacity(RubyFont.shadowColor)
				.ShadowOffset(RubyFont.shadowOffset)
				//.StrikeBrush(&(RubyFont.brush))
				
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				// body text block
				SNew(STextBlock)
				.Font(BodyFont.font)
				.Text(Body)
				.ColorAndOpacity(BodyFont.color)
				.ShadowColorAndOpacity(BodyFont.shadowColor)
				.ShadowOffset(BodyFont.shadowOffset)
				//.StrikeBrush(&(BodyFont.brush))
			]
		];
}



#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
