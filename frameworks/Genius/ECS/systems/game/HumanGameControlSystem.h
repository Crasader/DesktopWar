
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComTeam.h"
#include "../../components/GamePlayCom.h"

namespace Genius
{
	class HumanGameControlSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<HumanGameControlCom>	gameControlMapper;
		ComponentMapper<ComTeam>	teamMapper;
		ComponentMapper<ComTransform>	positionMapper;

	public:
		HumanGameControlSystem()
		{
			SetComponentTypes<HumanGameControlCom, ComTeam, ComTransform>();
		}
		virtual const char* GetName(){ return "HumanGameControlSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	private:
		Entity* SpawnOne(float x, float y);
	};
};
