
#pragma once

#include "../../core/IComponent.h"


namespace Genius
{
	
	class ComBezierMovement : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComBezierMovement);

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
		void Create(float _startx, float _starty, float _destx, float _desty, float _duration);
		bool IsDone(){ return timePassed >= duration; }
		void Stop(){ timePassed = duration; }
	};

};
