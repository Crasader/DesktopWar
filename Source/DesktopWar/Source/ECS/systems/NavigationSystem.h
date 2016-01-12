#ifndef _NAVIGATION_SYSTEM_H_
#define _NAVIGATION_SYSTEM_H_

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"

#include "../components/common/PositionCom.h"
#include "../components/common/VelocityCom.h"
#include "../components/pawn/PawnNavigationCom.h"

namespace Genius
{
	class NavigationSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PawnNavigationCom>	navigationMapper;
		ComponentMapper<PositionCom>					positionMapper;
		ComponentMapper<VelocityCom>					velocityMapper;

	public:
		NavigationSystem()
		{
			SetComponentTypes<PawnNavigationCom, PositionCom>();
		}
		virtual const char* GetName(){ return "NavigationSystem"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

		virtual bool HandleEvent(IEventData const &event);

	};
};
#endif