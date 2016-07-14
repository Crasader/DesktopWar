
#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/common/ComTeam.h"
#include "../../components/GamePlayCom.h"

namespace Genius
{
	class MonsterGameControlSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<MonsterGameControlCom>	gameControlMapper;
		ComponentMapper<ComTeam>	teamMapper;
		ComponentMapper<ComTransform>	positionMapper;

	public:
		MonsterGameControlSystem()
		{
			SetComponentTypes<MonsterGameControlCom, ComTeam, ComTransform>();
		}
		virtual const char* GetName(){ return "MonsterGameControlSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	private:
		Entity* SpawnOne(float x, float y);
	};
};
