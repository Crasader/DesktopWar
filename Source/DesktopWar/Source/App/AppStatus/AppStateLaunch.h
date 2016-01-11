
#include "AppState.h"


class AppStateLaunch : public AppState
{
public:
	AppStateLaunch(WarApp* app);
	~AppStateLaunch();

	virtual bool Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr);

	void FadeOutCallback();

private:
	float		m_timePassed;
	bool		m_soldierSpawned;
	bool		m_isFadeOut;
};