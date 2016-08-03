
#include "ComTransform.h"
#include "2Ddef.h"


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

void ComTransform::MoveTo(float _x, float _y, float speed)
{
	float dx = _x - this->x;
	float dy = _y - this->y;
	Point2D delta(dx, dy);
	delta.Normalize();
	if (speed <= 0)
		speed = 1;
	this->vx = delta.x * speed;
	this->vy = delta.y * speed;
}

void ComTransform::MoveTowards(float angle, float speed)
{
	Point2D pt2d(angle);
	this->vx = pt2d.x * speed;
	this->vy = pt2d.y * speed;
}


