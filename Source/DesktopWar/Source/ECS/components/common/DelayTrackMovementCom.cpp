// d:)
#include "DelayTrackMovementCom.h"
#include "PositionCom.h"
#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"

using namespace Genius;

bool DelayTrackMovingCom::Init()
{
	Entity* pTarEntity = ECSWorld::GetSingleton()->GetEntity(targetEntityID);
	if (pTarEntity)
	{
		PositionCom* pTarPosCom = pTarEntity->GetComponent<PositionCom>();
		if (pTarPosCom)
		{
			targetCachePosX = pTarPosCom->x;
			targetCachePosY = pTarPosCom->y;
		}
	}
	return Component::Init();
}