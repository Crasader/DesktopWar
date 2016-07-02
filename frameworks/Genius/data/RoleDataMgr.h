#pragma once

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "../common/Singleton.h"

namespace Genius
{
#pragma pack(push, 1)
	class RoleData : public IData
	{
	public:
		int				id;
		std::string		nameID;
		std::string		nameCN;
		std::string		animSetName;
		std::string		bevTreeFile;
		float				moveSpeed;
		float				viewRange;
		int				fightRangeNear;
		int				fightRangeFar;
		int				baseLife;
		int				attackValue;
		int				attackType;
		int				antiPhysicValue;
		int				antiMagicValue;
		int				dodgeValue;
		int				normalSkill1;					// 普通攻击技1
		int				maxAttack1Times;		// 普通攻击最大连续次数
		int				normalSkill2;					// 普通攻击技2
		int				specialSkill1;
		int				specialSkill2;
		int				specialSkill3;
		int				lifeBarType;
		int				lifeBarHeight;
		float				IdleDuration;
		float				IdleTurnFaceTime;
		float				WanderDuration;
		float				WanderChangeDirTime;
		float				DeadBodyTime;
		int				bulletX;
		int				bulletY;

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)

	class RoleDataMgr : public IDataManager, public Singleton<RoleDataMgr>
	{
	public:
		RoleDataMgr(){}
		virtual ~RoleDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();
	
		virtual	std::string GetName()
		{
			return "res/data/role.txt";
		}

		virtual int GetSize()
		{
			return m_roleInfoList.size()*sizeof(m_roleInfoList);
		}

	protected:
		virtual  bool LoadData(TabFile& reader, int row);

	public:
		RoleData*		GetRoleData(int id);
		RoleData*		GetRoleData(std::string name);

	private:
		std::map<int, RoleData*>		m_roleInfoList;
	};

	enum AttackType
	{
		AT_Unknown,
		AT_Physic,
		AT_Magic,
	};

};