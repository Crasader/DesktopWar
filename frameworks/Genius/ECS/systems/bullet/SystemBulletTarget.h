#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComTarget.h"
#include "../../components//bullet/ComBulletAgent.h"

namespace Genius
{
	class SystemBulletTarget : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComTarget> targetMapper;
		ComponentMapper<ComBulletAgent> agentMapper;

	public:
		SystemBulletTarget()
		{
			SetComponentTypes<ComPosition, ComTarget, ComBulletAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletTarget"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};