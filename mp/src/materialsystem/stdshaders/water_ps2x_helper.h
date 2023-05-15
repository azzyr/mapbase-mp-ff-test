//========= Copyright Valve Corporation, All rights reserved. ============//
#include "common_ps_fxc.h"

struct DrawWater_params_t
{
	float2 vBumpTexCoord;
#if MULTITEXTURE
	float4 vExtraBumpTexCoord;
#endif
	float4 vReflectXY_vRefractYX;
	float w;
	float4 vReflectRefractScale;
	float fReflectOverbright;
	float4 vReflectTint;
	float4 vRefractTint;
	half3 vTangentEyeVect;
	float4 waterFogColor;
#if BASETEXTURE
	HALF4 lightmapTexCoord1And2;
	HALF4 lightmapTexCoord3;
#endif
	float4 vProjPos;
	float4 pixelFogParams;
	float fWaterFogStart;
	float fWaterFogEndMinusStart;
	float3 vEyePos;
	float3 vWorldPos;
};

void DrawWater( in DrawWater_params_t i,
#if BASETEXTURE
	in sampler BaseTextureSampler,
	in sampler LightmapSampler,
#endif
				in sampler NormalSampler,
				in sampler RefractSampler,
				in sampler ReflectSampler,
				out float4 result, out float fogFactor )
{
	bool bReflect = REFLECT ? true : false;
	bool bRefract = REFRACT ? true : false;

#if MULTITEXTURE
	float4 vNormal  = tex2D( NormalSampler, i.vBumpTexCoord );
	float4 vNormal1 = tex2D( NormalSampler, i.vExtraBumpTexCoord.xy );
	float4 vNormal2 = tex2D( NormalSampler, i.vExtraBumpTexCoord.zw );
	vNormal = 0.33 * ( vNormal + vNormal1 + vNormal2 );

#if ( NORMAL_DECODE_MODE == NORM_DECODE_ATI2N )
	vNormal.xy = vNormal.xy * 2.0f - 1.0f;
	vNormal.z = sqrt( 1.0f - dot( vNormal.xy, vNormal.xy ) );
	vNormal.a = 1.0f;
#else
	vNormal.xyz = 2.0 * vNormal.xyz - 1.0;
#endif

#else
	float4 vNormal = DecompressNormal( NormalSampler, i.vBumpTexCoord, NORMAL_DECODE_MODE );
#endif

	// Perform division by W only once
	float ooW = 1.0f / i.w;

	float2 unwarpedRefractTexCoord = i.vReflectXY_vRefractYX.wz * ooW;

#if ABOVEWATER
	float waterFogDepthValue = tex2D( RefractSampler, unwarpedRefractTexCoord ).a;
#else
	// We don't actually have valid depth values in alpha when we are underwater looking out, so
	// just set to farthest value.
	float waterFogDepthValue = 1.0f;
#endif
	float4 reflectRefractScale = i.vReflectRefractScale;
#if !BASETEXTURE
#if ( BLURRY_REFRACT == 0 )
	reflectRefractScale *= waterFogDepthValue;
#endif
#endif

	// Compute coordinates for sampling Reflection
	float2 vReflectTexCoord;
	float2 vRefractTexCoord;

	// vectorize the dependent UV calculations (reflect = .xy, refract = .wz)
	float4 vN;
	vN.xy = vNormal.xy;
	vN.w = vNormal.x;
	vN.z = vNormal.y;
	float4 vDependentTexCoords = vN * vNormal.a * reflectRefractScale;

	vDependentTexCoords += ( i.vReflectXY_vRefractYX * ooW );
	vReflectTexCoord = vDependentTexCoords.xy;
	vRefractTexCoord = vDependentTexCoords.wz;

	HALF4 vReflectColor = tex2D( ReflectSampler, vReflectTexCoord );
#if BLURRY_REFRACT
	// Sample reflection and refraction
	float2 ddx1 = float2( 0.005, 0 );
	float2 ddy1 = float2( 0, 0.005 );
	float4 vRefractColor = float4( 0, 0, 0, 0 );

#if 0
	float sumweights = 0;
	for( int ix = -2; ix <= 2; ix++ )
	{
		for( int iy = -2; iy <= 2; iy++ )
		{
			float weight = 1; ///(1+abs(ix)+abs(iy));
			vRefractColor += weight * tex2D( RefractSampler, vRefractTexCoord + ix * ddx1 + iy * ddy1 );
			sumweights += weight;
		}
	}
#else
	// NOTE: Generated by genwaterloop.pl in the stdshaders directory.
	// Need to unroll for 360 to avoid shader compilation problems.
	// Modified genwaterloop.pl and regenerate if you need different params
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -2 * ddx1 + -2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -2 * ddx1 + -1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -2 * ddx1 + 0 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -2 * ddx1 + 1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -2 * ddx1 + 2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -1 * ddx1 + -2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -1 * ddx1 + -1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -1 * ddx1 + 0 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -1 * ddx1 + 1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + -1 * ddx1 + 2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 0 * ddx1 + -2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 0 * ddx1 + -1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 0 * ddx1 + 0 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 0 * ddx1 + 1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 0 * ddx1 + 2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 1 * ddx1 + -2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 1 * ddx1 + -1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 1 * ddx1 + 0 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 1 * ddx1 + 1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 1 * ddx1 + 2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 2 * ddx1 + -2 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 2 * ddx1 + -1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 2 * ddx1 + 0 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 2 * ddx1 + 1 * ddy1 );
	vRefractColor += tex2D( RefractSampler, vRefractTexCoord + 2 * ddx1 + 2 * ddy1 );
	float sumweights = 25;
	// NOTE: end of generated code.
#endif

	vRefractColor *= ( 1.0 / sumweights );
	vReflectColor *= i.fReflectOverbright;
	vReflectColor *= i.vReflectTint;
	vRefractColor *= i.vRefractTint;
#	if ABOVEWATER
	// Don't mess with this in the underwater case since we don't really have
	// depth values there.
	// get the blurred depth value to be used for fog.
	waterFogDepthValue = vRefractColor.a;
#	endif
#else
	vReflectColor *= i.vReflectTint;
	HALF4 vRefractColor = tex2D( RefractSampler, vRefractTexCoord );
	// get the depth value from the refracted sample to be used for fog.
#	if ABOVEWATER
	// Don't mess with this in the underwater case since we don't really have
	// depth values there.
	waterFogDepthValue = tex2D( RefractSampler, vRefractTexCoord ).a;
#	endif
#endif

	half3 vEyeVect;
	vEyeVect = normalize( i.vTangentEyeVect );

	// Fresnel term
	HALF fNdotV = saturate( dot( vEyeVect, vNormal ) );
	HALF fFresnel = pow( 1.0 - fNdotV, 5 );

#if !BASETEXTURE
	// fFresnel == 1.0f means full reflection
	fFresnel *= saturate( ( waterFogDepthValue - 0.05f ) * 20.0f );
#endif


	// blend between refraction and fog color.
#if ABOVEWATER
	vRefractColor = lerp( vRefractColor, i.waterFogColor * LINEAR_LIGHT_SCALE, saturate( waterFogDepthValue - 0.05f ) );
#else
	float waterFogFactor = saturate( ( i.vProjPos.z - i.fWaterFogStart ) / i.fWaterFogEndMinusStart );
	vRefractColor = lerp( vRefractColor, i.waterFogColor * LINEAR_LIGHT_SCALE, waterFogFactor );
#endif

#if BASETEXTURE
	float4 baseSample = tex2D( BaseTextureSampler, i.vBumpTexCoord.xy );
	HALF2 bumpCoord1;
	HALF2 bumpCoord2;
	HALF2 bumpCoord3;
	ComputeBumpedLightmapCoordinates( i.lightmapTexCoord1And2, i.lightmapTexCoord3.xy,
									  bumpCoord1, bumpCoord2, bumpCoord3 );

	HALF4 lightmapSample1 = tex2D( LightmapSampler, bumpCoord1 );
	HALF3 lightmapColor1 = lightmapSample1.rgb;
	HALF3 lightmapColor2 = tex2D( LightmapSampler, bumpCoord2 );
	HALF3 lightmapColor3 = tex2D( LightmapSampler, bumpCoord3 );

	float3 dp;
	dp.x = saturate( dot( vNormal, bumpBasis[0] ) );
	dp.y = saturate( dot( vNormal, bumpBasis[1] ) );
	dp.z = saturate( dot( vNormal, bumpBasis[2] ) );
	dp *= dp;

	float3 diffuseLighting = dp.x * lightmapColor1 +
							 dp.y * lightmapColor2 +
							 dp.z * lightmapColor3;
	float sum = dot( dp, float3( 1.0f, 1.0f, 1.0f ) );
	diffuseLighting *= LIGHT_MAP_SCALE / sum;
	HALF3 diffuseComponent = baseSample.rgb * diffuseLighting;
#endif

	if( bReflect && bRefract )
	{
		result = lerp( vRefractColor, vReflectColor, fFresnel );
	}
	else if( bReflect )
	{
#if BASETEXTURE
		result = float4( diffuseComponent, 1.0f ) + vReflectColor * fFresnel * baseSample.a;
#else
		result = vReflectColor;
#endif
	}
	else if( bRefract )
	{
		result = vRefractColor;
	}
	else
	{
		result = float4( 0.0f, 0.0f, 0.0f, 0.0f );
	}

#if (PIXELFOGTYPE == PIXEL_FOG_TYPE_RANGE)
	fogFactor = CalcRangeFogFactorNonFixedFunction( i.vWorldPos, i.vEyePos, i.pixelFogParams.z, i.pixelFogParams.x, i.pixelFogParams.w );
#else
	fogFactor = 0;
#endif
}
