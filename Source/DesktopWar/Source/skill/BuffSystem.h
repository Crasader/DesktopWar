#ifndef _GENIUS_BUFFSYSTEM_H_
#define _GENIUS_BUFFSYSTEM_H_

#include <map>
#include "BuffSet.h"

namespace Genius
{
	class BuffSystem
	{
	public:
		static BuffSystem& GetSingleton();
		~BuffSystem(){}

		void Update(float elapse);
		bool AddBuff(int senderID, int targetID, int buffID);
		void RemoveBuff(int targetID);
		void RemoveAllBuff();

		int	GetBuffCount();

	private:
		BuffSystem();

	private:
		std::map<int, BuffSet>		m_buffSets;
		float		m_timeCounter;
	};

}

#endif