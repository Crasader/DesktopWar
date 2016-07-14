#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"

#include "../../components/bullet/ComBulletAnimEgg.h"

namespace Genius
{
	class SystemBulletEggAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> positionMapper;
		
		ComponentMapper<ComBulletAnimEgg> animMapper;

	public:
		SystemBulletEggAnim()
		{
			SetComponentTypes<ComTransform, ComBulletAnimEgg>();
		}
		virtual const char* GetName(){ return "SystemBulletEggAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &evnt);
	};
};