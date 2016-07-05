
#pragma once

#include "../../core/Component.h"

namespace cfg
{
	class Bullet_cfg;
}

namespace Genius
{
	class ComBulletTemplate : public Component
	{
	public:
		const cfg::Bullet_cfg*	pBulletData;

		ComBulletTemplate(cfg::Bullet_cfg* _bulletInfo);
	};
};

