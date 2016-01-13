
#pragma once

#include "../../core/Component.h"
#include "../../core/Entity.h"

namespace Genius
{
	class ComBulletDamageSingle : public Component
	{
	public:
		int		targetID;

	public:
		ComBulletDamageSingle():
			targetID(Entity::InvalidID)
		{}
	};
};

