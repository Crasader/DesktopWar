
#pragma once

#include <string>
#include "../../core/IComponent.h"

namespace cfg
{
	class Bullet_cfg;
}

namespace Genius
{
	class BulletBlackboard;

	class ComBulletAgent : public IComponent
	{
	public:
		cfg::Bullet_cfg*					pBulletData;
		BulletBlackboard*			pBlackBoard;

		void Create(cfg::Bullet_cfg* pData);

	};

	

};
