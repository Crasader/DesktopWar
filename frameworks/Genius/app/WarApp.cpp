

#include <string>

#include "common/Log.h"
#include "common/Performance.h"
#include "common/TimeSystem.h"
#include "app/Config.h"
#include "WarApp.h"
#include "ConfigPool.h"
#include "gfx/gfx.h"
#include "gfx/CocosApp.h"
#include "pawn/bevtree/BehaviorsAndPreconditions.h"
#include "ECS/ecs.h"
#include "entity/EntityCreators.h"
#include "skill/SkillManager.h"
#include "skill/BuffManager.h"

#include "scripting/js-bindings/manual/ScriptingCore.h"



CocosApp cocosApp;

USING_NS_CC;
using namespace Genius;


bool WarApp::Init()
{
	do
	{
		cocosApp.PostRun();

		if (cfg_EnableConsole)
		{
			AllocConsole();
			freopen("CONIN$", "r", stdin);
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
		}

		Log::Info("WarApp::Init Begin...");

		Performance::Begin();

		TimeSystem::GetSingleton()->Init();
		cfg::ConfigPool::GetSingleton()->Init();
		SceneManager::GetSingleton()->Init();
		SystemStatusPanel::GetSingleton()->Init();
		AI::BHTree::BehaviorLoader::GetSingleton()->Init(gBehaviorMap, gPreconditionMap);
		ECSWorld::GetSingleton()->GetSystemManager()->Init();
		//GamePlay::GetSingleton().Init();

		cocosApp.RunScript();

		float dt = Performance::End();
		Log::Info("WarApp::Init End. Cost : %f s", dt);


		// test
		//int width = GetSystemMetrics(SM_CXSCREEN);
		//EntityCreator::CreateBornPoint(50, 133, Team_Monster);
		//EntityCreator::CreateBornPoint(width - 50, 133, Team_Human);

		//EntityCreator::CreatePawn("Militia", 100, 133, Team_Human);		EntityCreator::CreatePawn("Goblin", 240, 133, Team_Monster);
		//EntityCreator::CreatePawn("Footman", 200, 133, Team_Human);	EntityCreator::CreatePawn("Goblin", 340, 133, Team_Monster);
		//EntityCreator::CreatePawn("Knight", 300, 133, Team_Human);		EntityCreator::CreatePawn("Goblin", 440, 133, Team_Monster);
		//EntityCreator::CreatePawn("HolyKnight", 400, 133, Team_Human);	EntityCreator::CreatePawn("Barbarian", 540, 133, Team_Monster);
		//EntityCreator::CreatePawn("Barbarian", 500, 133, Team_Human);		EntityCreator::CreatePawn("Goblin", 640, 133, Team_Monster);

	} while (0);

	return true;
}

void WarApp::Tick(float time)
{
	float tickSec = time;
	TimeSystem::GetSingleton()->Tick(tickSec);
	SystemStatusPanel::GetSingleton()->ClearStatus();
	
	ECSWorld::GetSingleton()->LoopStart();
	ECSWorld::GetSingleton()->SetDeltaTime(tickSec);
	ECSWorld::GetSingleton()->Process();

	SkillManager::GetSingleton()->Update(tickSec);
	BuffManager::GetSingleton()->Update(tickSec);

	SceneManager::GetSingleton()->Update();

	cocosApp.StepRun();

	_Update_Fast(tickSec);
	_Update_Normal(tickSec);
	_Update_Slow(tickSec);

}

void WarApp::Destroy()
{
	Genius::EntityManager * em = ECSWorld::GetSingleton()->GetEntityManager();
	em->RemoveAllEntities();

	AI::BHTree::BehaviorLoader::GetSingleton()->Destroy();
	cfg::ConfigPool::GetSingleton()->Destroy();

	cocosApp.AfterRun();
	//GamePlay::GetSingleton().Destroy();

	if (cfg_EnableConsole)
	{
		FreeConsole();
	}
}

void WarApp::_Update_Fast(float time)
{

}

void WarApp::_Update_Normal(float time)
{
	static float timePassed = 0;
	timePassed += time;
	if (timePassed < 0.2f)
		return;

	ScriptingCore::getInstance()->evalString("Game.OnUpdate(0.2)");
	
	// set zero
	timePassed = 0;
}

void WarApp::_Update_Slow(float time)
{
	static float timePassed = 0;
	timePassed += time;
	if (timePassed < 1.0f)
		return;

	//ScriptingCore::getInstance()->evalString("Game.OnUpdate(1.0)");

	// set zero
	timePassed = 0;
}

