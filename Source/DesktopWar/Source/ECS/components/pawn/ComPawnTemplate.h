
#pragma once

#include <string>
#include "../../core/Component.h"

namespace Genius
{
	class RoleData;
	class ComPawnTemplate : public Component
	{
	public:
		const RoleData*	pRoleData;

		ComPawnTemplate(int roleID);

	};

	

};
