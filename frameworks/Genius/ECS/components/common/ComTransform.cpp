
#include "ComTransform.h"

using namespace Genius;


void ComTransform::Create(float _x, float _y, float _vx, float _vy, int _dir)
{
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	curDir = _dir;
	lastDir = 0;
}

