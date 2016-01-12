
#pragma once


#include "../../core/Component.h"

namespace Genius
{
	
	class PositionCom : public Component
	{
	public:
		float x;
		float y;

	public:
		PositionCom(float _x, float _y):
			x(_x),
			y(_y)
		{}
	};

};
