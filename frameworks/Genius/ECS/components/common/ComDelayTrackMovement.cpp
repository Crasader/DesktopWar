
#include "ComDelayTrackMovement.h"
#include "ComTransform.h"
#include "../../core/Entity.h"
#include "../../core/ECSWorld.h"


using namespace Genius;


COM_CREATE_FN_IMPL(ComDelayTrackMovement);

ComDelayTrackMovement::ComDelayTrackMovement() :
targetEntityID(Entity::InvalidID)
{
	lifeTime = 0;
	delayTime = 0;
	targetCachePosX = 0;
	targetCachePosY = 0;
	isTracking = false;
}

void ComDelayTrackMovement::Create(int _targetID, float _delayTime)
{
	/*_targetID = Entity::InvalidID;
	targetEntityID = _targetID;
	lifeTime = 0;*/
	delayTime = _delayTime;
	targetCachePosX = 1500;
	targetCachePosY = 100;
	isTracking = true;
};


void ComDelayTrackMovement::OnAwake()
{
	/*Entity* pTarEntity = ECSWorld::GetSingleton()->GetEntity(targetEntityID);
	if (pTarEntity)
	{
		ComTransform* pTarPosCom = pTarEntity->GetComponent<ComTransform>();
		if (pTarPosCom)
		{
			targetCachePosX = pTarPosCom->x;
			targetCachePosY = pTarPosCom->y;
		}
	}*/

}