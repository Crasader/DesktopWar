#pragma once

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "../common/Singleton.h"

namespace Genius
{
#pragma pack(push, 1)
	class SkillData : public IData
	{
	public:
		const static int MaxBuffNum = 3;

	public:
		int				id;
		int				findTargetStyle;
		int				findTargetRadius;
		int				targetTeam;
		int				costType;
		int				costNum;
		float			coolTime;
		int				bulletID;
		int				buffs[MaxBuffNum];

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)

	class SkillDataMgr : public IDataManager, public Singleton<SkillDataMgr>
	{
	public:
		SkillDataMgr(){}
		virtual ~SkillDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();
	
		virtual	std::string GetName()
		{
			return "res/data/skill.txt";
		}

		virtual int GetSize()
		{
			return m_SkillInfoList.size()*sizeof(m_SkillInfoList);
		}

	protected:
		virtual bool LoadData(TabFile& reader, int row);

	public:
		SkillData* GetSkillData(int id);

	private:
		std::map<int, SkillData*>		m_SkillInfoList;
	};

};