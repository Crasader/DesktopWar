// d:)
#include "AnimDataMgr.h"
#include "gfx/gfx.h"
#include "Logger.h"


using namespace Genius;

bool AnimInfo::ParseBuffer(TabFile& reader, int row)
{
	int col = 0;
	col++;
	name = reader.GetStringValue(row, col++);
	filePath = reader.GetStringValue(row, col++);

	return true;
}


/************************************************************************/
/*                                                   RoleDataMgr                   */
/************************************************************************/
bool AnimDataMgr::Init()
{
	if (IDataManager::Init())
	{
		/*for (auto iter = m_animInfoList.begin(); iter != m_animInfoList.end(); ++iter)
		{
			cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(iter->second->filePath);
		}*/
		return true;
	}

	return false;
}

void AnimDataMgr::Destroy()
{
	for (auto iter = m_animInfoList.begin(); iter != m_animInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_animInfoList.clear();
}

bool AnimDataMgr::LoadData(TabFile& reader, int row)
{
	AnimInfo* info = new AnimInfo;
	bool ret = info->ParseBuffer(reader, row);
	if (ret)
		m_animInfoList.insert(std::make_pair(info->name, info));

	return true;
}

// AnimationSetData& AnimDataMgr::GetAnimSet(std::string name)
// {
// 	static AnimationSetData set;
// 	std::map<std::string, AnimationSetData>::iterator iter = m_animSetCache.find(name);
// 	if (iter != m_animSetCache.end())
// 		return iter->second;
// 	else
// 		return set;
// }
/*
bool AnimDataMgr::LoadFromConfig(std::string filePath)
{
	TiXmlDocument* doc = new TiXmlDocument();
	if (!doc->LoadFile(filePath.c_str()))
		return false;

	std::string forePath = filePath.substr(0, filePath.find_last_of("/") + 1);

	TiXmlElement* root = doc->RootElement();
	for (TiXmlElement* animSetNode = root->FirstChildElement(); animSetNode; animSetNode = animSetNode->NextSiblingElement())
	{
		AnimationSetData animSetTemp;
		animSetTemp.name = animSetNode->Attribute("name");
		for (TiXmlElement* animNode = animSetNode->FirstChildElement(); animNode; animNode = animNode->NextSiblingElement())
		{
			AnimationData animTemp;
			animTemp.name = animNode->Attribute("name");
			animTemp.frameTime = 0.001f*atoi(animNode->Attribute("frameTime"));
			animTemp.loop = atoi(animNode->Attribute("loop")) == 0 ? false : true;
			animTemp.anchorX = (float)atof(animNode->Attribute("anchorX"));
			animTemp.anchorY = (float)atof(animNode->Attribute("anchorY"));
			for (TiXmlElement* frameNode = animNode->FirstChildElement(); frameNode; frameNode = frameNode->NextSiblingElement())
			{
				FrameData frameTemp;
				frameTemp.fileName = forePath + frameNode->Attribute("file");
				frameTemp.flipX = atoi(frameNode->Attribute("flipX")) == 0 ? false : true;
				frameTemp.flipY = atoi(frameNode->Attribute("flipY")) == 0 ? false : true;
				frameTemp.eventName = frameNode->Attribute("event");

				Texture* tex = TextureCache::GetSingleton().AddTexture(frameTemp.fileName.c_str());
				frameTemp.tex = tex;
				animTemp.frames.push_back(frameTemp);
			}
			animSetTemp.anims.insert(std::make_pair(animTemp.name, animTemp));
		}
		m_animSetCache.insert(std::make_pair(animSetTemp.name, animSetTemp));
	}
	delete doc;

	return true;
}*/