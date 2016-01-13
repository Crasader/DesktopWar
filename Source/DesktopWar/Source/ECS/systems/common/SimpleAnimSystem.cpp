// d:)
#include "SimpleAnimSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void SimpleAnimSystem::Initialize()
{
	positionMapper.init(*world);
	animMapper.init(*world);
}

void SimpleAnimSystem::ProcessEntity(Entity* e)
{
	AnimationCom* render = animMapper.get(e);
	PositionCom* pos = positionMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};