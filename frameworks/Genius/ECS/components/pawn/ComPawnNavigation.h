
#pragma once

#include <string>
#include "../../core/IComponent.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComPawnNavigation : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComPawnNavigation);

	public:
		std::vector<Point2D>	pathPoints;
		unsigned int					curPointIndex;
		bool									arrived;
	public:
		ComPawnNavigation() :
			curPointIndex(0),
			arrived(false)
		{}

		void MoveTo(float x, float y);
	};

	

};
