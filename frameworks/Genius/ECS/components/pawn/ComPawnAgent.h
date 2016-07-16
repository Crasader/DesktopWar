
#pragma once


#include "../../core/IComponent.h"


namespace cfg
{
	class Role_cfg;
	class Bullet_cfg;
}

namespace Genius
{

	class PawnBlackboard;

	class ComPawnAgent : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComPawnAgent);

	public:
		void Create(int cfgID, bool isPawn);
		~ComPawnAgent();
		PawnBlackboard*		GetBlackboard(){ return m_pBlackboard; }
		void AddAction(int type);

	public:
		cfg::Role_cfg*					m_roleCfg;
		cfg::Bullet_cfg*					pBulletData;

	private:
		PawnBlackboard*		m_pBlackboard;

	};

	

};
