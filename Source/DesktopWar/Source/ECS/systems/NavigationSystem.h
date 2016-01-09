#ifndef _NAVIGATION_SYSTEM_H_
#define _NAVIGATION_SYSTEM_H_

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/PawnComponents.h"
#include "../components/CommonCom.h"

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