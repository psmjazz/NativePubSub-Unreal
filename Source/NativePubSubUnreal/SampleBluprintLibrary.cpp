// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleBluprintLibrary.h"

#include "JsonObjectConverter.h"
#include "MyTester.h"
#include "Data/Message.h"

void USampleBluprintLibrary::CallNativeTest(const FString& Text)
{
	// UE_LOG(LogTemp, Warning, TEXT("Native Test Called! %s"), *Text);
	// FMyTester::CallTest(Text);
}

void USampleBluprintLibrary::CallBytesTest(const TArray<uint8>& Bytes)
{
	// UE_LOG(LogTemp, Warning, TEXT("Byte Test Called! %s"), Bytes.GetData());
	// auto b = Bytes.GetData();
	// const TArray<char> CharArray(Bytes);
	// FMyTester::CallByteTest(CharArray);
}

void USampleBluprintLibrary::JsonTest()
{
	// FString TestJson = TEXT("{\"str\":\"json to object\", \"integer\":123}");
	// FTest Test;
	// FJsonObjectConverter::JsonObjectStringToUStruct(TestJson, &Test);
	//
	// UE_LOG(LogTemp, Display, TEXT("json -> Ustruct test : str - %s, integer - %d"), *Test.str, Test.integer)
	//
	// FTest Test2{"object to json",10000};
	// FString TestJson2;
	// FJsonObjectConverter::UStructToJsonObjectString(Test2, TestJson2);
	// UE_LOG(LogTemp, Display, TEXT("Ustruct -> json test : %s"), *TestJson2)
	
}

void USampleBluprintLibrary::MyTest()
{
	FTest Test = FTest();
	Test.str = TEXT("hi");
	Test. integer = 1234;
	 
	TSharedPtr<const FMessage> MessageBase = TMessage<FTest>::Create(TEXT("this_is_key"), Test); // MakeShareable(new TMessage(TEXT("this_is_key"), Test));

	FTest  *const t = new FTest();
	t->integer = 1;
	TSharedPtr<const TMessage<FTest>> MessageConverted = TMessage<FTest>::Convert(MessageBase);
	UE_LOG(LogTemp, Display, TEXT("STTMessage key : %s    data.str : %s    data.integer : %d"), *MessageConverted->Key, *MessageConverted->Data().str, MessageConverted->Data().integer)

	FString Json = MessageBase->ToString();
	UE_LOG(LogTemp, Display, TEXT("Message json : %s"), *Json)
	
	TSharedPtr<const FMessage> MessageFromJson = FMessage::ParseFrom(Json);
	TSharedPtr<const TMessage<FTest>> MessageConvertedFromJson = TMessage<FTest>::Convert(MessageFromJson);
	UE_LOG(LogTemp, Display, TEXT("STTMessage2 key : %s    data.str : %s    data.integer : %d"), *MessageConvertedFromJson->Key, *MessageConvertedFromJson->Data().str, MessageConvertedFromJson->Data().integer)
	
}
