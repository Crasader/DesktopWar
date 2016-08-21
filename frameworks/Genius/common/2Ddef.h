#pragma once
#include <math.h>

#define PI 3.141f
//--------------------------------------------------------------------------
// Represents a dimension in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

class Size2D
{
public:
	Size2D()
	{
		width = height = 0.0f;
	}

	Size2D(const Size2D& size)
	{
		width = size.width;
		height = size.height;
	}

	Size2D(float w, float h)
	{
		width = w;
		height = h;
	}

	Size2D operator+(const Size2D& sz) const
	{
		return Size2D(width + sz.width,
			height + sz.height);
	}

	Size2D operator-(const Size2D& sz) const
	{
		return Size2D(width - sz.width,
			height - sz.height);
	}

	bool Equals(const Size2D& sz) const
	{
		return (width == sz.width) && (height == sz.height);
	}

	bool Empty() const
	{
		return (width == 0.0f && height == 0.0f);
	}

public:

	float width;
	float height;
};

//--------------------------------------------------------------------------
// Represents a location in a 2D coordinate system (floating-point coordinates)
//--------------------------------------------------------------------------

class Point2D
{
public:
	Point2D()
	{
		x = y = 0.0f;
	}

	Point2D(const Point2D &point)
	{
		x = point.x;
		y = point.y;
	}

	Point2D(const Size2D &size)
	{
		x = size.width;
		y = size.height;
	}

	Point2D(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	Point2D(float angle)
	{
		x = cos(angle);
		y = sin(angle);
	}

	Point2D operator+(const Point2D& point) const
	{
		return Point2D(x + point.x, y + point.y);
	}

	Point2D operator-(const Point2D& point) const
	{
		return Point2D(x - point.x, y - point.y);
	}

	Point2D operator*(float number) const
	{
		return Point2D(x*number, y*number);
	}

	bool Equals(const Point2D& point)
	{
		return (x == point.x) && (y == point.y);
	}

	float	Dot(const Point2D& v) const 
	{
		return x*v.x + y*v.y; 
	}

	float	Length() const 
	{ 
		return sqrtf(Dot(*this)); 
	}

	void Normalize()
	{
		float lenRcp = Length();
		if (lenRcp)
		{
			lenRcp = 1.0f / lenRcp;
			x *= lenRcp;
			y *= lenRcp;
		}
	}

	float AngleBetween(const Point2D& point)
	{
		return 180*acos(this->Dot(point) / (this->Length()*point.Length()));
	}

public:

	float x;
	float y;
};