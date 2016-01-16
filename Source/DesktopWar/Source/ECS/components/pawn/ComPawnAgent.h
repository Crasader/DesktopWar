
#pragma once

#include <string>
#include "../../core/Component.h"
#include "data/RoleDataMgr.h"

namespace Genius
{
	class PawnBlackboard;

	class ComPawnAgent : public Component
	{
	public:
		RoleData*					m_pRoleData;
		PawnBlackboard*		m_pBlackboard;

		ComPawnAgent(RoleData* pData);
		~ComPawnAgent();

	public:
		PawnBlackboard*		GetBlackboard(){ return m_pBlackboard; }

	};

	

};
