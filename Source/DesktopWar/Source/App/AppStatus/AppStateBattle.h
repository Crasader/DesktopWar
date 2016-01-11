
#include "AppState.h"


class AppStateBattle : public AppState
{
public:
	AppStateBattle(WarApp* app);
	~AppStateBattle();

	virtual bool Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void GenerateLoadingList(LoadingManager* pLoadMgr);
};