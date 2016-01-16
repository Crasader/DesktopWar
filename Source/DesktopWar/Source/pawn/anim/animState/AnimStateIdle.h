
#pragma once

#include "AnimState.h"

namespace Genius
{
	class AnimStateIdle : public AnimState
	{
	public:

		AnimStateIdle(ComPawnAnim* comAnim);

		virtual ~AnimStateIdle();

		virtual void OnActive();

		virtual void OnDeactive();

		virtual void Update();

		virtual void Initialize();

		void PlayAnim();

	};

}