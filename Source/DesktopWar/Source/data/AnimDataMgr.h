#ifndef _GENIUS_ANIMATION_DATA_MGR_H_
#define _GENIUS_ANIMATION_DATA_MGR_H_

#include <string>
#include <map>
#include <vector>
#include "IDataManager.h"
#include "Singleton.h"


namespace Genius
{

#pragma pack(push, 1)
	class AnimInfo : public IData
	{
	public:
		std::string	name;
		std::string	filePath;

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row);
	};
#pragma pack(pop)


	class AnimDataMgr : public IDataManager, public Singleton<AnimDataMgr>
	{
	public:
		AnimDataMgr(){}
		virtual ~AnimDataMgr(){}

	public:
		virtual bool			Init();
		virtual void			Destroy();

		virtual std::string	GetName()
		{
			return "res/data/anim.txt";
		}

		virtual int				GetSize()
		{
			return m_animInfoList.size()*sizeof(m_animInfoList);
		}

		std::map<std::string, AnimInfo*>& GetAnimInfoList()
		{
			return m_animInfoList;
		}

	protected:
		virtual  bool  LoadData(TabFile& reader, int row);

// 	public:
// 		AnimationSetData& GetAnimSet(std::string name);
// 
// 	private:
// 		bool LoadFromConfig(std::string file);

	private:
		std::map<std::string, AnimInfo*>		m_animInfoList;
/*		std::map<std::string, AnimationSetData>		m_animSetCache;*/
	};
};

#endif

