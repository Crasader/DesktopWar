
#pragma once


#include "../../core/Component.h"

namespace Genius
{
	
	class ComPosition : public Component
	{
	public:
		float x;
		float y;

	public:
		ComPosition():
			x(0),
			y(0)
		{}
		ComPosition(float _x, float _y):
			x(_x),
			y(_y)
		{}
	};

};
