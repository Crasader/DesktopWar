
#pragma once


class WarApp;
class LoadingManager;

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

	AppState(WarApp* app);

	virtual ~AppState();

	virtual bool Init() = 0;

	virtual void Update(float time) = 0;

	virtual void Destroy() = 0;

	virtual void GenerateLoadingList(LoadingManager* pLoadMgr) = 0;

	void SetApp(WarApp* app){ m_pApp = app; }

protected:

	StateType		m_stateType;

	WarApp*		m_pApp;

};