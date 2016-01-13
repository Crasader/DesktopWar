#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/VelocityCom.h"
#include "../../components/bullet/BulletEggAnimCom.h"

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