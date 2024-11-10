// Fill out your copyright notice in the Description page of Project Settings.

#include "Bridge/Mobile.h"

#if PLATFORM_ANDROID
#include "AndroidBridge.h"
#elif PLATFORM_IOS
#include "iOSBridge.h"
#endif


FMobile::FMobile()
{
#if PLATFORM_ANDROID
	this->Bridge = MakeShareable(new FAndroidBridge());
#elif PLATFORM_IOS
	this->Bridge = MakeShareable(new FIOSBridge());
#else
#endif
}

void FMobile::Send(const FString& Info, const FString& Data)
{
#if PLATFORM_ANDROID || PLATFORM_IOS
	this->Bridge.Get()->Send(Info, Data);
#endif
}

void FMobile::BindNative(const FDelegate_Native_Handler& Handle)
{
#if PLATFORM_ANDROID || PLATFORM_IOS
	this->Bridge->NativeHandle = Handle;
#endif
}
