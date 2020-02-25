// Fill out your copyright notice in the Description page of Project Settings.


#include "SRubyTextSlate.h"
#include "SlateOptMacros.h"

#include "CustomDataTables.h"
#include "UObject/ConstructorHelpers.h"

#include "Runtime/Engine/Classes/Engine/Engine.h" 


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SRubyTextSlate"

void SRubyTextSlate::Construct(const FArguments& InArgs, const FTextRunInfo& RunInfo, const FText RubyText, const FText BodyText, FRubyTextFontData RubyFontInfo, FRubyTextFontData BodyFontInfo)
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

	




	FSlateFontInfo rubyFont = RubyFontInfo.font;
	FSlateFontInfo bodyFont = BodyFontInfo.font;

	FSlateColor rubyColor = RubyFontInfo.color;
	FSlateColor bodyColor = BodyFontInfo.color;


	if (const FString* rubystyle = RunInfo.MetaData.Find(TEXT("ruby_style")))
	{
		rubyFont.TypefaceFontName = FName(**rubystyle);
	}

	if (const FString * bodystyle = RunInfo.MetaData.Find(TEXT("body_style")))
	{
		bodyFont.TypefaceFontName = FName(**bodystyle);
	}

	if (const FString * rubycolor = RunInfo.MetaData.Find(TEXT("ruby_color")))
	{
		rubyColor = FSlateColor(FColor::FromHex(*rubycolor));
	}

	if (const FString * bodycolor = RunInfo.MetaData.Find(TEXT("body_color")))
	{
		bodyColor = FSlateColor(FColor::FromHex(*bodycolor));
	}

	//FLinearColor rubyShadowColor = RubyFontInfo.shadowColor;
	//FLinearColor bodyShadowColor = BodyFontInfo.shadowColor;

	//Supported formats are: RGB, RRGGBB, RRGGBBAA, RGB, #RRGGBB, #RRGGBBAA
	FSlateColor a = FSlateColor(FColor::FromHex("#aaaaaa"));

	//FVector2D 


	ChildSlot
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(RubyFontInfo.textPadding)
			[
				// Ruby Text Block
				SNew(STextBlock)
				//.Font(tmp)
				.Font(rubyFont)
				.Text(RubyText)
				.ColorAndOpacity(rubyColor)
				.ShadowColorAndOpacity(RubyFontInfo.shadowColor)
				.ShadowOffset(RubyFontInfo.shadowOffset)
				//.StrikeBrush(&(RubyFont.brush))
				
			]
			+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Padding(BodyFontInfo.textPadding)
			[
				// body text block
				SNew(STextBlock)
				.Font(bodyFont)
				.Text(BodyText)
				.ColorAndOpacity(bodyColor)
				.ShadowColorAndOpacity(BodyFontInfo.shadowColor)
				.ShadowOffset(BodyFontInfo.shadowOffset)
				//.StrikeBrush(&(BodyFont.brush))
			]
		];
}



#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
