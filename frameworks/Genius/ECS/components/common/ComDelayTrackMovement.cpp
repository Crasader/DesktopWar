
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
	shouldTurnLeft = false;

}

void ComDelayTrackMovement::OnAwake()
{
	delayTime = 2.0f;
	targetCachePosX = 1500;
	targetCachePosY = 100;
	shouldTurnLeft = true;
	currentState = Wait;
}