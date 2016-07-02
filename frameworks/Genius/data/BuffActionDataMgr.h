#pragma once

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "../common/Singleton.h"

#define MaxActionParamNum 3

namespace Genius
{
#pragma pack(push, 1)
	class BuffActionData : public IData
	{
	public:
		int					id;
		int					buffType;
		std::string		action;
		int					params[MaxActionParamNum];

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)

	class BuffActionDataMgr : public IDataManager, public Singleton<BuffActionDataMgr>
	{
	public:
		BuffActionDataMgr(){}
		virtual ~BuffActionDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();
	
		virtual	std::string GetName()
		{
			return "res/data/buffAction.txt";
		}

		virtual int GetSize()
		{
			return m_BuffInfoList.size()*sizeof(m_BuffInfoList);
		}

	protected:
		virtual bool LoadData(TabFile& reader, int row);

	public:
		BuffActionData* GetBuffActionData(int id);

	private:
		std::map<int, BuffActionData*>		m_BuffInfoList;
	};

};