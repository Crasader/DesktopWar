
#include "ComBezierMovement.h"


using namespace Genius;


void ComBezierMovement::Create(float _startx, float _starty, float _destx, float _desty, float _duration)
{
	startX = _startx;
	startY = _starty;
	deltaX = _destx - _startx;
	deltaY = _desty - _starty;
	controlPoint1X = 0;
	controlPoint1Y = 100;
	controlPoint2X = _destx - _startx;
	controlPoint2Y = 100;
	duration = _duration;
	timePassed = 0;
}




