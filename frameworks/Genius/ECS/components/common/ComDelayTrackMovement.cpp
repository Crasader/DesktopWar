
#include "ComDelayTrackMovement.h"
#include "ComTransform.h"
#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"


using namespace Genius;


COM_CREATE_FN_IMPL(ComDelayTrackMoving);

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
		ComTransform* pTarPosCom = pTarEntity->GetComponent<ComTransform>();
		if (pTarPosCom)
		{
			targetCachePosX = pTarPosCom->x;
			targetCachePosY = pTarPosCom->y;
		}
	}
	return IComponent::Init();
}