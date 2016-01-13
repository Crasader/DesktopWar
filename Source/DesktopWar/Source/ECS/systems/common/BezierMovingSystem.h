#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/VelocityCom.h"
#include "../../components/common/BezierMovementCom.h"


namespace Genius
{
	class BezierMovingSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BezierMovementCom> bezierMapper;

	public:
		BezierMovingSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BezierMovementCom>();
		}
		virtual const char* GetName(){ return "BezierMovingSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		void OnStopMove(IEventData const &evnt);
	};
};