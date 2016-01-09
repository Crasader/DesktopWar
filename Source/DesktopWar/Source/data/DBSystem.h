#ifndef _GENIUS_DBSYSTEM_H_
#define _GENIUS_DBSYSTEM_H_

#include <vector>

namespace Genius
{
	class IDataManager;
	class DBSystem
	{
	public:
		static DBSystem&	GetSingleton()
		{
			static DBSystem inst;
			return inst;
		}
		DBSystem(){}
		~DBSystem(){}
		bool Init();
		void Destroy();

	private:
		void AddDataManager(IDataManager* mgr);

	private:
		std::vector<IDataManager*>		m_dataMgrList;
	};
};

#endif