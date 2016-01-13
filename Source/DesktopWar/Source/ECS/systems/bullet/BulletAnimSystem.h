#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/VelocityCom.h"
#include "../../components/bullet/BulletBaseAnimCom.h"

namespace Genius
{
	class BulletAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<PositionCom> positionMapper;
		ComponentMapper<VelocityCom> velocityMapper;
		ComponentMapper<BulletBaseAnimCom> animMapper;

	public:
		BulletAnimSystem()
		{
			SetComponentTypes<PositionCom, VelocityCom, BulletBaseAnimCom>();
		}
		virtual const char* GetName(){ return "BulletAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};