// d:)
#include "PawnDirectionSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void PawnDirectionSystem::Initialize()
{
	pawnDirectionMapper.init(*world);
	positionMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_velocityChanged);
	EventManager::GetInstance().AddListener(this, Event_changeDirection);
	EventManager::GetInstance().AddListener(this, Event_turnTo);
}

void PawnDirectionSystem::ProcessEntity(Entity* e)
{
}

bool PawnDirectionSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	switch (eType)
	{
	case Event_velocityChanged:
	{
		const VelocityChangedEvent & actionEvent = static_cast<const VelocityChangedEvent &>(event);
		PawnDirectionCom* pawnDir = pawnDirectionMapper.get(actionEvent.entity);
		if (pawnDir)
		{
			unsigned int dir = CalculateDirection(pawnDir, actionEvent.x, actionEvent.y);
			pawnDir->m_lastFaceDir = pawnDir->m_faceDir;
			pawnDir->m_faceDir = dir;
			EventManager::GetInstance().FireEvent(UpdateActionEvent(actionEvent.entity));
		}
	}
		break;
	case Event_changeDirection:
	{
		const DirectionEvent & actionEvent = static_cast<const DirectionEvent &>(event);
		PawnDirectionCom* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->ChangeDirection(dirCom, actionEvent.dir);
		EventManager::GetInstance().FireEvent(UpdateActionEvent(actionEvent.entity));
	}
		break;
	case Event_turnTo:
	{
		const TurnToEvent & actionEvent = static_cast<const TurnToEvent &>(event);
		PawnDirectionCom* pawnDir = pawnDirectionMapper.get(actionEvent.entity);
		PositionCom* pawnPos = positionMapper.get(actionEvent.entity);
		if (pawnDir && pawnPos)
		{
			unsigned int dir = CalculateDirection(pawnDir, actionEvent.x - pawnPos->x, actionEvent.y - pawnPos->y);
			pawnDir->m_lastFaceDir = pawnDir->m_faceDir;
			pawnDir->m_faceDir = dir;
			EventManager::GetInstance().FireEvent(UpdateActionEvent(actionEvent.entity));
		}
	}
		break;
	default:
		break;
	}

	return true;
}

unsigned int PawnDirectionSystem::CalculateDirection(PawnDirectionCom* pawnDir, float x, float y)
{
	if (nullptr == pawnDir)
		return Face_Right;

	float absTan = 2.0f;
	unsigned int dir = pawnDir->m_faceDir;
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

void PawnDirectionSystem::ChangeDirection(PawnDirectionCom* dirCom, unsigned int dir)
{
	if (nullptr == dirCom)
		return;

	if (dir <= Face_Min || dir >= Face_Max)
		return;

	if (dir == Face_Turn)
	{
		dirCom->m_lastFaceDir = dirCom->m_faceDir;
		dirCom->m_faceDir = dirCom->m_faceDir & Face_Left ? Face_Right : Face_Left;
	}
	else
	{
		dirCom->m_lastFaceDir = dirCom->m_faceDir;
		dirCom->m_faceDir = dir;
	}
}