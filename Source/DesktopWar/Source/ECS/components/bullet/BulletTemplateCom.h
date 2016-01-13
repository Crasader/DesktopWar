
#pragma once

#include "../../core/Component.h"

namespace Genius
{
	class BulletData;

	class BulletTemplateCom : public Component
	{
	public:
		const BulletData*	pBulletData;

		BulletTemplateCom(BulletData* _bulletInfo);
	};
};

