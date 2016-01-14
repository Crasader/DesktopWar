
#include "SystemBulletTarget.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "2Ddef.h"
#include "RoleDataMgr.h"

using namespace Genius;

void SystemBulletTarget::Initialize()
{
	positionMapper.init(*world);
	targetMapper.init(*world);
	templateMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void SystemBulletTarget::ProcessEntity(Entity* pEntity)
{
	//ComPosition* posCom = positionMapper.get(pEntity);
}

bool SystemBulletTarget::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}