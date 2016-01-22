
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateDie : public AnimState
	{
	public:

		AnimStateDie(ComPawnAnim* comAnim);

		virtual ~AnimStateDie();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}