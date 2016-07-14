
#include "SystemPawnDirection.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/action/ActionDefine.h"

using namespace Genius;

void SystemPawnDirection::Initialize()
{
	positionMapper.init(*world);
	pawnDirectionMapper.init(*world);
	pawnAgentMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_velocityChanged);
	EventManager::GetSingleton()->AddListener(this, Event_turnBack);
	EventManager::GetSingleton()->AddListener(this, Event_turnTo);
}

void SystemPawnDirection::ProcessEntity(Entity* e)
{
}

bool SystemPawnDirection::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	switch (eType)
	{
	case Event_velocityChanged:
	{
		const VelocityChangedEvent & actionEvent = static_cast<const VelocityChangedEvent &>(event);
		ComPawnAgent* pawnAgent = pawnAgentMapper.get(actionEvent.entity);
		ComPawnDirection* pawnDir = pawnDirectionMapper.get(actionEvent.entity);
		if (nullptr != pawnDir && nullptr != pawnAgent)
		{
			unsigned int dir = CalculateDirection(pawnDir, actionEvent.x, actionEvent.y);
			pawnDir->m_lastFaceDir = pawnDir->m_currentDir;
			pawnDir->m_currentDir = dir;

			pawnAgent->AddAction(PAT_ChangeDir);
		}
	}
		break;
	case Event_turnBack:
	{
		const TurnBackEvent & actionEvent = static_cast<const TurnBackEvent &>(event);
		ComPawnDirection* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->ChangeDirection(dirCom, Face_Turn);
		ComPawnAgent* pawnAgent = pawnAgentMapper.get(actionEvent.entity);
		pawnAgent->AddAction(PAT_ChangeDir);
	}
		break;
	case Event_turnTo:
	{
		const TurnToEvent & actionEvent = static_cast<const TurnToEvent &>(event);
		ComTransform* pawnPos = positionMapper.get(actionEvent.entity);
		ComPawnDirection* pawnDir = pawnDirectionMapper.get(actionEvent.entity);
		ComPawnAgent* pawnAgent = pawnAgentMapper.get(actionEvent.entity);
		if (nullptr != pawnDir && nullptr != pawnAgent)
		{
			unsigned int dir = CalculateDirection(pawnDir, actionEvent.x - pawnPos->x, actionEvent.y - pawnPos->y);
			pawnDir->m_lastFaceDir = pawnDir->m_currentDir;
			pawnDir->m_currentDir = dir;
			
			pawnAgent->AddAction(PAT_ChangeDir);
		}
	}
		break;
	default:
		break;
	}

	return true;
}

unsigned int SystemPawnDirection::CalculateDirection(ComPawnDirection* pawnDir, float x, float y)
{
	if (nullptr == pawnDir)
		return Face_Right;

	float absTan = 2.0f;
	unsigned int dir = pawnDir->m_currentDir;
	if (x == 0.0f)
	{
		if (y == 0.0f)
		{
			dir = dir;
		}
		else if (y > 0.0f)
		{
			dir = Face_Up;
		}
		else // < 0
		{
			dir = Face_Down;
		}
	}
	else if (x > 0.0f)
	{
		float tan = y / x;
		if (tan > absTan)
			dir = Face_Up | Face_Right;
		else if (tan > -absTan && tan <= absTan)
			dir = Face_Right;
		else
			dir = Face_Down | Face_Right;
	}
	else// vec.x < 0.0f
	{
		float tan = y / x;
		if (tan > absTan)
			dir = Face_Down | Face_Left;
		else if (tan > -absTan && tan <= absTan)
			dir = Face_Left;
		else
			dir = Face_Up | Face_Left;
	}
	return dir;
}

void SystemPawnDirection::ChangeDirection(ComPawnDirection* dirCom, unsigned int dir)
{
	if (nullptr == dirCom)
		return;

	if (dir <= Face_Min || dir >= Face_Max)
		return;

	if (dir == Face_Turn)
	{
		dirCom->m_lastFaceDir = dirCom->m_currentDir;
		dirCom->m_currentDir = dirCom->m_currentDir & Face_Left ? Face_Right : Face_Left;
	}
	else
	{
		dirCom->m_lastFaceDir = dirCom->m_currentDir;
		dirCom->m_currentDir = dir;
	}
}