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
		ComponentMapper<ComTransform> transMapper;
		
		ComponentMapper<ComDelayTrackMovement> trackMapper;

	public:
		SystemDelayTrackMovement()
		{
			SetComponentTypes<ComTransform, ComDelayTrackMovement>();
		}
		virtual const char* GetName(){ return "SystemDelayTrackMovement"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	private:
		void _doWait(Entity* entity);
		void _doFindTarget(Entity* entity);
		void _doAdjustDirection(Entity* entity);
		void _doSpeedUp(Entity* entity);
		void _doExplode(Entity* entity);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};