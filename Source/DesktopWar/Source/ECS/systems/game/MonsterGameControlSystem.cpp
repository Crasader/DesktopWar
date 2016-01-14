
#include "MonsterGameControlSystem.h"
#include "../pawn/SystemPawnFight.h"
#include "../../core/SystemManager.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "entity/EntityCreators.h"
#include "app/GameDefine.h"

using namespace Genius;

void MonsterGameControlSystem::Initialize()
{
	gameControlMapper.init(*world);
	teamMapper.init(*world);
	positionMapper.init(*world);
}

void MonsterGameControlSystem::ProcessEntity(Entity* pEntity)
{
	return;

	MonsterGameControlCom* myGameControl = gameControlMapper.get(pEntity);
	ComTeam* myComTeam = teamMapper.get(pEntity);
	ComPosition* myComPosition = positionMapper.get(pEntity);

	float deltaTime = world->GetDeltaTime();
	myGameControl->gameTimePassed += deltaTime;

	int myTeamCount = 0;
	ImmutableBag<Entity*>* pawnActivities = world->GetGroupManager()->GetEntities(GameDefine::Group_Monster);
	if (pawnActivities)
		myTeamCount = pawnActivities->getCount();

	if (myTeamCount < MonsterGameControlCom::maxMonsterPopulation
		&& myGameControl->gameTimePassed > 1
		&& myGameControl->gameTimePassed - myGameControl->lastSpawnTime > 10)
	{
		myGameControl->lastSpawnTime = myGameControl->gameTimePassed;
		SpawnOne(myComPosition->x, myComPosition->y);
	}
};

Entity* MonsterGameControlSystem::SpawnOne(float x, float y)
{
	const int humTypeCount = 11;
	std::string humanNames[humTypeCount] = { "Goblin", "Orc", "Sahman", "Ogre", "Bandit", "Brigand", "Wulf", "Juggernaut", "NoxiousCreeeper", "ShadowArcher", "NoxiousSon" };

	static int humIndex = 0;
	Entity* entity = EntityCreator::CreatePawn(humanNames[humIndex++], x, y, Team_Monster);
	humIndex = humIndex % humTypeCount;

	return entity;
}