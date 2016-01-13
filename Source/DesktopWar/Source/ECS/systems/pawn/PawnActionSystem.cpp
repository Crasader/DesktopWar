// d:)
#include "PawnActionSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void PawnActionSystem::Initialize()
{
	pawnActionMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_startAction);
}

void PawnActionSystem::ProcessEntity(Entity* e)
{
	
};

bool PawnActionSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_startAction:
	{
		const ActionEvent & actionEvent = static_cast<const ActionEvent &>(event);
		PawnActionCom* action = pawnActionMapper.get(actionEvent.entity);
		if (action)
			action->StartAction(actionEvent.action);
	}
		break;
	default:
		break;
	}

	return true;
}