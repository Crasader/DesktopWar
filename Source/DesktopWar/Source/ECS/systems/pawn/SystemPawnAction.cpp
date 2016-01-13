// d:)
#include "SystemPawnAction.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

using namespace Genius;

void SystemPawnAction::Initialize()
{
	pawnActionMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_startAction);
}

void SystemPawnAction::ProcessEntity(Entity* e)
{
	
};

bool SystemPawnAction::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_startAction:
	{
		const ActionEvent & actionEvent = static_cast<const ActionEvent &>(event);
		ComPawnAction* action = pawnActionMapper.get(actionEvent.entity);
		if (action)
			action->StartAction(actionEvent.action);
	}
		break;
	default:
		break;
	}

	return true;
}