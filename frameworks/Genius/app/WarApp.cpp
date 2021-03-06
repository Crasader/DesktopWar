

#include <string>
#include <thread>
#include <mutex>

#include "common/Log.h"
#include "common/Performance.h"
#include "common/TimeSystem.h"

#include "WarApp.h"
#include "ConfigPool.h"
#include "gfx/gfx.h"
#include "gfx/CocosApp.h"
#include "ECS/ecs.h"
#include "skill/SkillManager.h"
#include "skill/BuffManager.h"

#include "scripting/JSInvoker.h"


std::mutex gMutex;
CocosApp gCocosApp;

USING_NS_CC;
using namespace Genius;

const bool	cfg_EnableConsole = true;

bool WarApp::Init()
{
	do
	{

		gCocosApp.PostRun();

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
		ECSWorld::GetSingleton()->GetSystemManager()->Init();

		gCocosApp.RunScript();

		//AudioManager::GetSingleton()->PlayBGM("res/audio/main_theme.mp3");

		Log::Info("WarApp::Init End. Cost : %f s", Performance::End());

		//std::thread tLogic(&WarApp::_logicThread, this);
		//tLogic.detach();

		//cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/anim/npc0.plist");

		this->running = true;

	} while (0);

	return true;
}

void WarApp::Tick(float timeSecond)
{
	TimeSystem::GetSingleton()->Tick(timeSecond);
	SystemStatusPanel::GetSingleton()->ClearStatus();
	
	ECSWorld::GetSingleton()->LoopStart();
	ECSWorld::GetSingleton()->SetDeltaTime(timeSecond);
	ECSWorld::GetSingleton()->Process();

	SkillManager::GetSingleton()->Update(timeSecond);
	BuffManager::GetSingleton()->Update(timeSecond);

	SceneManager::GetSingleton()->Update();

	gCocosApp.StepRun();

	_Update_Normal(timeSecond);
	_Update_Slow(timeSecond);

}

void WarApp::Destroy()
{
	this->running = false;

	Genius::EntityManager * em = ECSWorld::GetSingleton()->GetEntityManager();
	em->RemoveAllEntities();

	cfg::ConfigPool::GetSingleton()->Destroy();

	gCocosApp.AfterRun();
	
	AudioManager::GetSingleton()->Release();

	if (cfg_EnableConsole)
	{
		FreeConsole();
	}
}

void WarApp::_logicThread()
{
	return;
	while (this->running)
	{
		gMutex.lock();
		{
			///
		}
		gMutex.unlock();
	}
}

void WarApp::_Update_Normal(float time)
{
	static float timePassed = 0;
	timePassed += time;
	if (timePassed < 0.1f)
		return;
		
	JSInvoker::Invoke_Update(time);
	
	timePassed = 0;
}

void WarApp::_Update_Slow(float time)
{
	static float timePassed = 0;
	timePassed += time;
	if (timePassed < 1.0f)
		return;

	JSInvoker::Invoke_LongUpdate(timePassed);

	timePassed = 0;
}

