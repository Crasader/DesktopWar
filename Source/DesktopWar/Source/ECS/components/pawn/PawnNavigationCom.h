
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class PawnNavigationCom : public Component
	{
	public:
		std::vector<Point2D>	pathPoints;
		unsigned int					curPointIndex;
		bool									arrived;
	public:
		PawnNavigationCom() :
			curPointIndex(0),
			arrived(false)
		{}

		void MoveTo(float x, float y);
	};

	

};
