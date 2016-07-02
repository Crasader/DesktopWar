#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  CocosApp : private cocos2d::Application
{
public:
    CocosApp();
    virtual ~CocosApp();

    virtual void initGLContextAttrs();
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();

	void setParent(HWND hwnd);
	cocos2d::Scene* GetScene(){ return m_pScene; }

	void RunScript();

	void PostRun();
	void StepRun();
	void AfterRun();

private:
	HWND		m_hwnd;
	cocos2d::Scene*	m_pScene;
};

#endif // _APP_DELEGATE_H_

