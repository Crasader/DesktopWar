
#pragma once

#include "BuffLogic.h"

namespace Genius
{
	class BL_ChangeAttr : public BuffLogic
	{
	public:
		virtual void OnActive(){}
		virtual void OnDeactive(){}

		DECLARE_BUFFLOGIC_CREATOR(BL_ChangeAttr)

	};

}