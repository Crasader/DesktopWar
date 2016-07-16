#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/pawn/ComPawnAgent.h"


namespace Genius
{
	class SystemBulletTarget : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComPawnAgent> agentMapper;

	public:
		SystemBulletTarget()
		{
			SetComponentTypes<ComTransform, ComPawnAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletTarget"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};