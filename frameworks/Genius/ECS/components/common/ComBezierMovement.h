
#pragma once

#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComBezierMovement : public IComponent
	{
	public:
		float controlPoint1X;		// ���startX
		float controlPoint1Y;		// ���startY
		float controlPoint2X;		// ���startX
		float controlPoint2Y;		// ���startY

		float startX;
		float startY;
		float deltaX;
		float deltaY;

		float duration;
		float timePassed;

	public:
		void Create(float _startx, float _starty, float _destx, float _desty, float _duration);
		bool IsDone(){ return timePassed >= duration; }
		void Stop(){ timePassed = duration; }
	};

};
