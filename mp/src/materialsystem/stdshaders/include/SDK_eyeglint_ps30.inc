#pragma once
#include "shaderlib/cshader.h"
class SDK_eyeglint_ps30_Static_Index
{
public:
	SDK_eyeglint_ps30_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_SDK_eyeglint_ps30 1


class SDK_eyeglint_ps30_Dynamic_Index
{
public:
	SDK_eyeglint_ps30_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_SDK_eyeglint_ps30 1

