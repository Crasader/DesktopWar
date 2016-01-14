
#include "SystemStatusPanel.h"
#include "CocosApp.h"
#include "app/GameDefine.h"
#include "ECS/ecs.h"
#include "app/Config.h"

USING_NS_CC;
using namespace Genius;

const bool enableShowStatus = false;

const int SystemStatusPanel::m_lineHeight = 16;
const int SystemStatusPanel::m_panelWidth = 256;

SystemStatusPanel* SystemStatusPanel::GetSingleton()
{
	static SystemStatusPanel inst;
	return &inst;
}

bool SystemStatusPanel::Init()
{
	m_pRootLayer = LayerColor::create(Color4B(0, 0, 0, 200), (GLfloat)m_panelWidth, (GLfloat)m_lineHeight);
	((CocosApp*)Application::getInstance())->GetScene()->addChild(m_pRootLayer, GameDefine::uiRootZOrder);
	m_pRootLayer->setPositionX(500);
	m_pRootLayer->setVisible(enableShowStatus);

	// Ô¤ÁôµÄ×´Ì¬Label
	m_lineCount = 0;
	m_currentLine = 0;
	
	if (cfg_EnableDrawViewRect)
	{
		pDrawNode = DrawNode::create();
		((CocosApp*)Application::getInstance())->GetScene()->addChild(pDrawNode);
		pDrawNode->drawRect(Vec2(2, 2), Vec2((float)GameDefine::viewWidth - 8, (float)GameDefine::viewHeight - 2), Color4F::RED);
	}

	return true;
}

void SystemStatusPanel::Update()
{
	if (enableShowStatus)
	{
		std::string buffer;
		const std::map<EntitySystem*, int>& times = ECSWorld::GetSingleton()->GetSysCostTime();
		for (auto iter = times.begin(); iter != times.end(); ++iter)
		{
			buffer = iter->first->GetName();
			PrintStatus(buffer, iter->second);
		}
	}
}

void SystemStatusPanel::PrintStatus(std::string& name, std::string& state)
{
	if (m_currentLine >= (int)m_labels.size())
		AddNewLine();

	Label* pLabel = m_labels[m_currentLine];
	if (nullptr == pLabel)
		return;
	std::string text = name + "    " + state;
	pLabel->setString(text);
	m_currentLine++;
}

void SystemStatusPanel::PrintStatus(std::string& name, float state)
{
	char temp[64];
	sprintf_s(temp, 64, "%f", state);
	std::string stateStr = temp;
	PrintStatus(name, stateStr);
}

void SystemStatusPanel::PrintStatus(std::string& name, int state)
{
	char temp[64];
	sprintf_s(temp, 64, "%d", state);
	std::string stateStr = temp;
	PrintStatus(name, stateStr);
}

void SystemStatusPanel::ClearStatus()
{
	m_currentLine = 0;
	static std::string emptyText = "- -";
	for (auto iter = m_labels.begin(); iter != m_labels.end(); ++iter)
	{
		Label* pLabel = *iter;
		if (nullptr == pLabel)
			continue;
		pLabel->setString(emptyText);
	}
}

void SystemStatusPanel::AddNewLine()
{
	if (nullptr == m_pRootLayer)
		return;

	Label* pLabel = Label::createWithBMFont("res/font/arial16.fnt", "- -", TextHAlignment::LEFT);
	pLabel->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	pLabel->setScale(0.8f);
	pLabel->setColor(Color3B(0, 255, 0));
	float x = 10;
	float y = (float)(m_lineCount - 1)*m_lineHeight;
	pLabel->setPosition(x, y);
	m_pRootLayer->addChild(pLabel);
	m_labels.push_back(pLabel);
	m_lineCount++;

	m_pRootLayer->setContentSize(cocos2d::Size((float)m_panelWidth, (float)(m_lineCount*m_lineHeight)));
}