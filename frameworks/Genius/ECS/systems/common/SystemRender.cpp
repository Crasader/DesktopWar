
#include "SystemRender.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void SystemRender::Initialize()
{
	transMapper.init(*world);
	animMapper.init(*world);
}

void SystemRender::ProcessEntity(Entity* e)
{
	ComRenderRoot* render = animMapper.get(e);
	ComTransform* pos = transMapper.get(e);
	if (render && render->rootNode)
		render->rootNode->setPosition(pos->x, pos->y);
};