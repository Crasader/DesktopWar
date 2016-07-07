#ifndef _GENIUS_BUFFMGR_H_
#define _GENIUS_BUFFMGR_H_

#include <map>
#include "BuffSet.h"
#include "common/Singleton.h"

namespace Genius
{
	class BuffManager : public Singleton<BuffManager>
	{
	public:
		BuffManager();

		void Update(float elapse);
		bool AddBuff(int senderID, int targetID, int buffID);
		void RemoveBuff(int targetID);
		void RemoveAllBuff();

		int	GetBuffCount();
	private:
		std::map<int, BuffSet>		m_buffSets;
		float		m_timeCounter;
	};

}

#endif