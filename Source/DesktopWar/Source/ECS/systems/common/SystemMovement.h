#ifndef _MOVEMENT_SYSTEM_H_
#define _MOVEMENT_SYSTEM_H_

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"

namespace Genius
{
	class SystemMovement : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComPosition> positionMapper;

	public:
		SystemMovement()
		{
			SetComponentTypes<ComVelocity, ComPosition>();
		}
		virtual const char* GetName(){ return "SystemMovement"; }
		virtual void Initialize();

		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		unsigned int CalculateDirection(float x, float y);

	};
};

#endif