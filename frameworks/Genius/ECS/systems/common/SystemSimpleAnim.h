
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComAnimation.h"

namespace Genius
{
	class SystemSimpleAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComAnimation>	animMapper;
		ComponentMapper<ComTransform>		transMapper;

	public:
		SystemSimpleAnim()
		{
			SetComponentTypes<ComAnimation, ComTransform>();
		}
		virtual const char* GetName(){ return "SystemSimpleAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
	};
};
