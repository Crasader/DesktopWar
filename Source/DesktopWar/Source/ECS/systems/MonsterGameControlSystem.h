
#pragma once

#include "../core/EntityProcessingSystem.h"
#include "../core/ComponentMapper.h"
#include "../components/common/PositionCom.h"
#include "../components/common/TeamCom.h"
#include "../components/GamePlayCom.h"

namespace Genius
{
	class MonsterGameControlSystem : public EntityProcessingSystem
	{
	private:
		ComponentMapper<MonsterGameControlCom>	gameControlMapper;
		ComponentMapper<TeamCom>	teamMapper;
		ComponentMapper<PositionCom>	positionMapper;

	public:
		MonsterGameControlSystem()
		{
			SetComponentTypes<MonsterGameControlCom, TeamCom, PositionCom>();
		}
		virtual const char* GetName(){ return "MonsterGameControlSystem"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	private:
		Entity* SpawnOne(float x, float y);
	};
};
