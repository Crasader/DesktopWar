
#include "SystemTransform.h"

#include "../../core/Entity.h"
#include "scripting/JSInvoker.h"

#include "2Ddef.h"

using namespace Genius;

void SystemTransform::Initialize()
{
	transMapper.init(*world);
}

void SystemTransform::ProcessEntity(Entity* e)
{
	auto tranCom = transMapper.get(e);
	tranCom->x += tranCom->vx * world->GetDeltaTime();
	tranCom->y += tranCom->vy * world->GetDeltaTime();
	if (tranCom->haveDestPoint)
	{
		if (abs(tranCom->x - tranCom->destx) < 5 && abs(tranCom->y - tranCom->desty) < 5)
		{
			tranCom->SetVelocity(0, 0);
			JSInvoker::Invoke_PushEvent(e->GetId(), "Arrived");
		}
	}
}

bool SystemTransform::HandleEvent(IEventData const &event)
{
	return true;
}



