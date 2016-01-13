#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/common/ComBezierMovement.h"


namespace Genius
{
	class SystemBezierMovement : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComBezierMovement> bezierMapper;

	public:
		SystemBezierMovement()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComBezierMovement>();
		}
		virtual const char* GetName(){ return "SystemBezierMovement"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		void OnStopMove(IEventData const &evnt);
	};
};