
#include "SystemBoxCollider.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"

#include "2Ddef.h"
#include "data/auto/Role_cfg.hpp"
#include "app/GameDefine.h"
#include "app/GameUtils.h"

using namespace Genius;

void SystemBoxCollider::Initialize()
{
	transMapper.init(*world);
	colliderMapper.init(*world);
}

void SystemBoxCollider::ProcessEntity(Entity* pEntity)
{
	ComBoxCollider* colliderCom = colliderMapper.get(pEntity);
	if (colliderCom->isStatic)
		return;

	ComTransform* posCom = transMapper.get(pEntity);

	// 更新所在区域
	colliderCom->areaID = GameUtils::CalculateAreaID((int)posCom->x, (int)posCom->y);

	// 检查已经发生的碰撞是否还有效。
	auto it_find = m_colliderData.find(pEntity->GetId());
	if (it_find == m_colliderData.end())
	{
		std::list<int> new_vec;
		m_colliderData.insert(std::make_pair(pEntity->GetId(), new_vec));
	}

	auto collideList = m_colliderData[pEntity->GetId()];
	for (auto it = collideList.begin(); it != collideList.end(); )
	{
		int oldEntityID = *it;
		auto oldEntity = ECSWorld::GetSingleton()->GetEntity(oldEntityID);

		// invaild entity
		if (nullptr == oldEntity)
		{
			it = collideList.erase(it);
			continue;
		}
		
		ComTransform* oldTranCom = transMapper.get(oldEntity);
		ComBoxCollider* oldColliderCom = colliderMapper.get(oldEntity);
		if (!IsCollidedBetween(posCom, colliderCom, oldTranCom, oldColliderCom))
		{
			// exit collider
			it = collideList.erase(it);
			EventManager::GetSingleton()->FireEvent(ExitColliderEvent(pEntity, oldEntity));
			continue;
		}

		++it;
	}

	// new collide test
	auto activities = ECSWorld::GetSingleton()->GetEntitiesByTag(GameDefine::Tag_Collider);
	for (auto it = activities.begin(); it != activities.end(); it++)
	{
		int otherEntityID = it->first;
		auto otherEntity = it->second;

		bool alreadyCollided = false;
		for (auto it2 = collideList.begin(); it2 != collideList.end(); it2++)
		{
			if (*it2 == otherEntityID)
			{
				alreadyCollided = true;
				break;
			}
		}
		if (alreadyCollided)
			continue;


		ComTransform* otherPosCom = transMapper.get(otherEntity);
		ComBoxCollider* otherColliderCom = colliderMapper.get(otherEntity);
		// 先判断是否在相邻区域内
		bool isInAreas = GameUtils::IsInAreasAround(colliderCom->areaID, (int)otherPosCom->x, (int)otherPosCom->y);
		if (isInAreas && IsCollidedBetween(posCom, colliderCom, otherPosCom, otherColliderCom))
		{
			collideList.push_back(otherEntityID);
			EventManager::GetSingleton()->FireEvent(EnterColliderEvent(pEntity, otherEntity));
		}

	}

}

bool SystemBoxCollider::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}

bool SystemBoxCollider::IsCollidedBetween(ComTransform* posCom, ComBoxCollider* colliderCom, ComTransform* otherPosCom, ComBoxCollider* otherColliderCom)
{
	float distX = (posCom->x + colliderCom->centerX) - (otherPosCom->x + otherColliderCom->centerX);
	distX = distX > 0 ? distX : -distX;
	float distY = (posCom->y + colliderCom->centerY) - (otherPosCom->y + otherColliderCom->centerY);
	distY = distY > 0 ? distY : -distY;
	float widthPlus = colliderCom->width*0.5f + otherColliderCom->width*0.5f;
	float heightPlus = colliderCom->height*0.5f + otherColliderCom->height*0.5f;
	return (distX < widthPlus && distY < heightPlus);
}




