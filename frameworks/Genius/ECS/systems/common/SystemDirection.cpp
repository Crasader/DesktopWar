
#include "SystemDirection.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemDirection::Initialize()
{
	transMapper.init(*world);
	directionMapper.init(*world);
	renderMapper.init(*world);
}

void SystemDirection::ProcessEntity(Entity* pEntity)
{
	auto tranCom = transMapper.get(pEntity);
	auto dirCom = transMapper.get(pEntity);
	auto renderCom = renderMapper.get(pEntity);

	float rotation = 0;
	if (tranCom->vx == 0)
	{
		rotation = 90;
	}
	else if (tranCom->vx > 0)
	{
		if (tranCom->vy * tranCom->vx >= 0)
			rotation = -180 * atan(tranCom->vy / tranCom->vx) / PI;
		else if (tranCom->vy * tranCom->vx < 0)
			rotation = -180 * atan(tranCom->vy / tranCom->vx) / PI;
	}
	else
	{
		if (tranCom->vy * tranCom->vx >= 0)
			rotation = 180 - 180 * atan(tranCom->vy / tranCom->vx) / PI;
		else if (tranCom->vy * tranCom->vx < 0)
			rotation = 180 - 180 * atan(tranCom->vy / tranCom->x) / PI;
	}
	
	if (renderCom->rootNode)
		renderCom->rootNode->setRotation(rotation);
}

bool SystemDirection::HandleEvent(IEventData const &event)
{
	return true;
}
