#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"

#include "../../components/common/ComBezierMovement.h"


namespace Genius
{
	class SystemBezierMovement : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		
		ComponentMapper<ComBezierMovement> bezierMapper;

	public:
		SystemBezierMovement()
		{
			SetComponentTypes<ComTransform, ComBezierMovement>();
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