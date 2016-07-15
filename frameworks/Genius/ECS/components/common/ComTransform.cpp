
#include "ComTransform.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComTransform);

void ComTransform::SetPosition(float _x, float _y)
{
	x = _x;
	y = _y;
}
void ComTransform::SetVelocity(float _x, float _y)
{
	vx = _x;
	vy = _y;
}
void ComTransform::SetDirection(int dir)
{
	lastDir = curDir;
	curDir = dir;
}

