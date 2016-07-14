#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"

#include "../../components/common/ComDelayTrackMovement.h"

namespace Genius
{
	class SystemDelayTrackMovement : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> positionMapper;
		
		ComponentMapper<ComDelayTrackMoving> trackMapper;

	public:
		SystemDelayTrackMovement()
		{
			SetComponentTypes<ComTransform, ComDelayTrackMoving>();
		}
		virtual const char* GetName(){ return "SystemDelayTrackMovement"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};