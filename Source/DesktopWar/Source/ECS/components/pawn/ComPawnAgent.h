
#pragma once

#include <string>
#include "../../core/Component.h"

namespace Genius
{
	class PawnBlackboard;
	class RoleData;
	class AnimSet;

	class ComPawnAgent : public Component
	{
	public:
		RoleData*					pRoleData;
		PawnBlackboard*		pBlackBoard;

		ComPawnAgent(int roleID);

	};

	

};
