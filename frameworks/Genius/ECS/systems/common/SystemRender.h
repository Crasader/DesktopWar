
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComRenderRoot.h"

namespace Genius
{
	class SystemRender : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComRenderRoot>	animMapper;
		ComponentMapper<ComTransform>		transMapper;

	public:
		SystemRender()
		{
			SetComponentTypes<ComRenderRoot, ComTransform>();
		}
		virtual const char* GetName(){ return "SystemRender"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
	};
};
