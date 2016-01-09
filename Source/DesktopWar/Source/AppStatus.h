
#pragma once

#include "cocos2d.h"

class WarApp;
class LoadingManager;
class RollNumberLabel;
namespace cocos2d
{
	class Node;
	class Label;
}

class AppState
{
public:
	enum StateType
	{
		eUnknown,
		eLaunch,
		eLoading,
		eBattle,
	};

public:
	AppState(WarApp* app) :
		m_stateType(eUnknown),
		m_pApp(app)
	{}

	virtual ~AppState(){}

	virtual bool Init(){ return true; }
	virtual void Update(float time){}
	virtual void Destroy(){}
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr){}

	void SetApp(WarApp* app){ m_pApp = app; }

protected:
	StateType		m_stateType;
	WarApp*		m_pApp;
};

namespace cocos2d
{
	class Texture2D;
	class Ref;
};
class AppLaunchState : public AppState, public cocos2d::Ref
{
public:
	AppLaunchState(WarApp* app);
	~AppLaunchState();

	virtual bool Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr);

	void FadeOutCallback();

private:
	cocos2d::Texture2D* m_pScreenTexture;
	float		m_timePassed;
	bool		m_soldierSpawned;
	bool		m_isFadeOut;
};

class AppLoadingState : public AppState
{
public:
	AppLoadingState(WarApp* app);
	~AppLoadingState();

	virtual bool Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr);

	void StartLoading(AppState* pPrevState, AppState* pNextState);
	void SetPercent(int percent);

private:
	LoadingManager*		m_pLoadingManager;
	AppState*					m_prevState;
	AppState*					m_nextState;
	cocos2d::Node*		m_pUIRoot;
	RollNumberLabel*		m_percentLabel;
};

class AppBattleState : public AppState
{
public:
	AppBattleState(WarApp* app);
	~AppBattleState();

	virtual bool Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr);
};






