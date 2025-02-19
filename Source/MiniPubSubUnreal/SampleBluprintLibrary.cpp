// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleBluprintLibrary.h"

#include "JsonObjectConverter.h"
#include "Data/Message.h"
#include "Public/NativeManager.h"
#include "PubSub/Messenger.h"


FNativeManager GNativeManager = FNativeManager();
void USampleBluprintLibrary::PubSubInitTest()
{
	UE_LOG(LogTemp, Display, TEXT("PubSubInitTest!!"))
	if(!GNativeManager.IsInitialized())
	{
		GNativeManager.Initialize();
		GNativeManager.InitNativePubSub();
	}
	UE_LOG(LogTemp, Display, TEXT("PubSubInitTest end!!"))
}

void USampleBluprintLibrary::SendNativeTest(const FToastData& Data)
{
	if(GNativeManager.IsInitialized())
	GNativeManager.ShowToast(Data);
}
