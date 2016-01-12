#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/common/PositionCom.h"
#include "../components/common/VelocityCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletBombAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BulletBombAnimCom> animMapper;

	public:
		BulletBombAnimSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BulletBombAnimCom>();
		}
		virtual const char* GetName(){ return "BulletBombAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		void OnBulletHit(IEventData const &evnt);
		void OnReachDest(IEventData const &evnt);
	};
};