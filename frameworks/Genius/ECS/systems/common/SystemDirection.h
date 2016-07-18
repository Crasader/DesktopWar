#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComDirection.h"
#include "../../components/common/ComRenderRoot.h"

namespace Genius
{
	class SystemDirection : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComDirection> directionMapper;
		ComponentMapper<ComRenderRoot> renderMapper;

	public:
		SystemDirection()
		{
			SetComponentTypes<ComTransform, ComDirection, ComRenderRoot>();
		}
		virtual const char* GetName(){ return "SystemDirection"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);
	};
};