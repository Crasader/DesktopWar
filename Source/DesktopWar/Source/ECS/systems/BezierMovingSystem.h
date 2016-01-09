#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/CommonCom.h"

namespace Genius
{
	class BezierMovingSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BezierMovingCom> bezierMapper;

	public:
		BezierMovingSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BezierMovingCom>();
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