
#pragma once

#include "../../core/IComponent.h"

namespace Genius
{
	enum FaceType
	{
		Face_Min = 1 << 0,
		Face_Left = 1 << 1,
		Face_Right = 1 << 2,
		Face_Up = 1 << 3,
		Face_Down = 1 << 4,
		Face_Turn = 1 << 5,
		Face_Max = 1 << 6,
	};

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
		int GetDir(){ return curDir; }
		void MoveTo(float x, float y, float speed);
		void MoveTowards(float angle, float speed);

	private:
		int CalculateDirection(float x, float y);
	};
	
};