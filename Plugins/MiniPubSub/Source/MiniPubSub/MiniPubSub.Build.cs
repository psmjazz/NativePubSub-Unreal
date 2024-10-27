// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using Internal;
using UnrealBuildTool;

public class MiniPubSub : ModuleRules
{
	public MiniPubSub(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
			
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
				"Json",
				"JsonUtilities"
			}
			);
		
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
		
		if(Target.Platform == UnrealTargetPlatform.Android)
		{
			string uplPath = Path.Combine(ModuleDirectory, "MiniPubSub_Android_UPL.xml");
			Console.WriteLine("upl file path : " + uplPath);
			Console.WriteLine("upl file exist? " + File.Exists(uplPath));
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", uplPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicSystemLibraryPaths.Add("/usr/lib/swift");
			PublicSystemLibraryPaths.Add("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/iphoneos");
			PublicSystemLibraryPaths.Add("/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift-5.0/iphoneos");
			
			string frameworkName = "Thirdparty/iOS/MiniPubSub.framework";
			string frameworkPath = Path.Combine(ModuleDirectory, frameworkName);
			PublicAdditionalFrameworks.Add(new Framework("MiniPubSub", frameworkPath, Framework.FrameworkMode.LinkAndCopy));
		}
	}
}
