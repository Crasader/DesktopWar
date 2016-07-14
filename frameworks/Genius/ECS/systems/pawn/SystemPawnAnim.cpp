
#include "SystemPawnAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

void SystemPawnAnim::Initialize()
{
	positionMapper.init(*world);
	pawnAnimMapper.init(*world);
	pawnDirectionMapper.init(*world);
}

void SystemPawnAnim::ProcessEntity(Entity* e)
{
	ComPawnAnim* render = pawnAnimMapper.get(e);
	ComTransform* pos = positionMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};

bool SystemPawnAnim::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	return true;
}

