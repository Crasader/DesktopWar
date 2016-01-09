

class AppState;
class AppLoadingState;
class AppLaunchState;
class AppBattleState;

class WarApp
{
public:
	WarApp():
		m_pCurrentState(nullptr),
		m_pLastState(nullptr)
	{}

	~WarApp()
	{}

	bool			Init();
	void			Tick(float time);
	void			Destroy();
	void			ShowSetting(bool show);
	void			ShowAuthor(bool show);
	void			SpawnOne(int team = 0);
	void			KillAll();
	void			SwitchState(int state);
	void			SetCurrentState(AppState* state);

private:
	void OpenConsole();

private:
	AppState*					m_pCurrentState;
	AppState*					m_pLastState;
	AppLaunchState*		m_pLaunchState;
	AppLoadingState*	m_pLoadingState;
	AppBattleState*		m_pBattleState;
};