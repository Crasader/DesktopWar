
#pragma once

#include "BuffLogic.h"

namespace Genius
{
	class BL_Spawn : public BuffLogic
	{
	public:
		virtual void OnActive(Buff* buff);
		virtual void OnDeactive(Buff* buff);
		virtual void OnEffect(Buff* buff);

		DECLARE_BUFFLOGIC_CREATOR(BL_Spawn)

	};

}