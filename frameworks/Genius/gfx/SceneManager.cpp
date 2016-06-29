
#include "SceneManager.h"
#include "ECS/ecs.h"
#include "CocosApp.h"
#include "app/GameDefine.h"
#include <algorithm>
#include "SystemStatusPanel.h"

using namespace Genius;
USING_NS_CC;

SceneManager& SceneManager::GetInstance()
{
	static SceneManager mgr;
	return mgr;
}

SceneManager::SceneManager():
m_root(nullptr),
m_pMapLayer(nullptr),
m_bShakeScene(false)
{}

bool SceneManager::Init()
{
	m_root = Node::create();
	m_pMapLayer = LayerColor::create();
	m_root->addChild(m_pMapLayer, GameDefine::mapRootZOrder);
	m_root->setCascadeOpacityEnabled(true);
	m_pMapLayer->setCascadeOpacityEnabled(true);
	((CocosApp*)Application::getInstance())->GetScene()->addChild(m_root);
	return true;
}

void SceneManager::Update()
{
	RefreshPawnsZOrder();

	SystemStatusPanel::GetSingleton()->Update();

	UpdateSceneShake();
}

void SceneManager::AddToMapLayer(cocos2d::Node* node, float x/* = 0*/, float y/* = 0*/, int zOrder/* = 0*/)
{
	m_pMapLayer->addChild(node);
	node->setLocalZOrder(zOrder);
	node->setPosition(x, y);
}

struct SortData
{
	Entity* entity;
	ComPosition* posCom;
	SortData(Entity* ent, ComPosition* pos) : entity(ent), posCom(pos){}
};

bool SortZOrderFunc(SortData data1, SortData data2)
{
	return (data1.posCom->y > data2.posCom->y);
}

void SceneManager::RefreshPawnsZOrder()
{
	return;
	auto sysMgr = ECSWorld::GetSingleton()->GetSystemManager();
	SystemPawnAnim* fightSys = sysMgr->GetSystem<SystemPawnAnim>();
	Bag<Entity*>& activities = fightSys->GetActivities();
	std::vector<SortData> sortedList;
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* pEntity = activities.get(i);
		ComPosition* posCom = pEntity->GetComponent<ComPosition>();
		SortData data(pEntity, posCom);
		sortedList.push_back(data);
	}

	std::sort(sortedList.begin(), sortedList.end(), SortZOrderFunc);
	int zorderStart = 1;
	for (auto iter = sortedList.begin(); iter != sortedList.end(); ++iter)
	{
		Entity* pEntity = (*iter).entity;
		ComPawnAnim* animCom = pEntity->GetComponent<ComPawnAnim>();
		animCom->m_pAvatarRoot->setLocalZOrder(zorderStart);
		zorderStart++;
	}
}

void SceneManager::ShakeScene(int strength, float time)
{
	if (m_bShakeScene)
		return;

	m_bShakeScene = true;
	m_shakeSceneBeginTime = GetTickCount();
	m_shakeStrength = strength > 0 ? strength : -strength;
	m_shakeTime = time > 0 ? time : -time;
}

void SceneManager::UpdateSceneShake()
{
	if (m_bShakeScene)
	{
		int time = GetTickCount() - m_shakeSceneBeginTime;

		if (time * 0.001f >= m_shakeTime)
		{
			m_bShakeScene = false;
			m_shakeSceneBeginTime = 0;

			m_pMapLayer->setPositionX(0.0f);
			m_pMapLayer->setPositionY(0.0f);
		}
		else
		{
			int xPos = rand() % m_shakeStrength - m_shakeStrength/2;
			int yPos = rand() % m_shakeStrength - m_shakeStrength / 2;
			m_pMapLayer->setPositionX(float(xPos));
			m_pMapLayer->setPositionY(float(yPos));
		}
	}
}
