
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComAnimation.h"

namespace Genius
{
	class SystemSimpleAnim : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComAnimation>	animMapper;
		ComponentMapper<ComPosition>		positionMapper;

	public:
		SystemSimpleAnim()
		{
			SetComponentTypes<ComAnimation, ComPosition>();
		}
		virtual const char* GetName(){ return "SystemSimpleAnim"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
	};
};
