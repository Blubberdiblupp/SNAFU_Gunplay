SNAFU_Gunplay / AJ_Gunplay Admin Config Guide
============================================

This guide explains how to edit the generated JSON config files for SNAFU_Gunplay and AJ_Gunplay.

Config file locations
---------------------

SNAFU_Gunplay:
$profile:\SNAFU_Gunplay\SNAFU_Gunplay.json

AJ_Gunplay:
$profile:\AJ_Gunplay\AJ_Gunplay.json

The config is loaded on server start. Changes are not applied live while the server is running.
After editing a JSON file, restart the server.


Config version and updates
--------------------------

ConfigVersion:
Current config version. At the moment this should be 1.

Do not manually increase ConfigVersion.

When the mod is updated, missing default entries are added automatically on the next server start.
Existing admin edits are preserved.

If a future mod update requires a real config migration, the mod will update ConfigVersion automatically.

If a server used an older mod version that did not generate a JSON file yet, there is no migration needed.
The JSON file will be created with defaults on first server start.


Which JSON should I edit?
-------------------------

Edit the JSON of the mod that owns the item you want to balance.

If only AJ_Gunplay is loaded:
- AJ_Gunplay controls AJ, Vanilla, and Expansion gunplay values.

If SNAFU_Gunplay and AJ_Gunplay are loaded together:
- SNAFU_Gunplay controls Vanilla, Expansion, and SNAFU items.
- AJ_Gunplay controls AJ-specific items such as AJW_... and AJs_...

SNAFU_Gunplay does not copy custom values from AJ_Gunplay.json.
AJ_Gunplay does not copy custom values from SNAFU_Gunplay.json.

If you previously changed Vanilla or Expansion values in AJ_Gunplay.json and later add SNAFU_Gunplay, copy those Vanilla/Expansion changes manually into SNAFU_Gunplay.json.


Important value rules
---------------------

Most gunplay values are multipliers.

Recoil:
- Lower than 1.0 = less recoil / better
- Higher than 1.0 = more recoil / worse

Sway:
- Lower than 1.0 = less sway / better
- Higher than 1.0 = more sway / worse

ADS:
- Higher than 1.0 = faster ADS / better
- Lower than 1.0 = slower ADS / worse

Precision:
- Higher than 1.0 = more precision / better
- Lower than 1.0 = less precision / worse

HipFire:
- Lower than 1.0 = tighter hip-fire / better
- Higher than 1.0 = worse hip-fire / worse


Main config options
-------------------

ConfigVersion:
Do not edit this manually.
It is used by the mod to handle future config updates.

CrosshairMode:
0 = use vanilla behavior
1 = dynamic weapon-barrel aligned crosshair
2 = dynamic weapon-barrel aligned crosshair only when a laser is attached

EnableTooltipStats:
Shows gunplay stats in inventory tooltips.

EnableInspectStats:
Shows gunplay stats in the inspect view.

EnableExpansionMarketStats:
Shows gunplay stats in the Expansion Market view.

EnableHipFireNerf:
Enables the hip-fire balancing changes.

EnableWeaponGeometryDamage:
Enables weapon geometry/damage behavior from the mod.

DebugMode:
Only enable this when you need extra debugging.

GlobalRecoilMultiplier:
Global multiplier applied to recoil behavior.

GlobalSwayMultiplier:
Global multiplier applied to sway behavior.

GlobalAimSpeedMultiplier:
Global multiplier applied to ADS behavior.

GlobalHipFireMultiplier:
Global multiplier applied to hip-fire behavior.

GlobalPrecisionMultiplier:
Global multiplier applied to precision behavior.

HighCapMagazineThreshold:
Magazine capacity above this number is treated as high-capacity.


AttachmentTierOverrides
-----------------------

This list assigns item class names to a tier.

Example:

{
    "ClassName": "FGRIP",
    "TierKey": "Foregrip_T1"
}

You can move an item to another tier:

{
    "ClassName": "FGRIP",
    "TierKey": "Foregrip_T2"
}

After a restart, FGRIP will use the Foregrip_T2 tier values, unless you also changed its individual values in AttachmentStatOverrides.

Common tier keys include:

Foregrip_T1
Foregrip_T2
Foregrip_T3
PistolGrip_T1
PistolGrip_T2
PistolGrip_T3
Stock_T1
Stock_T2
Stock_T3
Handguard_T1
Handguard_T2
Handguard_T3
Bipod_Special
LightOptic_T1
HeavyOptic_T2
SniperOptic_T3
Laser_Tactical
Flashlight_Utility
Bayonet_Heavy
Muzzle_T1
Muzzle_T2
Muzzle_T3
Suppressor_T1
Suppressor_T2
Suppressor_T3
WeaponWrap_Utility
StandardMag_Neutral
HighCap_Heavy
Neutral


TierMultiplierOverrides
-----------------------

This list changes an entire tier group.

Default values are 1.0, meaning no extra change.

Example:

{
    "TierKey": "Foregrip_T1",
    "Recoil": 0.9,
    "Sway": 0.9,
    "ADS": 1.0,
    "Precision": 1.0,
    "HipFire": 1.0
}

This makes every Foregrip_T1 item slightly better for recoil and sway.

Use TierMultiplierOverrides when you want to adjust a full category or tier without editing every single item.


AttachmentStatOverrides
-----------------------

This list shows the default gunplay values for each known item.
These values are the mod's own SNAFU_Gunplay or AJ_Gunplay balancing values, not the original weapon mod config.cpp values.

Example:

{
    "ClassName": "FGRIP",
    "Category": "Foregrip",
    "Tier": "T1",
    "Recoil": 0.699999988079071,
    "Sway": 0.925000011920929,
    "ADS": 1.0299999713897706,
    "Precision": 1.0499999523162842,
    "HipFire": 0.8999999761581421
}

You can edit these values directly if you want one specific item to behave differently.

Example:

{
    "ClassName": "FGRIP",
    "Category": "Foregrip",
    "Tier": "Custom",
    "Recoil": 0.5,
    "Sway": 0.85,
    "ADS": 1.05,
    "Precision": 1.10,
    "HipFire": 0.80
}

After a restart, FGRIP will use these exact item-specific values.


Which method should I use?
--------------------------

Use AttachmentTierOverrides if:
- You want to move an item from Tier 1 to Tier 2 or Tier 3.
- You want the item to use the normal values of another tier.

Use TierMultiplierOverrides if:
- You want to buff or nerf a whole tier group.
- Example: make all Tier 1 foregrips slightly better.

Use AttachmentStatOverrides if:
- You want to tune one specific item exactly.
- Example: make only FGRIP stronger without changing other foregrips.


Recommended workflow
--------------------

1. Stop the server.
2. Edit the JSON file.
3. Save the JSON file.
4. Start the server again.
5. Join and inspect the item in-game to confirm the displayed values.

If the server is running while you edit the file, the changes will not be applied until the next restart.


JSON formatting notes
---------------------

Keep valid JSON formatting.

Do not remove commas between entries.
Do not add comments inside the JSON file.
Do not rename ClassName unless you know the exact DayZ item class name.
Do not rename TierKey unless that tier exists in the config.

If the JSON is broken, restore the last working version or delete the JSON file and restart the server to regenerate defaults.
Deleting the JSON will also remove your custom admin edits.


Short rule
----------

Edit the JSON of the mod that owns the item.
Restart the server.
Check the item stats in-game.
