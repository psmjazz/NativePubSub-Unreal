// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;

public class MiniPubSubUnreal : ModuleRules
{
	public MiniPubSubUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PublicDependencyModuleNames.AddRange(new string[] { "MiniPubSub" });
		
		PrivateDependencyModuleNames.AddRange(new []{"Json", "JsonUtilities"});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string uplPath = Path.Combine(ModuleDirectory, "MiniPubSubUnreal_Android_UPL.xml");
			Console.WriteLine("upl file path : " + uplPath);
			Console.WriteLine("upl file exist? " + File.Exists(uplPath));
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", uplPath);
		}
		else if(Target.Platform == UnrealTargetPlatform.IOS)
        {
	        // PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty/iOS"));
	        
	        string frameworkName = "Thirdparty/iOS/sample-1.0.embeddedframework.zip";
	        string frameworkPath = Path.Combine(ModuleDirectory, frameworkName);
	        PublicAdditionalFrameworks.Add(new Framework("sample", frameworkPath));
		}
	}
}
