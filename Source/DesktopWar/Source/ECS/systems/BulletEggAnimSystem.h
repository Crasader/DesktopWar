#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"
#include "../components/BulletComponents.h"

namespace Genius
{
	class BulletEggAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BulletEggAnimCom> animMapper;

	public:
		BulletEggAnimSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BulletEggAnimCom>();
		}
		virtual const char* GetName(){ return "BulletEggAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &evnt);
	};
};