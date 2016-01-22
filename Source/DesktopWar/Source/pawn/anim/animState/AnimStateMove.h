
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateMove : public AnimState
	{
	public:

		AnimStateMove(ComPawnAnim* comAnim);

		virtual ~AnimStateMove();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}