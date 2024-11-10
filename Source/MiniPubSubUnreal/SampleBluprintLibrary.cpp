// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleBluprintLibrary.h"

#include "JsonObjectConverter.h"
#include "Data/Message.h"
#include "Public/NativeManager.h"
#include "PubSub/Messenger.h"

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
	 
	TMessage MessageBase = TMessage(TEXT("this_is_key"), Test);
	
	FString Json = MessageBase.Json;
	UE_LOG(LogTemp, Display, TEXT("Message json : %s"), *Json)
}

void USampleBluprintLibrary::PubSubTest()
{
	// FMessenger Messenger1 = FMessenger();
	// FMessenger Messenger2 = FMessenger();
	//
	// Messenger1.Subscribe(TEXT("M2"), FReceiveDelegate::CreateLambda([](const FMessage& Message)
	// {
	// 	TMessage<FTest> TestMessage = TMessage<FTest>(Message);
	// 	UE_LOG(LogTemp, Display, TEXT("from Messenger2 replay -  key : %s   data.str : %s    data.integer : %d"), *TestMessage.Info.Key, *TestMessage.Data().str, TestMessage.Data().integer)
	// }));
	//
	// Messenger2.Subscribe(TEXT("M1"), FReceiveDelegate::CreateLambda([Messenger2](const FMessage& Message)
	// {
	// 	TMessage<FTest> TestMessage = TMessage<FTest>(Message);
	// 	UE_LOG(LogTemp, Display, TEXT("Messenger1 sends -  key : %s   data.str : %s    data.integer : %d"), *TestMessage.Info.Key, *TestMessage.Data().str, TestMessage.Data().integer)
	//
	// 	FTest T2 = FTest{ TEXT("T2Message"), 999999};
	// 	Messenger2.Publish(TMessage<FTest>(TEXT("M2"), T2));
	// }));
	//
	//
	// FTest T1 = FTest{ TEXT("T1Message"), 100};
	// Messenger1.Publish(TMessage<FTest>(TEXT("M1"), T1));
	//
	// Messenger1.Unsubscribe(TEXT("M2"));
	// Messenger2.Unsubscribe(TEXT("M1"));
}

void USampleBluprintLibrary::PubSubInitTest()
{
	UE_LOG(LogTemp, Display, TEXT("PubSubInitTest!!"))
	UNativeManager* NativeManager = UNativeManager::Get(); 
	if(IsValid(NativeManager))
	{
		NativeManager->InitNativePubSub();
	}
	UE_LOG(LogTemp, Display, TEXT("PubSubInitTest end!!"))
}

void USampleBluprintLibrary::SendNativeTest(const FToastData& Data)
{
	UNativeManager* NativeManager = UNativeManager::Get();
	if(IsValid(NativeManager))
	{
		NativeManager->ShowToast(Data);
	}
}
