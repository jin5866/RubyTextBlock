// Fill out your copyright notice in the Description page of Project Settings.


#include "RubyTextBlockDecorator.h"
#include "Slate.h"
#include "SRubyTextSlate.h"

class FRubyText : public FRichTextDecorator
{
public:
	FRubyText(URichTextBlock* InOwner, URubyTextBlockDecorator* InDecorator)
		: FRichTextDecorator(InOwner), Decorator(InDecorator)
	{

	}
	virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override
	{
		if (RunParseResult.Name == TEXT("Ruby") && RunParseResult.MetaData.Contains(TEXT("text"))) 
		{
			return true;
		}
		return false;
	}
	virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo, const FTextBlockStyle& TextStyle) const override
	{
		return SNew(SRubyTextSlate, RunInfo.MetaData.Find(TEXT("text")), RunInfo.Content);
	}

private:
	URubyTextBlockDecorator* Decorator;
};


URubyTextBlockDecorator::URubyTextBlockDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) 
{

}

TSharedPtr<ITextDecorator> URubyTextBlockDecorator::CreateDecorator(URichTextBlock* InOwner)
{
	return MakeShareable(new FRubyText(InOwner, this));
}
