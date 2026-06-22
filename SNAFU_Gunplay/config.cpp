class CfgPatches
{
	class SNAFU_Gunplay
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Muzzles",
			"DZ_Weapons_Optics",
			"DZ_Weapons_Supports",
			"SNAFU_Scripts",
			"SNAFU_WW2",
			"SNAFU_Guns",
			"SNAFU_Guns_01",
			"SNAFU_Guns_02",
			"SNAFU_Guns_03",
			"SNAFU_Guns_05",
			"SNAFU_Guns_06",
			"SNAFU_Scopes"
		};
	};
	
	class SNAFU_Gunplay_Items
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = {"DZ_Data", "DZ_Weapons_Muzzles"};
	};
};

class CfgMods
{
	class SNAFU_Gunplay
	{
		dir = "SNAFU_Gunplay";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "SNAFU Gunplay Overhaul";
		credits = "SNAFU Gunplay Team";
		author = "SNAFU Gunplay Team";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"SNAFU_Gunplay/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"SNAFU_Gunplay/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"SNAFU_Gunplay/Scripts/5_Mission"};
			};
		};
	};
};
