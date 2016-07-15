
#include "SystemTransform.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "pawn/action/ActionDefine.h"
#include "../../core/Entity.h"
#include "../../components/pawn/ComPawnAgent.h"


#include "2Ddef.h"
#include "data/auto/Role_cfg.hpp"

using namespace Genius;

void SystemTransform::Initialize()
{
	transMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_setPosition);
	EventManager::GetSingleton()->AddListener(this, Event_moveTo);
	EventManager::GetSingleton()->AddListener(this, Event_pawnStopMove);
	EventManager::GetSingleton()->AddListener(this, Event_velocityChanged);
	EventManager::GetSingleton()->AddListener(this, Event_turnBack);
	EventManager::GetSingleton()->AddListener(this, Event_turnTo);
}

void SystemTransform::ProcessEntity(Entity* e)
{
	auto tranCom = transMapper.get(e);
	tranCom->x += tranCom->vx * world->GetDeltaTime();
	tranCom->y += tranCom->vy * world->GetDeltaTime();
}

bool SystemTransform::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_setPosition:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		auto pos = transMapper.get(actionEvent.entity);
		if (pos)
		{
			pos->x = actionEvent.x;
			pos->y = actionEvent.y;
		}
	}
		break;
	case Event_moveTo:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		auto tran = transMapper.get(actionEvent.entity);
		if (tran)
		{
			//printf("mov to %f, %f\n", actionEvent.x, actionEvent.y);
			float dx = actionEvent.x - tran->x;
			float dy = actionEvent.y - tran->y;
			Point2D delta(dx, dy);
			delta.Normalize();
			
			float speed = 20;
			ComPawnAgent* pawnTemp = actionEvent.entity->GetComponent<ComPawnAgent>();
			if (pawnTemp)
			{
				speed = pawnTemp->m_roleCfg->moveSpeed;
			}
			tran->vx = delta.x * speed;
			tran->vy = delta.y * speed;

			EventManager::GetSingleton()->FireEvent(VelocityChangedEvent(actionEvent.entity, tran->vx, tran->vy));
		}
	}
		break;
	case Event_pawnStopMove:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		auto vel = transMapper.get(actionEvent.entity);
		if (vel)
		{
			vel->vx = 0;
			vel->vy = 0;
		}
	}
		break;
	case Event_velocityChanged:
	{
								  const VelocityChangedEvent & actionEvent = static_cast<const VelocityChangedEvent &>(event);
								  ComPawnAgent* pawnAgent = actionEvent.entity->GetComponent<ComPawnAgent>();
								  ComTransform* pawnDir = transMapper.get(actionEvent.entity);
								  if (nullptr != pawnAgent)
								  {
									  unsigned int dir = CalculateDirection(pawnDir->curDir, actionEvent.x, actionEvent.y);
									  pawnDir->lastDir = pawnDir->curDir;
									  pawnDir->curDir = dir;

									  pawnAgent->AddAction(PAT_ChangeDir);
								  }
	}
		break;
	case Event_turnBack:
	{
						   const TurnBackEvent & actionEvent = static_cast<const TurnBackEvent &>(event);
						   ComTransform* dirCom = transMapper.get(actionEvent.entity);
						   this->ChangeDirection(dirCom, Face_Turn);
						   ComPawnAgent* pawnAgent = actionEvent.entity->GetComponent<ComPawnAgent>();
						   if (nullptr != pawnAgent)
							   pawnAgent->AddAction(PAT_ChangeDir);
	}
		break;
	case Event_turnTo:
	{
						 const TurnToEvent & actionEvent = static_cast<const TurnToEvent &>(event);
						 ComTransform* pawnPos = transMapper.get(actionEvent.entity);
						 ComPawnAgent* pawnAgent = actionEvent.entity->GetComponent<ComPawnAgent>();
						 if (nullptr != pawnAgent)
						 {
							 unsigned int dir = CalculateDirection(pawnPos->curDir, actionEvent.x - pawnPos->x, actionEvent.y - pawnPos->y);
							 pawnPos->lastDir = pawnPos->curDir;
							 pawnPos->curDir = dir;

							 pawnAgent->AddAction(PAT_ChangeDir);
						 }
	}
		break;
	}

	return true;
}

int SystemTransform::CalculateDirection(int pawnDir, float x, float y)
{
	float absTan = 2.0f;
	int dir = pawnDir;
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

void SystemTransform::ChangeDirection(ComTransform* posCom, unsigned int dir)
{
	if (nullptr == posCom)
		return;

	if (dir <= Face_Min || dir >= Face_Max)
		return;

	if (dir == Face_Turn)
	{
		posCom->lastDir = posCom->curDir;
		posCom->curDir = posCom->curDir & Face_Left ? Face_Right : Face_Left;
	}
	else
	{
		posCom->lastDir = posCom->curDir;
		posCom->curDir = dir;
	}
}
