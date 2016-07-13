
#pragma once


#include "../../core/IComponent.h"
#include "../../core/Entity.h"

namespace Genius
{
	
	class ComTarget : public IComponent
	{
	public:
		int		targetType;
		int		targetID;
		float		targetX;
		float		targetY;

	public:
		void Create(int _type, int _id = Entity::InvalidID, float _x = 0, float _y = 0);
	};

};

