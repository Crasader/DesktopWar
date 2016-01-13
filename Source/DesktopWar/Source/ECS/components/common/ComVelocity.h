
#pragma once

#include "../../core/Component.h"

namespace Genius
{

	class ComVelocity : public Component
	{
	public:
		float x;
		float y;

	public:
		ComVelocity(float _x, float _y) :
			x(_x),
			y(_y)
		{}
	};
	
};