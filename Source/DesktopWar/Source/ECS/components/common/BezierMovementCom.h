
#pragma once

#include "../../core/Component.h"


namespace Genius
{
	
	class BezierMovementCom : public Component
	{
	public:
		float controlPoint1X;		// 相对startX
		float controlPoint1Y;		// 相对startY
		float controlPoint2X;		// 相对startX
		float controlPoint2Y;		// 相对startY

		float startX;
		float startY;
		float deltaX;
		float deltaY;

		float duration;
		float timePassed;

	public:
		BezierMovementCom(float _startx, float _starty, float _destx, float _desty, float _duration) :
			startX(_startx),
			startY(_starty),
			deltaX(_destx - _startx),
			deltaY(_desty - _starty),
			controlPoint1X(0),
			controlPoint1Y(100),
			controlPoint2X(_destx - _startx),
			controlPoint2Y(100),
			duration(_duration),
			timePassed(0)
		{}

		bool IsDone(){ return timePassed >= duration; }
		void Stop(){ timePassed = duration; }
	};

};
