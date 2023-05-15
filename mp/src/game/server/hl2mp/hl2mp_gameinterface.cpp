//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#include "cbase.h"
#include "gameinterface.h"
#include "mapentities.h"
#include "hl2mp_gameinterface.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// -------------------------------------------------------------------------------------------- //
// Mod-specific CServerGameClients implementation.
// -------------------------------------------------------------------------------------------- //
void CServerGameClients::GetPlayerLimits( int& minplayers, int& maxplayers, int& defaultMaxPlayers ) const
{
	minplayers = 1; // Allow Singleplayer mode
	maxplayers = defaultMaxPlayers = MAX_PLAYERS;
}

// -------------------------------------------------------------------------------------------- //
// Mod-specific CServerGameDLL implementation.
// -------------------------------------------------------------------------------------------- //
void CServerGameDLL::LevelInit_ParseAllEntities( const char* pMapEntities )
{
}

