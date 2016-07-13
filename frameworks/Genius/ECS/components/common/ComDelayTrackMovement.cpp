
#include "ComDelayTrackMovement.h"
#include "ComPosition.h"
#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"


using namespace Genius;


void ComDelayTrackMoving::Create(int _targetID, float _delayTime)
{
	targetEntityID = _targetID;
	lifeTime = 0;
	delayTime = _delayTime;
	targetCachePosX = 1500;
	targetCachePosY = 100;
	isTracking = true;
};


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
	return IComponent::Init();
}