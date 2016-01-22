
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateSkill1 : public AnimState
	{
	public:

		AnimStateSkill1(ComPawnAnim* comAnim);

		virtual ~AnimStateSkill1();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}