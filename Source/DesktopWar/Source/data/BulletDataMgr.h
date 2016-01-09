#pragma once

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "Singleton.h"

namespace Genius
{
#pragma pack(push, 1)
	class BulletData : public IData
	{
	public:
		const static int BuffNum = 3;

	public:
		int				id;
		int				movable;
		int				moveType;	// 1抛物线，2贝塞尔
		bool				targetIsEntity;	// 控制飞向entity还是坐标点
		int				flySpeed;
		float				findTargetDelay;	// 延迟锁定目标时间
		float				maxLifeTime;
		int				boxWidth;
		int				boxHeight;
		std::string	bodyAnim;
		std::string	tailAnim;
		int				buffTargetStyle;
		int				buffTargetRadius;
		int				attackValue;
		int				attackType;
		int				buffs[BuffNum];

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)

	class BulletDataMgr : public IDataManager, public Singleton<BulletDataMgr>
	{
	public:
		BulletDataMgr(){}
		virtual ~BulletDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();
	
		virtual	std::string GetName()
		{
			return "res/data/bullet.txt";
		}

		virtual int GetSize()
		{
			return m_BulletInfoList.size()*sizeof(m_BulletInfoList);
		}

	protected:
		virtual bool LoadData(TabFile& reader, int row);

	public:
		BulletData* GetBulletData(int id);

	private:
		std::map<int, BulletData*>		m_BulletInfoList;
	};

};