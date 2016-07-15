
#pragma once

#include <string>
#include "../../core/IComponent.h"
#include "data/auto/Role_cfg.hpp"

namespace Genius
{
	class PawnBlackboard;

	class ComPawnAgent : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComPawnAgent);

	public:
		cfg::Role_cfg*					m_roleCfg;
		PawnBlackboard*		m_pBlackboard;

		void Create(int roleCfgID);
		~ComPawnAgent();

	public:
		PawnBlackboard*		GetBlackboard(){ return m_pBlackboard; }

	public:
		void AddAction(int type);

	};

	

};
