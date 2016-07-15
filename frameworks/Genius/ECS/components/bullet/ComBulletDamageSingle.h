
#pragma once

#include "../../core/IComponent.h"
#include "../../core/Entity.h"

namespace Genius
{
	class ComBulletDamageSingle : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComBulletDamageSingle);

	public:
		int		targetID;

	public:

	};
};

