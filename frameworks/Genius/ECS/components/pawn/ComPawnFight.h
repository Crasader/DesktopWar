
#pragma once

#include <string>
#include "../../core/IComponent.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComPawnFight : public IComponent
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
