
#include "SceneManager.h"
#include "ECS/ecs.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "CocosApp.h"
#include "app/GameDefine.h"
#include <algorithm>
#include "SystemStatusPanel.h"

using namespace Genius;
USING_NS_CC;


SceneManager*  SceneManager::GetSingleton()
{
	static SceneManager mgr;
	return &mgr;
}

bool SceneManager::Init()
{
	m_root = Node::create();
	m_root->setCascadeOpacityEnabled(true);
	((CocosApp*)Application::getInstance())->GetScene()->addChild(m_root);

	m_pMapLayer = LayerColor::create();
	m_pMapLayer->setCascadeOpacityEnabled(true);
	m_root->addChild(m_pMapLayer, GameDefine::mapRootZOrder);

	m_pUILayer = LayerColor::create();
	m_pUILayer->setCascadeOpacityEnabled(true);
	m_root->addChild(m_pUILayer, GameDefine::mapRootZOrder);

	//auto s1 = Sprite::create("1.jpg");
	//s1->setPosition(400, 268);
	//m_root->addChild(s1);

	//ui::Layer* ul = ui::Layer::create();
	ui::Layout* widget = dynamic_cast<ui::Layout*>(cocostudio::GUIReader::shareReader()->widgetFromJsonFile("res/DemoShop/DemoShop.ExportJson"));
	//Ul->addWidget(widget);
	m_root->addChild(widget);

	EventManager::GetSingleton()->AddListener(this, Event_nodeCreated);
	EventManager::GetSingleton()->AddListener(this, Event_entityDestroy);
	return true;
}

void SceneManager::Update()
{
	RefreshPawnsZOrder();

	//SystemStatusPanel::GetSingleton()->Update();

	UpdateSceneShake();
}

void SceneManager::AddToMapLayer(cocos2d::Node* node, float x/* = 0*/, float y/* = 0*/, int zOrder/* = 0*/)
{
	m_pMapLayer->addChild(node);
	node->setLocalZOrder(zOrder);
	node->setPosition(x, y);
}


bool SortZOrderFunc(const EntityNodeData& data1, const EntityNodeData& data2)
{
	return (data1.node->getPositionY() > data2.node->getPositionY());
}

void SceneManager::RefreshPawnsZOrder()
{
	m_entityNodes.sort(SortZOrderFunc);
	int zorderStart = 1;
	for (auto iter = m_entityNodes.begin(); iter != m_entityNodes.end(); ++iter)
	{
		(*iter).node->setLocalZOrder(zorderStart);
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


bool SceneManager::HandleEvent(IEventData const &evt)
{
	EventType eType = evt.GetType();
	switch (eType)
	{
	case Event_nodeCreated:
	{const NodeCreatedEvent & nodeEvent = static_cast<const NodeCreatedEvent &>(evt);
	EntityNodeData data;
	data.entityID = nodeEvent.entity->GetId();
	data.node = (Node*)nodeEvent.node;
	m_entityNodes.push_back(data); }
		break;
	case Event_entityDestroy:
	{const EntityDectroyEvent & desEvent = static_cast<const EntityDectroyEvent &>(evt);
	int id = desEvent.entity->GetId();
	for (auto iter = m_entityNodes.begin(); iter != m_entityNodes.end(); ++iter)
	{
		if ((*iter).entityID == id)
		{
			m_entityNodes.erase(iter);
			break;
		}
	}
	}
	break;
	}

	return true;
}







