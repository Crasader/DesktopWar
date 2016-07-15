#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComTarget.h"
#include "../../components//bullet/ComBulletAgent.h"

namespace Genius
{
	class SystemBulletTarget : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComTarget> targetMapper;
		ComponentMapper<ComBulletAgent> agentMapper;

	public:
		SystemBulletTarget()
		{
			SetComponentTypes<ComTransform, ComTarget, ComBulletAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletTarget"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};