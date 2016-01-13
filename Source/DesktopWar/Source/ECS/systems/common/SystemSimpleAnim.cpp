// d:)
#include "SystemSimpleAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void SystemSimpleAnim::Initialize()
{
	positionMapper.init(*world);
	animMapper.init(*world);
}

void SystemSimpleAnim::ProcessEntity(Entity* e)
{
	ComAnimation* render = animMapper.get(e);
	ComPosition* pos = positionMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};