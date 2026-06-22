class CfgVehicles
{
	class Inventory_Base;
	
	class Gunplay_WeaponRepairKit: Inventory_Base
	{
		scope = 2;
		displayName = "Weapon Repair Kit";
		descriptionShort = "A specialized kit for repairing firearms and suppressors. Can restore ruined weapons to pristine condition.";
		model = "\DZ\weapons\attachments\supressors\universal_suppressor05.p3d";
		
		rotationFlags = 17;
		weight = 500;
		itemSize[] = {3, 2};
		inventorySlot[] = {"ShoulderMagazine"};
		stackedUnit = "pieces";
		quantityBar = 0;
		carveNavmesh = 0;
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0, {"DZ\weapons\attachments\supressors\data\universal_suppressor05.rvmat"}},
						{0.7, {"DZ\weapons\attachments\supressors\data\universal_suppressor05.rvmat"}},
						{0.5, {"DZ\weapons\attachments\supressors\data\universal_suppressor05_damage.rvmat"}},
						{0.3, {"DZ\weapons\attachments\supressors\data\universal_suppressor05_damage.rvmat"}},
						{0.0, {"DZ\weapons\attachments\supressors\data\universal_suppressor05_destruct.rvmat"}}
					};
				};
			};
		};
		
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpGear_Light_SoundSet";
					id = 79650;
				};
				class pickUpItem
				{
					soundSet = "pickUpGear_SoundSet";
					id = 79651;
				};
			};
		};
		
		nutrientIndex = 0;
		
		class SkinnedMesh
		{
			class SkinnedMesh
			{
				name = "damage";
				value = 0;
			};
		};
		
		lootCategory = "Tools";
		lootTag = "Work";
	};
};

class CfgSlots
{
	class Slot_Shotgunshell
	{
		name = "Shotgunshell";
		displayName = "Shotgun Shell";
		ghostIcon = "set:dayz_inventory image:cartridge";
	};
};
