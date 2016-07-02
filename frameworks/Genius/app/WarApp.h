

/*class AppState;
class AppStateLoading;
class AppStateLaunch;
class AppStateBattle;*/

class WarApp
{
public:
	bool			Init();
	void			Tick(float time);
	void			Destroy();
	void			ShowSetting(bool show);
	void			ShowAuthor(bool show);
	void			SpawnOne(int team = 0);
	void			KillAll();
	//void			SwitchState(int state);
	//void			SetCurrentState(AppState* state);

private:
	void			_Update_Fast(float time);
	void			_Update_Normal(float time);
	void			_Update_Slow(float time);

private:
	/*AppState*					m_pCurrentState;
	AppState*					m_pLastState;
	AppStateLaunch*		m_pLaunchState;
	AppStateLoading*	m_pLoadingState;
	AppStateBattle*		m_pBattleState;*/
};