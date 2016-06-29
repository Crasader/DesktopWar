#pragma once
#include <math.h>

class RandUtility
{
public:

	// [start, end)
	static int RandBetween(int start, int end)
	{
		return start + rand() % (end - start);
	}

	// [start, end)
	static float RandProbablity()
	{
		return RandBetween(0, 100)*0.01f;
	}

	static float RandomScale(float original, float scale)
	{
		return original*(1.0f + 2.f*scale*RandBetween(-50, 50) / 100.f);
	}

};
 