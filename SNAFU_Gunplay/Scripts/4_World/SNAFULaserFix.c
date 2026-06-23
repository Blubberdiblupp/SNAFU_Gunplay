modded class SNAFU_PEQ1_Base
{
	override void DoMeasurement()
	{
		vector from = ModelToWorld(GetMemoryPointPos("beamStart"));
		vector direction;
		if (!SNAFUGetForwardLaserDirection(direction))
		{
			return;
		}
		
		vector to = from + (direction * 600.0);
		vector contact_pos;
		vector contact_dir;
		int contactComponent;
		
		bool is_collision = DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contactComponent, NULL, NULL, GetHierarchyRootPlayer(), false, false, ObjIntersectIFire);
		if (!is_collision)
		{
			return;
		}
		
		float hitDistance = vector.Distance(contact_pos, from);
		EntityAI laserDot;
		
		if (hitDistance < 6)
		{
			laserDot = EntityAI.Cast(GetGame().CreateObject("SNAFU_Laser_Dot1", contact_pos, true, false, true));
		}
		else if (hitDistance < 15)
		{
			laserDot = EntityAI.Cast(GetGame().CreateObject("SNAFU_Laser_Dot2", contact_pos, true, false, true));
		}
		else if (hitDistance < 1000)
		{
			laserDot = EntityAI.Cast(GetGame().CreateObject("SNAFU_Laser_Dot3", contact_pos, true, false, true));
		}
		
		if (laserDot)
		{
			laserDot.SetObjectTexture(0, LaserColor());
			laserDot.SetObjectMaterial(0, LaserMaterial());
			laserDot.SetPosition(contact_pos);
			laserDot.Delete();
		}
	}
	
	protected bool SNAFUGetForwardLaserDirection(out vector direction)
	{
		vector startLocal = GetMemoryPointPos("beamStart");
		vector endLocal = GetMemoryPointPos("beamEnd");
		vector startWorld = ModelToWorld(startLocal);
		vector endWorld = ModelToWorld(endLocal);
		
		direction = endWorld - startWorld;
		if (direction.LengthSq() < 0.0001)
		{
			direction = GetDirection();
		}
		
		if (direction.LengthSq() < 0.0001)
		{
			return false;
		}
		
		direction.Normalize();
		
		Weapon_Base parentWeapon = SNAFUGetParentWeapon();
		if (parentWeapon && vector.Dot(direction, parentWeapon.GetDirection()) < 0)
		{
			direction = direction * -1.0;
		}
		
		return true;
	}
	
	protected Weapon_Base SNAFUGetParentWeapon()
	{
		EntityAI parent = GetHierarchyParent();
		while (parent)
		{
			Weapon_Base weapon = Weapon_Base.Cast(parent);
			if (weapon)
			{
				return weapon;
			}
			
			parent = parent.GetHierarchyParent();
		}
		
		return null;
	}
}
