
#pragma once


#include "../../core/Component.h"
#include "../../core/Entity.h"

namespace Genius
{
	
	class ComTarget : public Component
	{
	public:
		int		targetType;
		int		targetID;
		float		targetX;
		float		targetY;

	public:
		ComTarget(int _type, int _id = Entity::InvalidID, float _x = 0, float _y = 0) :
			targetType(_type),
			targetID(_id),
			targetX(_x),
			targetY(_y)
		{}
	};

};

