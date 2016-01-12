
#pragma once

#include "../../core/Component.h"

namespace Genius
{

	class VelocityCom : public Component
	{
	public:
		float x;
		float y;

	public:
		VelocityCom(float _x, float _y) :
			x(_x),
			y(_y)
		{}
	};
	
};