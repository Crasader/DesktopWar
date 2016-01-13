
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComPawnFight : public Component
	{
	public:
		int		enemyID;
		bool		haveTarget;
		bool		isTargetInNearRange;
		bool		isTargetInFarRange;

	public:
		ComPawnFight();
		~ComPawnFight();
		virtual bool Init();
	};

	

};
