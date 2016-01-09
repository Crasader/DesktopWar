
#pragma once

#include "../EntityProcessingSystem.h"
#include "../ComponentMapper.h"
#include "../components/CommonCom.h"

namespace Genius
{
	class SimpleAnimSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<SimpleAnimationCom>	animMapper;
		ComponentMapper<PositionCom>		positionMapper;

	public:
		SimpleAnimSystem()
		{
			SetComponentTypes<SimpleAnimationCom, PositionCom>();
		}
		virtual const char* GetName(){ return "SimpleAnimSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);
	};
};
