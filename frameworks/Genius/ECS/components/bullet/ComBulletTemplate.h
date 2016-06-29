
#pragma once

#include "../../core/Component.h"

namespace Genius
{
	class BulletData;

	class ComBulletTemplate : public Component
	{
	public:
		const BulletData*	pBulletData;

		ComBulletTemplate(BulletData* _bulletInfo);
	};
};

