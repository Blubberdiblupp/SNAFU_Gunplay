modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		SNAFUGetAdminConfig();
		GetRPCManager().AddRPC("SNAFUGunplayAdmin", "RPCSNAFUGunplayAdminSettings", this, SingeplayerExecutionType.Both);
	}
	
	void RPCSNAFUGunplayAdminSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		PlayerIdentity requestedBy = PlayerIdentity.Cast(sender);
		if (!requestedBy)
		{
			return;
		}
		
		GetRPCManager().SendRPC("SNAFUGunplayAdmin", "RPCSNAFUGunplayAdminSettings", new Param1<SNAFUGunplayAdminConfig>(SNAFUGetAdminConfig()), true, requestedBy);
	}
}

modded class MissionGameplay extends MissionBase
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("SNAFUGunplayAdmin", "RPCSNAFUGunplayAdminSettings", this, SingeplayerExecutionType.Both);
	}
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("SNAFUGunplayAdmin", "RPCSNAFUGunplayAdminSettings", new Param1<SNAFUGunplayAdminConfig>(NULL), true, NULL);
	}
	
	void RPCSNAFUGunplayAdminSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		Param1<SNAFUGunplayAdminConfig> data;
		if (!ctx.Read(data))
		{
			return;
		}
		
		SNAFUSetAdminConfig(data.param1);
		Print("[SNAFU Gunplay] Admin settings received from server");
	}
}
