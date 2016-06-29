
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateAttackFar : public AnimState
	{
	public:

		AnimStateAttackFar(ComPawnAnim* comAnim);

		virtual ~AnimStateAttackFar();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}