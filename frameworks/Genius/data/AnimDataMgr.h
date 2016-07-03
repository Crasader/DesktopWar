#ifndef _GENIUS_ANIMATION_DATA_MGR_H_
#define _GENIUS_ANIMATION_DATA_MGR_H_

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "../common/Singleton.h"


namespace Genius
{

#pragma pack(push, 1)
	class AnimInfo : public IData
	{
	public:
		std::string	name;
		std::string	filePath;

		std::string FilePath(){ return filePath; }

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)


	class AnimDataMgr : public IDataManager, public Genius::Singleton<AnimDataMgr>
	{
	public:
		AnimDataMgr(){}
		virtual ~AnimDataMgr(){}

	public:
		virtual bool Init();
		virtual void Destroy();

		virtual std::string	GetName()
		{
			return "res/data/anim.txt";
		}

		virtual int GetSize()
		{
			return m_animInfoList.size()*sizeof(m_animInfoList);
		}

		std::map<std::string, AnimInfo*>& GetAnimInfoList()
		{
			return m_animInfoList;
		}

		AnimInfo* FindAnimInfo(std::string name)
		{
			if (m_animInfoList.find(name) != m_animInfoList.end())
				return m_animInfoList[name];
			return nullptr;
		}

	protected:
		virtual  bool  LoadData(TabFile& reader, int row);

	private:
		std::map<std::string, AnimInfo*>		m_animInfoList;

	};
};

#endif

