#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComVelocity.h"
#include "../../components/bullet/ComBulletAnimBase.h"

namespace Genius
{
	class SystemBulletAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComVelocity> velocityMapper;
		ComponentMapper<ComBulletAnimBase> animMapper;

	public:
		SystemBulletAnim()
		{
			SetComponentTypes<ComPosition, ComVelocity, ComBulletAnimBase>();
		}
		virtual const char* GetName(){ return "SystemBulletAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};