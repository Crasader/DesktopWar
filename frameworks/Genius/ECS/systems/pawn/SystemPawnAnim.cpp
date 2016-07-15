
#include "SystemPawnAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

void SystemPawnAnim::Initialize()
{
	transMapper.init(*world);
	pawnAnimMapper.init(*world);
	transMapper.init(*world);
}

void SystemPawnAnim::ProcessEntity(Entity* e)
{
	ComPawnAnim* render = pawnAnimMapper.get(e);
	ComTransform* pos = transMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};

bool SystemPawnAnim::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	return true;
}

