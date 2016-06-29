
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateSkill2 : public AnimState
	{
	public:

		AnimStateSkill2(ComPawnAnim* comAnim);

		virtual ~AnimStateSkill2();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}