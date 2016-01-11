
#pragma once

namespace Genius
{
	class AnimState
	{
	public:

		AnimState();

		virtual ~AnimState();

		virtual void OnActive() = 0;

		virtual void OnDeactive() = 0;

		virtual void Update() = 0;

	};

}