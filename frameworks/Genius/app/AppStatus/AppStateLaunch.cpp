
#include "AppStateLaunch.h"

#include "gfx/gfx.h"
#include "app/GameDefine.h"
#include "ECS/ecs.h"
#include "entity/EntityCreators.h"
#include "app/LoadingManager.h"
#include "app/WarApp.h"
#include "Logger.h"
#include "AnimDataMgr.h"

using namespace Genius;


AppStateLaunch::AppStateLaunch(WarApp* app) :
AppState(app),
m_isFadeOut(false)
{
	m_stateType = AppState::eLaunch;
}

AppStateLaunch::~AppStateLaunch()
{

}

bool AppStateLaunch::Init()
{
	m_timePassed = 0;
	m_isFadeOut = false;
	m_soldierSpawned = false;
	Logger::LogInfo("Enter launch..");
	return true;
}

void AppStateLaunch::Update(float time)
{
	const float maxLaunchTime = 15;
	const float spawnSoldierTime = 0.0f;

	m_timePassed += time;

	if (m_soldierSpawned == false && m_timePassed > spawnSoldierTime)
	{
		m_soldierSpawned = true;
		float baseX = GameDefine::viewWidth*0.5f;
		float baseY = 0;
		EntityCreator::CreatePawn("BigDevil_chase", baseX + 300, 133, Team_Monster);
		EntityCreator::CreatePawn("HolyKnight", baseX - 300, 133, Team_Human);
	}

	/*if (!m_isFadeOut && m_timePassed > maxLaunchTime)
	{
		cocos2d::FadeOut* fadeOut = cocos2d::FadeOut::create(2);
		cocos2d::CallFunc* callBack = cocos2d::CallFunc::create(CC_CALLBACK_0(AppStateLaunch::FadeOutCallback, this));
		cocos2d::Sequence* sequence = cocos2d::Sequence::create(fadeOut, callBack, nullptr);
		SceneManager::GetInstance().GetMapLayer()->setCascadeOpacityEnabled(true);
		SceneManager::GetInstance().GetMapLayer()->runAction(sequence);
		m_isFadeOut = true;
	}*/

}

void AppStateLaunch::Destroy()
{
	m_timePassed = 0;
	m_isFadeOut = false;
	m_soldierSpawned = false;

	Genius::EntityManager * em = ECSWorld::GetSingleton()->GetEntityManager();
	em->RemoveAllEntities();
}

void AppStateLaunch::GenerateLoadingList(LoadingManager* pLoadMgr)
{
	pLoadMgr->AddResource(LoadingManager::ResourceType::Json, std::string("HolyKnight"));
	pLoadMgr->AddResource(LoadingManager::ResourceType::Json, std::string("BigDevil"));
}

void AppStateLaunch::FadeOutCallback()
{
	m_pApp->SwitchState(eBattle);
}