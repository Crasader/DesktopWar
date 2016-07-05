
#pragma once

#include <string>
#include "../../core/Component.h"

namespace Genius
{
	class BulletBlackboard;
	class Bullet_cfg;

	class ComBulletAgent : public Component
	{
	public:
		Bullet_cfg*					pBulletData;
		BulletBlackboard*			pBlackBoard;

		ComBulletAgent(Bullet_cfg* pData);

	};

	

};
