
#include "SystemSimpleAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void SystemSimpleAnim::Initialize()
{
	transMapper.init(*world);
	animMapper.init(*world);
}

void SystemSimpleAnim::ProcessEntity(Entity* e)
{
	ComAnimation* render = animMapper.get(e);
	ComTransform* pos = transMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};