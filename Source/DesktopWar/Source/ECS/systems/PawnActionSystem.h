#ifndef _PAWN_ACTION_SYSTEM_H_
#define _PAWN_ACTION_SYSTEM_H_

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/pawn/PawnActionCom.h"


namespace Genius
{
	class PawnActionSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PawnActionCom> pawnActionMapper;

	public:
		PawnActionSystem()
		{
			SetComponentTypes<PawnActionCom>();
		}
		virtual const char* GetName(){ return "PawnActionSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	};
};

#endif