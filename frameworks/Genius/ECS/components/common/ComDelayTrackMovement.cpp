
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

void ComDelayTrackMovement::OnAwake()
{
	delayTime = 1.5f;
	targetCachePosX = 1500;
	targetCachePosY = 100;
	isTracking = true;
	currentState = Wait;
}