
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateAttackNear : public AnimState
	{
	public:

		AnimStateAttackNear(ComPawnAnim* comAnim);

		virtual ~AnimStateAttackNear();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}