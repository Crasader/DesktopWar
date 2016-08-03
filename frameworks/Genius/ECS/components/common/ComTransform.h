
#pragma once

#include "../../core/IComponent.h"

namespace Genius
{

	class ComTransform : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComTransform);

	public:
		float x;
		float y;
		float vx;
		float vy;
		int curDir;
		int lastDir;

	public:
		ComTransform();
		void SetPosition(float _x, float _y);
		void SetVelocity(float _x, float _y);
		void SetDirection(int dir);
		float GetX(){ return x; }
		float GetY(){ return y; }
		float GetVX(){ return vx; }
		float GetVY(){ return vy; }
		void MoveTo(float x, float y, float speed);
		void MoveTowards(float angle, float speed);
	};
	
};