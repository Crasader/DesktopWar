// d:)
#include "HumanGameControlSystem.h"
#include "../pawn/SystemPawnFight.h"
#include "../../core/SystemManager.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "entity/EntityCreators.h"
#include "app/GameDefine.h"

using namespace Genius;

void HumanGameControlSystem::Initialize()
{
	gameControlMapper.init(*world);
	teamMapper.init(*world);
	positionMapper.init(*world);
}

void HumanGameControlSystem::ProcessEntity(Entity* pEntity)
{
	return;
	HumanGameControlCom* myGameControl = gameControlMapper.get(pEntity);
	ComTeam* myComTeam = teamMapper.get(pEntity);
	ComPosition* myComPosition = positionMapper.get(pEntity);

	float deltaTime = world->GetDeltaTime();
	myGameControl->gameTimePassed += deltaTime;

	int myTeamCount = 0;
	//SystemPawnFight* pFightSys = world->GetSystemManager()->getSystem<SystemPawnFight>();
	//Bag<Entity*>& pawnActivities = pFightSys->getActivities();
	ImmutableBag<Entity*>* pawnActivities = world->GetGroupManager()->GetEntities(GameDefine::Group_Human);
	if (pawnActivities)
		myTeamCount = pawnActivities->getCount();

	if (myTeamCount < HumanGameControlCom::maxHumanPopulation
		&& myGameControl->gameTimePassed > 1
		&& myGameControl->gameTimePassed - myGameControl->lastSpawnTime > 8)
	{
		myGameControl->lastSpawnTime = myGameControl->gameTimePassed;
		SpawnOne(myComPosition->x, myComPosition->y);
	}
};

Entity* HumanGameControlSystem::SpawnOne(float x, float y)
{
	const int humTypeCount = 3;
	std::string humanNames[humTypeCount] = { "Jedi2", "Jedi", "Tkdo" };

	static int humIndex = 0;
	Entity* entity = EntityCreator::CreatePawn(humanNames[humIndex++], x, y, Team_Human);
	humIndex = humIndex % humTypeCount;

	return entity;
}