
#include "CocosApp.h"
#include "app/Config.h"
#include "app/GameDefine.h"

#include "audio/include/SimpleAudioEngine.h"
#include "scripting/js-bindings/auto/jsb_cocos2dx_3d_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_3d_extension_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_builder_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_extension_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_navmesh_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_physics3d_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_spine_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_studio_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_ui_auto.hpp"
#include "scripting/js-bindings/auto/jsb_app_auto.hpp"
#include "scripting/js-bindings/manual/3d/jsb_cocos2dx_3d_manual.h"
#include "scripting/js-bindings/manual/chipmunk/js_bindings_chipmunk_registration.h"
#include "scripting/js-bindings/manual/cocosbuilder/js_bindings_ccbreader.h"
#include "scripting/js-bindings/manual/cocostudio/jsb_cocos2dx_studio_manual.h"
#include "scripting/js-bindings/manual/extension/jsb_cocos2dx_extension_manual.h"
#include "scripting/js-bindings/manual/jsb_opengl_registration.h"
#include "scripting/js-bindings/manual/localstorage/js_bindings_system_registration.h"
#include "scripting/js-bindings/manual/navmesh/jsb_cocos2dx_navmesh_manual.h"
#include "scripting/js-bindings/manual/network/XMLHTTPRequest.h"
#include "scripting/js-bindings/manual/network/jsb_socketio.h"
#include "scripting/js-bindings/manual/network/jsb_websocket.h"
#include "scripting/js-bindings/manual/physics3d/jsb_cocos2dx_physics3d_manual.h"
#include "scripting/js-bindings/manual/spine/jsb_cocos2dx_spine_manual.h"
#include "scripting/js-bindings/manual/ui/jsb_cocos2dx_ui_manual.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "scripting/js-bindings/auto/jsb_cocos2dx_experimental_video_auto.hpp"
#include "scripting/js-bindings/auto/jsb_cocos2dx_experimental_webView_auto.hpp"
#include "scripting/js-bindings/manual/experimental/jsb_cocos2dx_experimental_video_manual.h"
#include "scripting/js-bindings/manual/experimental/jsb_cocos2dx_experimental_webView_manual.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "scripting/js-bindings/auto/jsb_cocos2dx_audioengine_auto.hpp"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "cocos/scripting/js-bindings/manual/platform/android/CCJavascriptJavaBridge.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "cocos/scripting/js-bindings/manual/platform/ios/JavaScriptObjCBridge.h"
#endif


USING_NS_CC;

static void PVRFrameEnableControlWindow(bool bEnable);
static int register_all_packages();
static void register_js();

CocosApp::CocosApp()
{
}

CocosApp::~CocosApp()
{
	ScriptEngineManager::destroyInstance();
}

void CocosApp::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLView::setGLContextAttrs(glContextAttrs);
}

bool CocosApp::applicationDidFinishLaunching()
{
	// initialize director
	auto director = Director::getInstance();
	director->setDisplayStats(cfg_ShowFPS);
	director->setAnimationInterval(1.0f / 30);
	auto glview = director->getOpenGLView();
	if (!glview)
	{
		int width = GameDefine::viewWidth;// GetSystemMetrics(SM_CXSCREEN);
		int height = GameDefine::viewHeight;
		//cocos2d::Size designResolutionSize = cocos2d::Size((float)width, (float)height);
		//glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
		//glview->setFrameSize(designResolutionSize.width, designResolutionSize.height);
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		glview = cocos2d::GLViewImpl::create("DesktopWar");
#else
		glview = cocos2d::GLViewImpl::createWithRect("DesktopWar", Rect(0, 0, width, height));
#endif
		director->setOpenGLView(glview);
		director->setClearColor(Color4F(0, 0, 0, 0.0f));
	}

	register_all_packages();
	register_js();

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

void CocosApp::RunScript()
{
	ScriptEngineProtocol *engine = ScriptingCore::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
	ScriptingCore::getInstance()->runScript("res/script/main.js");
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

static int register_all_packages()
{
	return 0; //flag for packages manager
}

static void register_js()
{
	ScriptingCore* sc = ScriptingCore::getInstance();
	sc->addRegisterCallback(register_all_cocos2dx);
	sc->addRegisterCallback(register_cocos2dx_js_core);
	sc->addRegisterCallback(jsb_register_system);

	// extension can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_extension);
	sc->addRegisterCallback(register_all_cocos2dx_extension_manual);

	// chipmunk can be commented out to reduce the package
	sc->addRegisterCallback(jsb_register_chipmunk);
	// opengl can be commented out to reduce the package
	sc->addRegisterCallback(JSB_register_opengl);

	// builder can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_builder);
	sc->addRegisterCallback(register_CCBuilderReader);

	// ui can be commented out to reduce the package, attension studio need ui module
	sc->addRegisterCallback(register_all_cocos2dx_ui);
	sc->addRegisterCallback(register_all_cocos2dx_ui_manual);

	// studio can be commented out to reduce the package,
	sc->addRegisterCallback(register_all_cocos2dx_studio);
	sc->addRegisterCallback(register_all_cocos2dx_studio_manual);

	// spine can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_spine);
	sc->addRegisterCallback(register_all_cocos2dx_spine_manual);

	// XmlHttpRequest can be commented out to reduce the package
	sc->addRegisterCallback(MinXmlHttpRequest::_js_register);
	// websocket can be commented out to reduce the package
	sc->addRegisterCallback(register_jsb_websocket);
	// sokcet io can be commented out to reduce the package
	sc->addRegisterCallback(register_jsb_socketio);

	// 3d can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_3d);
	sc->addRegisterCallback(register_all_cocos2dx_3d_manual);

	// 3d extension can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_3d_extension);

#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
	// Physics 3d can be commented out to reduce the package
	sc->addRegisterCallback(register_all_cocos2dx_physics3d);
	sc->addRegisterCallback(register_all_cocos2dx_physics3d_manual);
#endif

#if CC_USE_NAVMESH
	sc->addRegisterCallback(register_all_cocos2dx_navmesh);
	sc->addRegisterCallback(register_all_cocos2dx_navmesh_manual);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	sc->addRegisterCallback(register_all_cocos2dx_experimental_video);
	sc->addRegisterCallback(register_all_cocos2dx_experimental_video_manual);
	sc->addRegisterCallback(register_all_cocos2dx_experimental_webView);
	sc->addRegisterCallback(register_all_cocos2dx_experimental_webView_manual);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	sc->addRegisterCallback(register_all_cocos2dx_audioengine);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	sc->addRegisterCallback(JavascriptJavaBridge::_js_register);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	sc->addRegisterCallback(JavaScriptObjCBridge::_js_register);
#endif

	// my api
	sc->addRegisterCallback(register_all_app);

	sc->start();
	sc->runScript("res/script/ccs/jsb_boot.js");
#if defined(COCOS2D_DEBUG) && (COCOS2D_DEBUG > 0)
	sc->enableDebugger();
#endif
	

}

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