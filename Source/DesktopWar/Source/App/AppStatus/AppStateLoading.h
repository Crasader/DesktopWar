
#include "AppState.h"



class RollNumberLabel;
namespace cocos2d
{
	class Node;
	class Label;
}


class AppStateLoading : public AppState
{
public:

	AppStateLoading(WarApp* app);
	~AppStateLoading();

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