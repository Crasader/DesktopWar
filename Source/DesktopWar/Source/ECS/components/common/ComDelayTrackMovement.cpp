// d:)
#include "ComDelayTrackMovement.h"
#include "ComPosition.h"
#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"

using namespace Genius;

bool ComDelayTrackMoving::Init()
{
	Entity* pTarEntity = ECSWorld::GetSingleton()->GetEntity(targetEntityID);
	if (pTarEntity)
	{
		ComPosition* pTarPosCom = pTarEntity->GetComponent<ComPosition>();
		if (pTarPosCom)
		{
			targetCachePosX = pTarPosCom->x;
			targetCachePosY = pTarPosCom->y;
		}
	}
	return Component::Init();
}