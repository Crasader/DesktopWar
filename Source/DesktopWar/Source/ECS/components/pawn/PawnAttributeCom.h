
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class PawnAttributeCom : public Component
	{
	public:
		int		curLife;
	
	public:
		PawnAttributeCom(int roleID);
		~PawnAttributeCom();
	};

	

};
