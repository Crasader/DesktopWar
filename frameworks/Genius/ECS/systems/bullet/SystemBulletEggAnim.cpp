
#include "SystemBulletEggAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletEggAnim::Initialize()
{
	transMapper.init(*world);
	animMapper.init(*world);

}

void SystemBulletEggAnim::ProcessEntity(Entity* pEntity)
{
	
}

bool SystemBulletEggAnim::HandleEvent(IEventData const &evnt)
{
	return true;
}
