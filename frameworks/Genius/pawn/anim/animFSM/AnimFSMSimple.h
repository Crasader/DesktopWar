
#pragma once

#include "AnimFSM.h"

namespace Genius
{
	class AnimState;


	class AnimFSMSimple : public AnimFSM
	{
	public:

		AnimFSMSimple(ComPawnAnim* pComPawnAnim);

		virtual ~AnimFSMSimple();

		virtual void Initialize();

		virtual void DoAction(PawnAction* pAction);

	};

}

