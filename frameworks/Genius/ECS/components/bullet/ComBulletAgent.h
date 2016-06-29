
#pragma once

#include <string>
#include "../../core/Component.h"

namespace Genius
{
	class BulletBlackboard;
	class BulletData;

	class ComBulletAgent : public Component
	{
	public:
		BulletData*					pBulletData;
		BulletBlackboard*			pBlackBoard;

		ComBulletAgent(BulletData* pData);

	};

	

};
