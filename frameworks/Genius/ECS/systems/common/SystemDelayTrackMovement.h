#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/common/ComDelayTrackMovement.h"

namespace Genius
{
	class SystemDelayTrackMovement : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComDelayTrackMoving> trackMapper;

	public:
		SystemDelayTrackMovement()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComDelayTrackMoving>();
		}
		virtual const char* GetName(){ return "SystemDelayTrackMovement"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};