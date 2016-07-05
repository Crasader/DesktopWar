
#pragma once

#include <string>
#include "../../core/Component.h"

namespace cfg
{
	class Bullet_cfg;
}

namespace Genius
{
	class BulletBlackboard;

	class ComBulletAgent : public Component
	{
	public:
		cfg::Bullet_cfg*					pBulletData;
		BulletBlackboard*			pBlackBoard;

		ComBulletAgent(cfg::Bullet_cfg* pData);

	};

	

};
