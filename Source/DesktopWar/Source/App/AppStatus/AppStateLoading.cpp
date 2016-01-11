
#include "AppStateLoading.h"
#include "GameDefine.h"
#include "gfx/gfx.h"
#include "LoadingManager.h"
#include "WarApp.h"
#include "Logger.h"
#include "AnimDataMgr.h"


using namespace Genius;


AppStateLoading::AppStateLoading(WarApp* app) :
AppState(app),
m_pLoadingManager(nullptr)
{
	m_stateType = AppState::eLoading;
	m_pLoadingManager = new LoadingManager(this);
}

AppStateLoading::~AppStateLoading()
{
	if (m_pLoadingManager)
		delete m_pLoadingManager;
}

bool AppStateLoading::Init()
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
	m_percentLabel->setColor(cocos2d::Color3B(0, 255, 0));
	m_percentLabel->setScale(1.5f);
	m_percentLabel->setPosition(x, y - 20);
	m_pUIRoot->addChild(m_percentLabel);

	Logger::LogInfo("Enter loading..");
	return true;
}

void AppStateLoading::Update(float time)
{
	m_pLoadingManager->UpdateLoading();

	if (m_pLoadingManager->IsLoadingDone() && m_percentLabel->isRollDone())
	{
		m_pApp->SetCurrentState(m_nextState);
	}
}

void AppStateLoading::Destroy()
{
	if (m_pUIRoot)
	{
		m_pUIRoot->removeFromParent();
		m_pUIRoot = nullptr;
	}
}

void AppStateLoading::GenerateLoadingList(LoadingManager* pLoadMgr)
{

}

void AppStateLoading::StartLoading(AppState* pPrevState, AppState* pNextState)
{
	m_prevState = pPrevState;
	m_nextState = pNextState;
	// 生成卸载列表、加载列表
	m_pLoadingManager->GenerateUnLoadList();
	m_pLoadingManager->ClearLoadingList();
	pNextState->GenerateLoadingList(m_pLoadingManager);

	m_pLoadingManager->StartLoading();
}

void AppStateLoading::SetPercent(int percent)
{
	m_percentLabel->/*setStartNumber*/rollTo(percent);
}
