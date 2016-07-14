#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"

#include "../../components/bullet/ComBulletAnimBase.h"

namespace Genius
{
	class SystemBulletAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> positionMapper;
		
		ComponentMapper<ComBulletAnimBase> animMapper;

	public:
		SystemBulletAnim()
		{
			SetComponentTypes<ComTransform, ComBulletAnimBase>();
		}
		virtual const char* GetName(){ return "SystemBulletAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};