
#include "SystemEntityScript.h"
#include "event/EventManager.h"
#include "../EntityEvents.h"

using namespace Genius;

void SystemEntityScript::Initialize()
{
	scriptMapper.init(*world);
}

void SystemEntityScript::ProcessEntity(Entity* entity)
{
	ComEntityScript* scriptCom = scriptMapper.get(entity);
	
};