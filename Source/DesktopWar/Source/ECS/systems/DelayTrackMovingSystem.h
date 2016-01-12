#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/CommonCom.h"

namespace Genius
{
	class DelayTrackMovingSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<DelayTrackMovingCom> trackMapper;

	public:
		DelayTrackMovingSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, DelayTrackMovingCom>();
		}
		virtual const char* GetName(){ return "DelayTrackMovingSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};