
#include "AppStateBattle.h"

#include "gfx/gfx.h"
#include "app/GameDefine.h"
#include "ECS/ecs.h"
#include "entity/EntityCreators.h"
#include "LoadingManager.h"
#include "app/WarApp.h"
#include "Logger.h"
#include "AnimDataMgr.h"


using namespace Genius;


AppStateBattle::AppStateBattle(WarApp* app) :
AppState(app)
{
	m_stateType = AppState::eBattle;
}

AppStateBattle::~AppStateBattle()
{

}

bool AppStateBattle::Init()
{
	Logger::LogInfo("Enter battle..");
	return true;
}

void AppStateBattle::Update(float time)
{

}

void AppStateBattle::Destroy()
{

}

void AppStateBattle::GenerateLoadingList(LoadingManager* pLoadMgr)
{
	std::map<std::string, AnimInfo*>& animInfoList = AnimDataMgr::GetSingleton()->GetAnimInfoList();
	for (auto iter = animInfoList.begin(); iter != animInfoList.end(); ++iter)
	{
		pLoadMgr->AddResource(LoadingManager::ResourceType::Json, iter->second->name);
	}
}