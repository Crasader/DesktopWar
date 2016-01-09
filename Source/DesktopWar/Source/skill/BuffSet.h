#ifndef _GENIUS_BUFFSET_H_
#define _GENIUS_BUFFSET_H_

#include <map>
#include "Buff.h"

namespace Genius
{
	class BuffSet
	{
	public:
		BuffSet(int owner) :
			m_ownerID(owner),
			m_instIDCounter(0)
		{}
		int AddBuff(int senderID, int buffID);
		void KillAllBuff();
		int KillBuff(int oldBuffInstID);
		void DealWithDelBuff();

		void Update(float elpase);

		int GetBuffCount(){ return m_buffInsts.size(); }

	private:
		int ReplaceBuff(int buffInstID, int senderID, int buffTemplateID);
		int TileBuff(int senderID, int buffTemplateID);
		int RemoveBuff(int buffInstID);

	private:
		std::map<int, Buff>	m_buffInsts;
		std::vector<int>	m_deleteSet;
		int							m_ownerID;
		int							m_instIDCounter;
	};

}

#endif