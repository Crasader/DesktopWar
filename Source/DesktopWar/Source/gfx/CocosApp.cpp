// d:)
#include "CocosApp.h"
#include "app/Config.h"
#include "app/GameDefine.h"

USING_NS_CC;

static void PVRFrameEnableControlWindow(bool bEnable);

CocosApp::CocosApp()
{
}

CocosApp::~CocosApp()
{
}

void CocosApp::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
	return 0; //flag for packages manager
}

bool CocosApp::applicationDidFinishLaunching()
{
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview)
	{
		glview = GLViewImpl::create("DesktopWar");
		director->setOpenGLView(glview);
		director->setClearColor(Color4F(0, 0, 0, 0.0f));
	}
	
	int width = GameDefine::viewWidth;// GetSystemMetrics(SM_CXSCREEN);
	int height = GameDefine::viewHeight;
	cocos2d::Size designResolutionSize = cocos2d::Size((float)width, (float)height);

	director->setDisplayStats(cfg_ShowFPS);
	director->setAnimationInterval(1.0 / 30);
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	glview->setFrameSize(designResolutionSize.width, designResolutionSize.height);

	register_all_packages();

	m_pScene = cocos2d::Scene::create();
	director->runWithScene(m_pScene);

	return true;
}

void CocosApp::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
}

void CocosApp::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
}

void CocosApp::setParent(HWND hwnd)
{
	m_hwnd = hwnd;
}

void CocosApp::PostRun()
{
	PVRFrameEnableControlWindow(false);
	initGLContextAttrs();
	applicationDidFinishLaunching();
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	glview->retain();
}

void CocosApp::AfterRun()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (glview->isOpenGLReady())
	{
		director->end();
		director->mainLoop();
		director = nullptr;
	}
	glview->release();
}

void CocosApp::StepRun()
{
	auto director = Director::getInstance();
	//auto glview = director->getOpenGLView();
	director->mainLoop();
	//glview->pollEvents();
}

//////////////////////////////////////////////////////////////////////////
// Local function
//////////////////////////////////////////////////////////////////////////
static void PVRFrameEnableControlWindow(bool bEnable)
{
	HKEY hKey = 0;

	// Open PVRFrame control key, if not exist create it.
	if (ERROR_SUCCESS != RegCreateKeyExW(HKEY_CURRENT_USER,
		L"Software\\Imagination Technologies\\PVRVFRame\\STARTUP\\",
		0,
		0,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		0,
		&hKey,
		nullptr))
	{
		return;
	}

	const WCHAR* wszValue = L"hide_gui";
	const WCHAR* wszNewData = (bEnable) ? L"NO" : L"YES";
	WCHAR wszOldData[256] = { 0 };
	DWORD   dwSize = sizeof(wszOldData);
	LSTATUS status = RegQueryValueExW(hKey, wszValue, 0, nullptr, (LPBYTE)wszOldData, &dwSize);
	if (ERROR_FILE_NOT_FOUND == status              // the key not exist
		|| (ERROR_SUCCESS == status                 // or the hide_gui value is exist
		&& 0 != wcscmp(wszNewData, wszOldData)))    // but new data and old data not equal
	{
		dwSize = sizeof(WCHAR)* (wcslen(wszNewData) + 1);
		RegSetValueEx(hKey, wszValue, 0, REG_SZ, (const BYTE *)wszNewData, dwSize);
	}

	RegCloseKey(hKey);
}