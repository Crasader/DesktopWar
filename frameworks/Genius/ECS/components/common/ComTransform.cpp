
#include "ComTransform.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComTransform);

ComTransform::ComTransform() :
x(0), y(0), vx(0), vy(0)
{

}

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

