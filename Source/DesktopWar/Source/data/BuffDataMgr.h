#pragma once

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "Singleton.h"

namespace Genius
{
#pragma pack(push, 1)
	class BuffData : public IData
	{
	public:
		int				id;
		int				series;
		int				hurtType;
		int				duration;
		int				jumpTime;
		int				maxPileCount;
		int				pileType;
		//int				strategyID;

		int				actionID;
		int				actionType;
		std::vector<int>	beginActions;
		std::vector<int>	cycleActions;
		std::vector<int>	effectActions;
		std::vector<int>	endActions;

	public:
		enum EActionType
		{
			EActionType_Wrong = 0,
			EActionType_Begin,
			EActionType_Cycle,
			EActionType_Effect,
			EActionType_End,
		};

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)

	class BuffDataMgr : public IDataManager, public Singleton<BuffDataMgr>
	{
	public:
		BuffDataMgr(){}
		virtual ~BuffDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();
	
		virtual	std::string GetName()
		{
			return "res/data/buff.txt";
		}

		virtual int GetSize()
		{
			return m_BuffInfoList.size()*sizeof(m_BuffInfoList);
		}

	protected:
		virtual bool LoadData(TabFile& reader, int row);

	public:
		BuffData* GetBuffData(int id);

	private:
		std::map<int, BuffData*>		m_BuffInfoList;
	};

};