
#pragma once

#include <string>
#include "../../core/Component.h"

namespace Genius
{
	class RoleData;
	class PawnTemplateCom : public Component
	{
	public:
		const RoleData*	pRoleData;

		PawnTemplateCom(int roleID);

	};

	

};
