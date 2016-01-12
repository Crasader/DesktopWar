
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class PawnFightCom : public Component
	{
	public:
		int		enemyID;
		bool		haveTarget;
		bool		isTargetInNearRange;
		bool		isTargetInFarRange;

	public:
		PawnFightCom();
		~PawnFightCom();
		virtual bool Init();
	};

	

};
