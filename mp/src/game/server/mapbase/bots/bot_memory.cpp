//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
// Authors:
// Iv�n Bravo Bravo (linkedin.com/in/ivanbravobravo), 2017

#include "cbase.h"
#include "bot.h"
#include "in_utils.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

extern ConVar bot_primary_attack;

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CBot::SetPeaceful( bool enabled )
{
	if( !GetMemory() )
	{
		return;
	}

	if( enabled )
	{
		GetMemory()->Disable();
	}
	else
	{
		GetMemory()->Enable();
	}
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CBaseEntity* CBot::GetEnemy() const
{
	if( !GetMemory() )
	{
		return NULL;
	}

	return GetMemory()->GetEnemy();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CEntityMemory* CBot::GetPrimaryThreat() const
{
	if( !GetMemory() )
	{
		return NULL;
	}

	return GetMemory()->GetPrimaryThreat();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CBot::SetEnemy( CBaseEntity* pEnemy, bool bUpdate )
{
	if( !GetMemory() )
	{
		return;
	}

	return GetMemory()->SetEnemy( pEnemy, bUpdate );
}
