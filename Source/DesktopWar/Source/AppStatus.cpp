
#include "AppStatus.h"
#include "gfx/gfx.h"
#include "GameDefine.h"
#include "ECS/ECSHeaders.h"
#include "EntityCreators.h"
#include "LoadingManager.h"
#include "WarApp.h"
#include "Logger.h"
#include "AnimDataMgr.h"

using namespace Genius;

AppLaunchState::AppLaunchState(WarApp* app) :
	AppState(app),
	m_pScreenTexture(nullptr),
	m_isFadeOut(false)
{
	m_stateType = AppState::eLaunch;
}

AppLaunchState::~AppLaunchState()
{

}

bool AppLaunchState::Init()
{
	m_timePassed = 0;
	m_isFadeOut = false;
	m_soldierSpawned = false;

	/*m_pScreenTexture = new cocos2d::Texture2D();
	cocos2d::Sprite* pScreenSprite = GfxUtils::PrintScreen(&m_pScreenTexture);
	SceneManager::GetInstance().AddToMapLayer(pScreenSprite);
	pScreenSprite->setPositionX(GameDefine::viewWidth * 0.5f);
	pScreenSprite->setPositionY(GameDefine::viewHeight * 0.5f);*/
	Logger::LogInfo("Enter launch..");
	return true;
}

void AppLaunchState::Update(float time)
{
	const float maxLaunchTime = 15;
	/*const float startShakeTime = 1.0f;
	const float shakeInterval = 1.2f;
	const int shakeMaxCount = 100;*/
	const float spawnSoldierTime = 0.0f;

	m_timePassed += time;

	// 开始震动
	/*if (m_timePassed > startShakeTime && m_shakeCount < shakeMaxCount && m_timePassed - m_lastShakeTime > shakeInterval)
	{
		SceneManager::GetInstance().ShakeScene(5, 0.5f);
		m_lastShakeTime = m_timePassed;
		m_shakeCount++;
	}*/

	if (m_soldierSpawned == false && m_timePassed > spawnSoldierTime)
	{
		m_soldierSpawned = true;
		float baseX = GameDefine::viewWidth*0.5f;
		float baseY = 0;
		EntityCreator::CreatePawn("BigDevil_chase", baseX + 30, 133, Team_Monster);
		EntityCreator::CreatePawn("HolyKnight", baseX - 30, 133, Team_Human);
	}

	if ( !m_isFadeOut && m_timePassed > maxLaunchTime)
	{
		cocos2d::FadeOut* fadeOut = cocos2d::FadeOut::create(2);
		cocos2d::CallFunc* callBack = cocos2d::CallFunc::create(CC_CALLBACK_0(AppLaunchState::FadeOutCallback, this));
		cocos2d::Sequence* sequence = cocos2d::Sequence::create(fadeOut, callBack, nullptr);
		SceneManager::GetInstance().GetMapLayer()->setCascadeOpacityEnabled(true);
		SceneManager::GetInstance().GetMapLayer()->runAction(sequence);
		m_isFadeOut = true;
	}
	
}

void AppLaunchState::Destroy()
{
	m_timePassed = 0;
	m_isFadeOut = false;
	m_soldierSpawned = false;
	if (m_pScreenTexture)
	{
		delete m_pScreenTexture;
		m_pScreenTexture = nullptr;
	}

	Genius::EntityManager * em = ECSWorld::GetSingleton()->GetEntityManager();
	em->RemoveAllEntities();
}

void AppLaunchState::GenerateLoadingList(LoadingManager* pLoadMgr)
{
	pLoadMgr->AddResource(LoadingManager::ResourceType::Json, std::string("HolyKnight"));
	pLoadMgr->AddResource(LoadingManager::ResourceType::Json, std::string("BigDevil"));
}

void AppLaunchState::FadeOutCallback()
{
	m_pApp->SwitchState(eBattle);
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

AppLoadingState::AppLoadingState(WarApp* app) :
	AppState(app),
	m_pLoadingManager(nullptr)
{
	m_stateType = AppState::eLoading;
	m_pLoadingManager = new LoadingManager(this);
}

AppLoadingState::~AppLoadingState()
{
	if (m_pLoadingManager)
		delete m_pLoadingManager;
}

bool AppLoadingState::Init()
{
	m_pUIRoot = cocos2d::Node::create();
	SceneManager::GetInstance().AddToMapLayer(m_pUIRoot);

	float x = GameDefine::viewWidth * 0.5f;
	float y = GameDefine::viewHeight * 0.6f;

	std::map<std::string, AnimInfo*>& animInfoList = AnimDataMgr::GetSingleton()->GetAnimInfoList();
	if (animInfoList.find("Loading_King") != animInfoList.end())
	{
		cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(animInfoList["Loading_King"]->filePath);
		cocostudio::Armature* pArmature = cocostudio::Armature::create("Loading_King");
		pArmature->setPosition(x, y);
		m_pUIRoot->addChild(pArmature);
		pArmature->getAnimation()->playWithIndex(0);
	}

	m_percentLabel = RollNumberLabel::create();
	m_percentLabel->setStartNumber(0);
	m_percentLabel->setColor(cocos2d::Color3B(0,255,0));
	m_percentLabel->setScale(1.5f);
	m_percentLabel->setPosition(x, y-20);
	m_pUIRoot->addChild(m_percentLabel);

	Logger::LogInfo("Enter loading..");
	return true;
}

void AppLoadingState::Update(float time)
{
	m_pLoadingManager->UpdateLoading();

	if (m_pLoadingManager->IsLoadingDone() && m_percentLabel->isRollDone())
	{
		m_pApp->SetCurrentState(m_nextState);
	}
}

void AppLoadingState::Destroy()
{
	if (m_pUIRoot)
	{
		m_pUIRoot->removeFromParent();
		m_pUIRoot = nullptr;
	}
}

void AppLoadingState::GenerateLoadingList(LoadingManager* pLoadMgr)
{
	
}

void AppLoadingState::StartLoading(AppState* pPrevState, AppState* pNextState)
{
	m_prevState = pPrevState;
	m_nextState = pNextState;
	// 生成卸载列表、加载列表
	m_pLoadingManager->GenerateUnLoadList();
	m_pLoadingManager->ClearLoadingList();
	pNextState->GenerateLoadingList(m_pLoadingManager);

	m_pLoadingManager->StartLoading();
}

void AppLoadingState::SetPercent(int percent)
{
	m_percentLabel->/*setStartNumber*/rollTo(percent);
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
AppBattleState::AppBattleState(WarApp* app):
	AppState(app)
{
	m_stateType = AppState::eBattle;
}

AppBattleState::~AppBattleState()
{

}

bool AppBattleState::Init()
{
	Logger::LogInfo("Enter battle..");
	return true;
}

void AppBattleState::Update(float time)
{

}

void AppBattleState::Destroy()
{

}

void AppBattleState::GenerateLoadingList(LoadingManager* pLoadMgr)
{
	std::map<std::string, AnimInfo*>& animInfoList = AnimDataMgr::GetSingleton()->GetAnimInfoList();
	for (auto iter = animInfoList.begin(); iter != animInfoList.end(); ++iter)
	{
		pLoadMgr->AddResource(LoadingManager::ResourceType::Json, iter->second->name);
	}
}





