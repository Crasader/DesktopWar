// d:)
#include "BoxColliderSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../../pawn/PawnDefines.h"
#include "../Entity.h"
#include "../components/PawnComponents.h"
#include "2Ddef.h"
#include "RoleDataMgr.h"
#include "GameDefine.h"
#include "GameUtils.h"

using namespace Genius;

void BoxColliderSystem::Initialize()
{
	positionMapper.init(*world);
	colliderMapper.init(*world);
	handlerMapper.init(*world);
	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void BoxColliderSystem::ProcessEntity(Entity* pEntity)
{
	BoxColliderCom* colliderCom = colliderMapper.get(pEntity);
	if (!colliderCom->positive)
		return;

	PositionCom* posCom = positionMapper.get(pEntity);
	ColliderHandlerCom* handlerCom = handlerMapper.get(pEntity);

	// 更新所在区域
	colliderCom->areaID = GameUtils::CalculateAreaID((int)posCom->x, (int)posCom->y);

	// 检查已经发生的碰撞是否还有效。
	for (int i = 0; i < BoxColliderCom::MaxCount; ++i)
	{
		if (colliderCom->collideIDs[i] == Entity::InvalidID)
			continue;
		Entity* pOldCollidedEntity = ECSWorld::GetSingleton()->GetEntity(colliderCom->collideIDs[i]);
		if (nullptr == pOldCollidedEntity)
		{
			colliderCom->collideIDs[i] = Entity::InvalidID;
			continue;
		}
		
		PositionCom* oldPosCom = positionMapper.get(pOldCollidedEntity);
		BoxColliderCom* oldColliderCom = colliderMapper.get(pOldCollidedEntity);
		if (!IsCollidedBetween(posCom, colliderCom, oldPosCom, oldColliderCom))
		{
			// exit
			colliderCom->collideIDs[i] = Entity::InvalidID;
			if (handlerCom->_exitColliderListener)
				handlerCom->_exitColliderListener(pEntity->GetId(), pOldCollidedEntity->GetId());
		}
	}

	Bag<Entity*>& activities = GetActivities();
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* pOtherEntity = activities.get(i);
		if (pEntity == pOtherEntity)
			continue;
		
		PositionCom* otherPosCom = positionMapper.get(pOtherEntity);
		BoxColliderCom* otherColliderCom = colliderMapper.get(pOtherEntity);
		// 先判断是否在相邻区域内
		bool isInAreas = GameUtils::IsInAreasAround(colliderCom->areaID, (int)otherPosCom->x, (int)otherPosCom->y);
		if (isInAreas && IsCollidedBetween(posCom, colliderCom, otherPosCom, otherColliderCom))
		{
			bool isAlreadyCollided = IsAlreadyCollided(colliderCom, pOtherEntity);
			if (false == isAlreadyCollided)
			{
				for (int j = 0; j < BoxColliderCom::MaxCount; ++j)
				{
					if (colliderCom->collideIDs[j] == Entity::InvalidID)
					{
						colliderCom->collideIDs[j] = pOtherEntity->GetId();
						if (handlerCom->_enterColliderListener)
							handlerCom->_enterColliderListener(pEntity->GetId(), pOtherEntity->GetId());
						break;
					}
				}
			}
		}
	}
}

bool BoxColliderSystem::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}

bool BoxColliderSystem::IsCollidedBetween(PositionCom* posCom, BoxColliderCom* colliderCom, PositionCom* otherPosCom, BoxColliderCom* otherColliderCom)
{
	float distX = (posCom->x + colliderCom->centerX) - (otherPosCom->x + otherColliderCom->centerX);
	distX = distX > 0 ? distX : -distX;
	float distY = (posCom->y + colliderCom->centerY) - (otherPosCom->y + otherColliderCom->centerY);
	distY = distY > 0 ? distY : -distY;
	float widthPlus = colliderCom->width*0.5f + otherColliderCom->width*0.5f;
	float heightPlus = colliderCom->height*0.5f + otherColliderCom->height*0.5f;
	return (distX < widthPlus && distY < heightPlus);
}

bool BoxColliderSystem::IsAlreadyCollided(BoxColliderCom* colliderCom, Entity* entity2)
{
	int id = entity2->GetId();
	for (int j = 0; j < BoxColliderCom::MaxCount; ++j)
	{
		if (colliderCom->collideIDs[j] == id)
			return true;
	}
	return false;
}