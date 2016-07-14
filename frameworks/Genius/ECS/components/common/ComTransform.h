
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

	public:
		void SetPosition(float _x, float _y);
		void SetVelocity(float _x, float _y);
		void SetDirection(int dir);

	};
	
};