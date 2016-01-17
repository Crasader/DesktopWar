
#pragma once

#include <list>
#include "ActionDefine.h"

namespace Genius
{
	class PawnAction;

	class PawnActionFactory
	{
	public:

		static PawnActionFactory* GetSingleton();

		~PawnActionFactory();

		PawnAction* CreatePawnAction(int type);
	
		void RecycleAction(PawnAction* pAction);

		void Release();

	private:

		std::list<PawnAction*>	m_actionUnused[PAT_Count];

		std::list<PawnAction*>	m_actionInUse[PAT_Count];

	};
}