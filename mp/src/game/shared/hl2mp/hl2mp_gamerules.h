//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================//

#ifndef HL2MP_GAMERULES_H
#define HL2MP_GAMERULES_H
#pragma once

#include "gamerules.h"
#include "hl2_gamerules.h"
#include "teamplay_gamerules.h"
#include "gamevars_shared.h"

#ifndef CLIENT_DLL
	#include "hl2mp_player.h"
#endif

#define VEC_CROUCH_TRACE_MIN	HL2MPRules()->GetHL2MPViewVectors()->m_vCrouchTraceMin
#define VEC_CROUCH_TRACE_MAX	HL2MPRules()->GetHL2MPViewVectors()->m_vCrouchTraceMax

enum
{
	TEAM_COMBINE = 2,
	TEAM_REBELS,
};


#ifdef CLIENT_DLL
	#define CHL2MPRules C_HL2MPRules
	#define CHL2MPGameRulesProxy C_HL2MPGameRulesProxy
#endif

class CHL2MPGameRulesProxy : public CHalfLife2Proxy
{
public:
	DECLARE_CLASS( CHL2MPGameRulesProxy, CHalfLife2Proxy );
	DECLARE_NETWORKCLASS();
};

class HL2MPViewVectors : public CViewVectors
{
public:
	HL2MPViewVectors(
		Vector vView,
		Vector vHullMin,
		Vector vHullMax,
		Vector vDuckHullMin,
		Vector vDuckHullMax,
		Vector vDuckView,
		Vector vObsHullMin,
		Vector vObsHullMax,
		Vector vDeadViewHeight,
		Vector vCrouchTraceMin,
		Vector vCrouchTraceMax ) :
		CViewVectors(
			vView,
			vHullMin,
			vHullMax,
			vDuckHullMin,
			vDuckHullMax,
			vDuckView,
			vObsHullMin,
			vObsHullMax,
			vDeadViewHeight )
	{
		m_vCrouchTraceMin = vCrouchTraceMin;
		m_vCrouchTraceMax = vCrouchTraceMax;
	}

	Vector m_vCrouchTraceMin;
	Vector m_vCrouchTraceMax;
};

class CHL2MPRules : public CHalfLife2
{
public:
	DECLARE_CLASS( CHL2MPRules, CHalfLife2 );

#ifdef CLIENT_DLL
	DECLARE_CLIENTCLASS_NOBASE(); // This makes datatables able to access our private vars.
#else
	DECLARE_SERVERCLASS_NOBASE(); // This makes datatables able to access our private vars.
#endif

	CHL2MPRules();
	virtual ~CHL2MPRules();

	virtual void Precache( void );
	virtual bool ShouldCollide( int collisionGroup0, int collisionGroup1 );
	virtual bool ClientCommand( CBaseEntity* pEdict, const CCommand& args );

	virtual float FlWeaponRespawnTime( CBaseCombatWeapon* pWeapon );
	virtual float FlWeaponTryRespawn( CBaseCombatWeapon* pWeapon );
	virtual Vector VecWeaponRespawnSpot( CBaseCombatWeapon* pWeapon );
	virtual QAngle DefaultWeaponRespawnAngle( CBaseCombatWeapon* pWeapon );
	virtual int WeaponShouldRespawn( CBaseCombatWeapon* pWeapon );
	virtual void Think( void );
	virtual void CreateStandardEntities( void );
	virtual void ClientSettingsChanged( CBasePlayer* pPlayer );
	virtual int PlayerRelationship( CBaseEntity* pPlayer, CBaseEntity* pTarget );
	virtual void GoToIntermission( void );
	virtual void DeathNotice( CBasePlayer* pVictim, const CTakeDamageInfo& info );
	virtual const char* GetGameDescription( void );
	// derive this function if you mod uses encrypted weapon info files
	virtual const unsigned char* GetEncryptionKey( void )
	{
		return ( unsigned char* )"x9Ke0BY7";
	}
	virtual const CViewVectors* GetViewVectors() const;
	const HL2MPViewVectors* GetHL2MPViewVectors() const;

	float GetMapRemainingTime();
	void CleanUpMap();
	void CheckRestartGame();
	void RestartGame();

#ifndef CLIENT_DLL
	virtual Vector VecItemRespawnSpot( CItem* pItem );
	virtual QAngle VecItemRespawnAngles( CItem* pItem );
	virtual float	FlItemRespawnTime( CItem* pItem );
	virtual bool	CanHavePlayerItem( CBasePlayer* pPlayer, CBaseCombatWeapon* pItem );
	virtual bool FShouldSwitchWeapon( CBasePlayer* pPlayer, CBaseCombatWeapon* pWeapon );

	void	AddLevelDesignerPlacedObject( CBaseEntity* pEntity );
	void	RemoveLevelDesignerPlacedObject( CBaseEntity* pEntity );
	void	ManageObjectRelocation( void );
	const char* GetChatFormat( bool bTeamOnly, CBasePlayer* pPlayer );

#ifdef ENABLE_BOTS
	virtual void PlayerSpawn( CBasePlayer* pPlayer );
#endif // ENABLE_BOTS

#ifdef MAPBASE_MP
	virtual void GetTaggedConVarList( KeyValues* pCvarTagList );
#endif // MAPBASE_MP

#endif
	virtual void ClientDisconnected( edict_t* pClient );

	bool CheckGameOver( void );
	bool IsIntermission( void );

	void PlayerKilled( CBasePlayer* pVictim, const CTakeDamageInfo& info );


	bool	IsTeamplay( void )
	{
		return m_bTeamPlayEnabled;
	}

	virtual bool IsConnectedUserInfoChangeAllowed( CBasePlayer* pPlayer );

	float CheckFragLimit();

private:

	CNetworkVar( bool, m_bTeamPlayEnabled );
	CNetworkVar( float, m_flGameStartTime );
	CUtlVector<EHANDLE> m_hRespawnableItemsAndWeapons;
	float m_tmNextPeriodicThink;
	float m_flRestartGameTime;
	bool m_bCompleteReset;

#ifndef CLIENT_DLL
	bool m_bChangelevelDone;
#endif
};

inline CHL2MPRules* HL2MPRules()
{
	return static_cast<CHL2MPRules*>( g_pGameRules );
}

#endif //HL2MP_GAMERULES_H
