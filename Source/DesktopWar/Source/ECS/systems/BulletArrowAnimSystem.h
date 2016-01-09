#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletArrowAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BulletArrowAnimCom> animMapper;

	public:
		BulletArrowAnimSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BulletArrowAnimCom>();
		}
		virtual const char* GetName(){ return "BulletArrowAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &evnt);

	private:
		void OnBulletHit(IEventData const &evnt);
		void OnReachDest(IEventData const &evnt);
	};
};