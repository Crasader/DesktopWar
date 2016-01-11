
#include "LoadingManager.h"
#include "AnimDataMgr.h"
#include "App/AppStatus/AppStateLoading.h"

using namespace Genius;

LoadingManager::LoadingManager(AppStateLoading* pState)
{
	m_pLoadingState = pState;
}

LoadingManager::~LoadingManager()
{

}

void LoadingManager::GenerateUnLoadList()
{
	m_unloadResources.clear();
	m_unloadResources = m_resources;
}

void LoadingManager::ClearLoadingList()
{
	m_resources.clear();
}

void LoadingManager::AddResource(ResourceType t, std::string& path)
{
	std::map<std::string, AnimInfo*>& animInfoList = AnimDataMgr::GetSingleton()->GetAnimInfoList();
	if (animInfoList.find(path) != animInfoList.end())
	{
		m_resources.push_back(ResourceInfo(t, animInfoList[path]->filePath));
	}
}

bool LoadingManager::IsLoadingDone()
{
	return m_resources.size() == m_loadedCount;
}

int LoadingManager::GetLoadingPercent()
{
	return 100 * m_loadedCount / m_resources.size();
}

void LoadingManager::StartLoading()
{
	m_currentIterator = m_resources.begin();
	m_loadedCount = 0;
}

void LoadingManager::UpdateLoading()
{
	if (!m_unloadResources.empty())
	{
		for (auto iter = m_unloadResources.begin(); iter != m_unloadResources.end(); ++iter)
		{
			ResourceInfo& resource = *iter;
			switch (resource.type)
			{
			case ResourceType::Json:
				cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(resource.path);
				break;
			case ResourceType::Image:
				Director::getInstance()->getTextureCache()->removeTextureForKey(resource.path);
				break;
			}
		}
		m_unloadResources.clear();
		return;
	}

	while (m_currentIterator != m_resources.end())
	{
		ResourceInfo& resource = *m_currentIterator;
		m_currentIterator++;
		switch (resource.type)
		{
		case ResourceType::Json:
			cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfoAsync(resource.path,
				this, schedule_selector(LoadingManager::JsonLoadedCallback));
			break;
		case ResourceType::Image:
			Director::getInstance()->getTextureCache()->addImageAsync(resource.path,
				CC_CALLBACK_1(LoadingManager::ImageLoadedCallback, this));
			break;
		}
	}
}

void LoadingManager::JsonLoadedCallback(float percent)
{
	m_loadedCount++;
	if (m_pLoadingState)
		m_pLoadingState->SetPercent(percent*100);
}

void LoadingManager::ImageLoadedCallback(cocos2d::Texture2D* texture)
{
	m_loadedCount++;
}






