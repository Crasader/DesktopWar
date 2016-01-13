#ifndef _PAWN_ACTION_SYSTEM_H_
#define _PAWN_ACTION_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/pawn/ComPawnAction.h"


namespace Genius
{
	class SystemPawnAction : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnAction> pawnActionMapper;

	public:
		SystemPawnAction()
		{
			SetComponentTypes<ComPawnAction>();
		}
		virtual const char* GetName(){ return "SystemPawnAction"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};

#endif