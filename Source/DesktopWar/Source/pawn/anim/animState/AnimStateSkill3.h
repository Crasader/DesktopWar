
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateSkill3 : public AnimState
	{
	public:

		AnimStateSkill3(ComPawnAnim* comAnim);

		virtual ~AnimStateSkill3();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}