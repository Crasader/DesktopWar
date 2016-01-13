
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/PositionCom.h"
#include "../../components/common/AnimationCom.h"

namespace Genius
{
	class SimpleAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<AnimationCom>	animMapper;
		ComponentMapper<PositionCom>		positionMapper;

	public:
		SimpleAnimSystem()
		{
			SetComponentTypes<AnimationCom, PositionCom>();
		}
		virtual const char* GetName(){ return "SimpleAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
	};
};
