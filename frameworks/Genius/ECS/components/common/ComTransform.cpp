
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
	if (dir != curDir)
	{
		lastDir = curDir;
		curDir = dir;
	}
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
	int dir = CalculateDirection(_x-x, _y-y);
	SetDirection(dir);
}

void ComTransform::MoveTowards(float angle, float speed)
{
	angle = angle / 180 * PI;
	Point2D pt2d(angle);
	this->vx = pt2d.x * speed;
	this->vy = pt2d.y * speed;
	int dir = CalculateDirection(pt2d.x, pt2d.y);
	SetDirection(dir);
}

int ComTransform::CalculateDirection(float x, float y)
{
	float absTan = 2.0f;
	int dir = this->curDir;
	if (x == 0.0f)
	{
		if (y == 0.0f)
		{
			dir = dir;
		}
		else if (y > 0.0f)
		{
			dir = Face_Up;
		}
		else // < 0
		{
			dir = Face_Down;
		}
	}
	else if (x > 0.0f)
	{
		float tan = y / x;
		if (tan > absTan)
			dir = Face_Up | Face_Right;
		else if (tan > -absTan && tan <= absTan)
			dir = Face_Right;
		else
			dir = Face_Down | Face_Right;
	}
	else// vec.x < 0.0f
	{
		float tan = y / x;
		if (tan > absTan)
			dir = Face_Down | Face_Left;
		else if (tan > -absTan && tan <= absTan)
			dir = Face_Left;
		else
			dir = Face_Up | Face_Left;
	}
	return dir;
}
