#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/bullet/ComBulletAnimEgg.h"

namespace Genius
{
	class SystemBulletEggAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComBulletAnimEgg> animMapper;

	public:
		SystemBulletEggAnim()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComBulletAnimEgg>();
		}
		virtual const char* GetName(){ return "SystemBulletEggAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &evnt);
	};
};