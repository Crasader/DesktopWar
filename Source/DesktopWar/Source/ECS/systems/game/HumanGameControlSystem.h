
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/common/ComTeam.h"
#include "../../components/GamePlayCom.h"

namespace Genius
{
	class HumanGameControlSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<HumanGameControlCom>	gameControlMapper;
		ComponentMapper<ComTeam>	teamMapper;
		ComponentMapper<ComPosition>	positionMapper;

	public:
		HumanGameControlSystem()
		{
			SetComponentTypes<HumanGameControlCom, ComTeam, ComPosition>();
		}
		virtual const char* GetName(){ return "HumanGameControlSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	private:
		Entity* SpawnOne(float x, float y);
	};
};
