
#pragma once

#include <string>
#include "../../core/Component.h"
#include "data/auto/Role_cfg.hpp"

namespace Genius
{
	class PawnBlackboard;

	class ComPawnAgent : public Component
	{
	public:
		cfg::Role_cfg*					m_roleCfg;
		PawnBlackboard*		m_pBlackboard;

		ComPawnAgent(cfg::Role_cfg* pData);
		~ComPawnAgent();

	public:
		PawnBlackboard*		GetBlackboard(){ return m_pBlackboard; }

	public:
		void AddAction(int type);

	};

	

};
