#ifndef _NAVIGATION_SYSTEM_H_
#define _NAVIGATION_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"

#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/pawn/ComPawnNavigation.h"

namespace Genius
{
	class SystemPawnNavigation : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPawnNavigation>	navigationMapper;
		ComponentMapper<ComPosition>					positionMapper;
		ComponentMapper<ComVelocity>					velocityMapper;

	public:
		SystemPawnNavigation()
		{
			SetComponentTypes<ComPawnNavigation, ComPosition>();
		}
		virtual const char* GetName(){ return "SystemPawnNavigation"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

		virtual bool HandleEvent(IEventData const &event);

	};
};
#endif