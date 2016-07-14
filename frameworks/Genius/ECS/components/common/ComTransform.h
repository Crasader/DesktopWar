
#pragma once

#include "../../core/IComponent.h"

namespace Genius
{

	class ComTransform : public IComponent
	{
	public:
		float x;
		float y;
		float vx;
		float vy;
		int curDir;
		int lastDir;

		void Create(float _x, float _y, float _vx, float _vy, int _dir);

	};
	
};