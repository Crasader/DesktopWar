
#pragma once

#include "../../core/Component.h"
#include "../../core/Entity.h"

namespace Genius
{
	class BulletDamageSingleCom : public Component
	{
	public:
		int		targetID;

	public:
		BulletDamageSingleCom():
			targetID(Entity::InvalidID)
		{}
	};
};

