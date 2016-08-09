#include "scripting/js-bindings/auto/jsb_app_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "JSBHeaders.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
JSClass  *jsb_Log_class;
JSObject *jsb_Log_prototype;

bool js_app_Log_print(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_Log_print : Error processing arguments");
        Log::print(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_Log_print : wrong number of arguments");
    return false;
}


void js_register_app_Log(JSContext *cx, JS::HandleObject global) {
    jsb_Log_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Log_class->name = "Log";
    jsb_Log_class->addProperty = JS_PropertyStub;
    jsb_Log_class->delProperty = JS_DeletePropertyStub;
    jsb_Log_class->getProperty = JS_PropertyStub;
    jsb_Log_class->setProperty = JS_StrictPropertyStub;
    jsb_Log_class->enumerate = JS_EnumerateStub;
    jsb_Log_class->resolve = JS_ResolveStub;
    jsb_Log_class->convert = JS_ConvertStub;
    jsb_Log_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("print", js_app_Log_print, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Log_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Log_class,
        dummy_constructor<Log>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Log_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Log"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Log>(cx, jsb_Log_class, proto, JS::NullPtr());
}

JSClass  *jsb_JSInvoker_class;
JSObject *jsb_JSInvoker_prototype;

bool js_app_JSInvoker_Invoke_Update(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_Update : Error processing arguments");
        JSInvoker::Invoke_Update(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_JSInvoker_Invoke_Update : wrong number of arguments");
    return false;
}

bool js_app_JSInvoker_Invoke_ModifyEntityAttr(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_ModifyEntityAttr : Error processing arguments");
        JSInvoker::Invoke_ModifyEntityAttr(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 5) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        int arg4 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_int32(cx, args.get(4), (int32_t *)&arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_ModifyEntityAttr : Error processing arguments");
        JSInvoker::Invoke_ModifyEntityAttr(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_JSInvoker_Invoke_ModifyEntityAttr : wrong number of arguments");
    return false;
}

bool js_app_JSInvoker_Invoke_ArmatureMovementEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        const char* arg2 = nullptr;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        std::string arg2_tmp; ok &= jsval_to_std_string(cx, args.get(2), &arg2_tmp); arg2 = arg2_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_ArmatureMovementEvent : Error processing arguments");
        JSInvoker::Invoke_ArmatureMovementEvent(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_JSInvoker_Invoke_ArmatureMovementEvent : wrong number of arguments");
    return false;
}

bool js_app_JSInvoker_Invoke_ArmatureFrameEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        const char* arg1 = nullptr;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_ArmatureFrameEvent : Error processing arguments");
        JSInvoker::Invoke_ArmatureFrameEvent(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_JSInvoker_Invoke_ArmatureFrameEvent : wrong number of arguments");
    return false;
}

bool js_app_JSInvoker_Invoke_LongUpdate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_JSInvoker_Invoke_LongUpdate : Error processing arguments");
        JSInvoker::Invoke_LongUpdate(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_JSInvoker_Invoke_LongUpdate : wrong number of arguments");
    return false;
}


void js_register_app_JSInvoker(JSContext *cx, JS::HandleObject global) {
    jsb_JSInvoker_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_JSInvoker_class->name = "JSInvoker";
    jsb_JSInvoker_class->addProperty = JS_PropertyStub;
    jsb_JSInvoker_class->delProperty = JS_DeletePropertyStub;
    jsb_JSInvoker_class->getProperty = JS_PropertyStub;
    jsb_JSInvoker_class->setProperty = JS_StrictPropertyStub;
    jsb_JSInvoker_class->enumerate = JS_EnumerateStub;
    jsb_JSInvoker_class->resolve = JS_ResolveStub;
    jsb_JSInvoker_class->convert = JS_ConvertStub;
    jsb_JSInvoker_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("Invoke_Update", js_app_JSInvoker_Invoke_Update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Invoke_ModifyEntityAttr", js_app_JSInvoker_Invoke_ModifyEntityAttr, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Invoke_ArmatureMovementEvent", js_app_JSInvoker_Invoke_ArmatureMovementEvent, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Invoke_ArmatureFrameEvent", js_app_JSInvoker_Invoke_ArmatureFrameEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Invoke_LongUpdate", js_app_JSInvoker_Invoke_LongUpdate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_JSInvoker_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_JSInvoker_class,
        dummy_constructor<JSInvoker>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_JSInvoker_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "JSInvoker"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<JSInvoker>(cx, jsb_JSInvoker_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_TimeSystem_class;
JSObject *jsb_Genius_TimeSystem_prototype;

bool js_app_TimeSystem_TimeSinceStart(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        double ret = Genius::TimeSystem::TimeSinceStart();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_TimeSystem_TimeSinceStart : wrong number of arguments");
    return false;
}

bool js_app_TimeSystem_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::TimeSystem* cobj = new (std::nothrow) Genius::TimeSystem();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::TimeSystem>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::TimeSystem"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_Genius_TimeSystem_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (TimeSystem)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::TimeSystem *nobj = static_cast<Genius::TimeSystem *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_TimeSystem(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_TimeSystem_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_TimeSystem_class->name = "TimeSystem";
    jsb_Genius_TimeSystem_class->addProperty = JS_PropertyStub;
    jsb_Genius_TimeSystem_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_TimeSystem_class->getProperty = JS_PropertyStub;
    jsb_Genius_TimeSystem_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_TimeSystem_class->enumerate = JS_EnumerateStub;
    jsb_Genius_TimeSystem_class->resolve = JS_ResolveStub;
    jsb_Genius_TimeSystem_class->convert = JS_ConvertStub;
    jsb_Genius_TimeSystem_class->finalize = js_Genius_TimeSystem_finalize;
    jsb_Genius_TimeSystem_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("TimeSinceStart", js_app_TimeSystem_TimeSinceStart, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Genius_TimeSystem_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_TimeSystem_class,
        js_app_TimeSystem_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_TimeSystem_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "TimeSystem"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::TimeSystem>(cx, jsb_Genius_TimeSystem_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_SceneManager_class;
JSObject *jsb_Genius_SceneManager_prototype;

bool js_app_SceneManager_ShakeScene(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SceneManager* cobj = (Genius::SceneManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SceneManager_ShakeScene : Invalid Native Object");
    if (argc == 0) {
        cobj->ShakeScene();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_ShakeScene : Error processing arguments");
        cobj->ShakeScene(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        int arg0 = 0;
        double arg1 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_ShakeScene : Error processing arguments");
        cobj->ShakeScene(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_SceneManager_ShakeScene : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_SceneManager_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SceneManager* cobj = (Genius::SceneManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SceneManager_Init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->Init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_SceneManager_Init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_SceneManager_Update(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SceneManager* cobj = (Genius::SceneManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SceneManager_Update : Invalid Native Object");
    if (argc == 0) {
        cobj->Update();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_SceneManager_Update : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_SceneManager_AddToMapLayer(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SceneManager* cobj = (Genius::SceneManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SceneManager_AddToMapLayer : Invalid Native Object");
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_AddToMapLayer : Error processing arguments");
        cobj->AddToMapLayer(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        cocos2d::Node* arg0 = nullptr;
        double arg1 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_AddToMapLayer : Error processing arguments");
        cobj->AddToMapLayer(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 3) {
        cocos2d::Node* arg0 = nullptr;
        double arg1 = 0;
        double arg2 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_AddToMapLayer : Error processing arguments");
        cobj->AddToMapLayer(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 4) {
        cocos2d::Node* arg0 = nullptr;
        double arg1 = 0;
        double arg2 = 0;
        int arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SceneManager_AddToMapLayer : Error processing arguments");
        cobj->AddToMapLayer(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_SceneManager_AddToMapLayer : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_SceneManager_GetMapLayer(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SceneManager* cobj = (Genius::SceneManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SceneManager_GetMapLayer : Invalid Native Object");
    if (argc == 0) {
        cocos2d::Node* ret = cobj->GetMapLayer();
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Node>(cx, (cocos2d::Node*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_SceneManager_GetMapLayer : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_SceneManager_GetSingleton(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        Genius::SceneManager* ret = Genius::SceneManager::GetSingleton();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::SceneManager>(cx, (Genius::SceneManager*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_SceneManager_GetSingleton : wrong number of arguments");
    return false;
}


void js_register_app_SceneManager(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_SceneManager_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_SceneManager_class->name = "SceneManager";
    jsb_Genius_SceneManager_class->addProperty = JS_PropertyStub;
    jsb_Genius_SceneManager_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_SceneManager_class->getProperty = JS_PropertyStub;
    jsb_Genius_SceneManager_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_SceneManager_class->enumerate = JS_EnumerateStub;
    jsb_Genius_SceneManager_class->resolve = JS_ResolveStub;
    jsb_Genius_SceneManager_class->convert = JS_ConvertStub;
    jsb_Genius_SceneManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ShakeScene", js_app_SceneManager_ShakeScene, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Init", js_app_SceneManager_Init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Update", js_app_SceneManager_Update, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddToMapLayer", js_app_SceneManager_AddToMapLayer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMapLayer", js_app_SceneManager_GetMapLayer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("GetSingleton", js_app_SceneManager_GetSingleton, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Genius_SceneManager_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_SceneManager_class,
        dummy_constructor<Genius::SceneManager>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_SceneManager_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SceneManager"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::SceneManager>(cx, jsb_Genius_SceneManager_class, proto, JS::NullPtr());
}

JSClass  *jsb_RollNumberLabel_class;
JSObject *jsb_RollNumberLabel_prototype;

bool js_app_RollNumberLabel_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    RollNumberLabel* cobj = (RollNumberLabel *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_RollNumberLabel_setColor : Invalid Native Object");
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_RollNumberLabel_setColor : Error processing arguments");
        cobj->setColor(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_RollNumberLabel_setColor : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_RollNumberLabel_update(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    RollNumberLabel* cobj = (RollNumberLabel *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_RollNumberLabel_update : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_RollNumberLabel_update : Error processing arguments");
        cobj->update(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_RollNumberLabel_update : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_RollNumberLabel_setStartNumber(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    RollNumberLabel* cobj = (RollNumberLabel *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_RollNumberLabel_setStartNumber : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_RollNumberLabel_setStartNumber : Error processing arguments");
        cobj->setStartNumber(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_RollNumberLabel_setStartNumber : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_RollNumberLabel_rollTo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    RollNumberLabel* cobj = (RollNumberLabel *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_RollNumberLabel_rollTo : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_RollNumberLabel_rollTo : Error processing arguments");
        cobj->rollTo(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_RollNumberLabel_rollTo : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_RollNumberLabel_isRollDone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    RollNumberLabel* cobj = (RollNumberLabel *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_RollNumberLabel_isRollDone : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isRollDone();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_RollNumberLabel_isRollDone : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_RollNumberLabel_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        auto ret = RollNumberLabel::create();
        js_type_class_t *typeClass = js_get_type_from_native<RollNumberLabel>(ret);
        JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "RollNumberLabel"));
        args.rval().set(OBJECT_TO_JSVAL(jsret));
        return true;
    }
    JS_ReportError(cx, "js_app_RollNumberLabel_create : wrong number of arguments");
    return false;
}

bool js_app_RollNumberLabel_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    RollNumberLabel* cobj = new (std::nothrow) RollNumberLabel();

    js_type_class_t *typeClass = js_get_type_from_native<RollNumberLabel>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "RollNumberLabel"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_register_app_RollNumberLabel(JSContext *cx, JS::HandleObject global) {
    jsb_RollNumberLabel_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_RollNumberLabel_class->name = "RollNumberLabel";
    jsb_RollNumberLabel_class->addProperty = JS_PropertyStub;
    jsb_RollNumberLabel_class->delProperty = JS_DeletePropertyStub;
    jsb_RollNumberLabel_class->getProperty = JS_PropertyStub;
    jsb_RollNumberLabel_class->setProperty = JS_StrictPropertyStub;
    jsb_RollNumberLabel_class->enumerate = JS_EnumerateStub;
    jsb_RollNumberLabel_class->resolve = JS_ResolveStub;
    jsb_RollNumberLabel_class->convert = JS_ConvertStub;
    jsb_RollNumberLabel_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setColor", js_app_RollNumberLabel_setColor, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("update", js_app_RollNumberLabel_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setStartNumber", js_app_RollNumberLabel_setStartNumber, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("rollTo", js_app_RollNumberLabel_rollTo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isRollDone", js_app_RollNumberLabel_isRollDone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_app_RollNumberLabel_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
    jsb_RollNumberLabel_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_RollNumberLabel_class,
        js_app_RollNumberLabel_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_RollNumberLabel_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "RollNumberLabel"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<RollNumberLabel>(cx, jsb_RollNumberLabel_class, proto, parent_proto);
}

JSClass  *jsb_LoadingManager_class;
JSObject *jsb_LoadingManager_prototype;

bool js_app_LoadingManager_StartLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_StartLoading : Invalid Native Object");
    if (argc == 0) {
        cobj->StartLoading();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_StartLoading : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_AddBullet(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_AddBullet : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_LoadingManager_AddBullet : Error processing arguments");
        cobj->AddBullet(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_AddBullet : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_LoadingManager_AddAnim(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_AddAnim : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_LoadingManager_AddAnim : Error processing arguments");
        cobj->AddAnim(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_AddAnim : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_LoadingManager_UpdateLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_UpdateLoading : Invalid Native Object");
    if (argc == 0) {
        cobj->UpdateLoading();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_UpdateLoading : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_GenerateUnLoadList(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_GenerateUnLoadList : Invalid Native Object");
    if (argc == 0) {
        cobj->GenerateUnLoadList();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_GenerateUnLoadList : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_IsLoadingDone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_IsLoadingDone : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsLoadingDone();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_IsLoadingDone : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_GetLoadingPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_GetLoadingPercent : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetLoadingPercent();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_GetLoadingPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_AddRole(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_AddRole : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_LoadingManager_AddRole : Error processing arguments");
        cobj->AddRole(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_AddRole : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_LoadingManager_ClearLoadingList(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_ClearLoadingList : Invalid Native Object");
    if (argc == 0) {
        cobj->ClearLoadingList();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_ClearLoadingList : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_LoadingManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    LoadingManager* cobj = new (std::nothrow) LoadingManager();

    js_type_class_t *typeClass = js_get_type_from_native<LoadingManager>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "LoadingManager"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_register_app_LoadingManager(JSContext *cx, JS::HandleObject global) {
    jsb_LoadingManager_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_LoadingManager_class->name = "LoadingManager";
    jsb_LoadingManager_class->addProperty = JS_PropertyStub;
    jsb_LoadingManager_class->delProperty = JS_DeletePropertyStub;
    jsb_LoadingManager_class->getProperty = JS_PropertyStub;
    jsb_LoadingManager_class->setProperty = JS_StrictPropertyStub;
    jsb_LoadingManager_class->enumerate = JS_EnumerateStub;
    jsb_LoadingManager_class->resolve = JS_ResolveStub;
    jsb_LoadingManager_class->convert = JS_ConvertStub;
    jsb_LoadingManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("StartLoading", js_app_LoadingManager_StartLoading, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddBullet", js_app_LoadingManager_AddBullet, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddAnim", js_app_LoadingManager_AddAnim, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("UpdateLoading", js_app_LoadingManager_UpdateLoading, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GenerateUnLoadList", js_app_LoadingManager_GenerateUnLoadList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsLoadingDone", js_app_LoadingManager_IsLoadingDone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLoadingPercent", js_app_LoadingManager_GetLoadingPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddRole", js_app_LoadingManager_AddRole, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ClearLoadingList", js_app_LoadingManager_ClearLoadingList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
    jsb_LoadingManager_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_LoadingManager_class,
        js_app_LoadingManager_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_LoadingManager_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "LoadingManager"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<LoadingManager>(cx, jsb_LoadingManager_class, proto, parent_proto);
}

JSClass  *jsb_Genius_IComponent_class;
JSObject *jsb_Genius_IComponent_prototype;

bool js_app_IComponent_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IComponent* cobj = (Genius::IComponent *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IComponent_OnDestroy : Invalid Native Object");
    if (argc == 0) {
        cobj->OnDestroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_IComponent_OnDestroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_IComponent_GetEntity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IComponent* cobj = (Genius::IComponent *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IComponent_GetEntity : Invalid Native Object");
    if (argc == 0) {
        Genius::Entity* ret = cobj->GetEntity();
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::Entity>(cx, (Genius::Entity*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_IComponent_GetEntity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_app_IComponent(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_IComponent_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_IComponent_class->name = "IComponent";
    jsb_Genius_IComponent_class->addProperty = JS_PropertyStub;
    jsb_Genius_IComponent_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_IComponent_class->getProperty = JS_PropertyStub;
    jsb_Genius_IComponent_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_IComponent_class->enumerate = JS_EnumerateStub;
    jsb_Genius_IComponent_class->resolve = JS_ResolveStub;
    jsb_Genius_IComponent_class->convert = JS_ConvertStub;
    jsb_Genius_IComponent_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("OnDestroy", js_app_IComponent_OnDestroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetEntity", js_app_IComponent_GetEntity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_IComponent_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_IComponent_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_IComponent_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "IComponent"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::IComponent>(cx, jsb_Genius_IComponent_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_ComTransform_class;
JSObject *jsb_Genius_ComTransform_prototype;

bool js_app_ComTransform_MoveTo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_MoveTo : Invalid Native Object");
    if (argc == 3) {
        double arg0 = 0;
        double arg1 = 0;
        double arg2 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_MoveTo : Error processing arguments");
        cobj->MoveTo(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_MoveTo : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_ComTransform_SetDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_SetDirection : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_SetDirection : Error processing arguments");
        cobj->SetDirection(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_SetDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComTransform_GetDir(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_GetDir : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetDir();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_GetDir : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComTransform_GetX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_GetX : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetX();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_GetX : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComTransform_GetY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_GetY : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetY();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_GetY : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComTransform_GetVY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_GetVY : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetVY();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_GetVY : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComTransform_GetVX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_GetVX : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetVX();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_GetVX : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComTransform_FaceTo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_FaceTo : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_FaceTo : Error processing arguments");
        cobj->FaceTo(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_FaceTo : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComTransform_SetPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_SetPosition : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_SetPosition : Error processing arguments");
        cobj->SetPosition(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_SetPosition : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComTransform_SetVelocity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_SetVelocity : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_SetVelocity : Error processing arguments");
        cobj->SetVelocity(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_SetVelocity : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComTransform_MoveTowards(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComTransform* cobj = (Genius::ComTransform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComTransform_MoveTowards : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComTransform_MoveTowards : Error processing arguments");
        cobj->MoveTowards(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComTransform_MoveTowards : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComTransform_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComTransform* cobj = new (std::nothrow) Genius::ComTransform();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::ComTransform>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::ComTransform"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IComponent_prototype;

void js_Genius_ComTransform_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ComTransform)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::ComTransform *nobj = static_cast<Genius::ComTransform *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_ComTransform(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComTransform_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComTransform_class->name = "ComTransform";
    jsb_Genius_ComTransform_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComTransform_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComTransform_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComTransform_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComTransform_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComTransform_class->resolve = JS_ResolveStub;
    jsb_Genius_ComTransform_class->convert = JS_ConvertStub;
    jsb_Genius_ComTransform_class->finalize = js_Genius_ComTransform_finalize;
    jsb_Genius_ComTransform_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("MoveTo", js_app_ComTransform_MoveTo, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDirection", js_app_ComTransform_SetDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetDir", js_app_ComTransform_GetDir, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetX", js_app_ComTransform_GetX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetY", js_app_ComTransform_GetY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVY", js_app_ComTransform_GetVY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVX", js_app_ComTransform_GetVX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("FaceTo", js_app_ComTransform_FaceTo, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetPosition", js_app_ComTransform_SetPosition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetVelocity", js_app_ComTransform_SetVelocity, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("MoveTowards", js_app_ComTransform_MoveTowards, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComTransform_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComTransform_class,
        js_app_ComTransform_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComTransform_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComTransform"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComTransform>(cx, jsb_Genius_ComTransform_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBoxCollider_class;
JSObject *jsb_Genius_ComBoxCollider_prototype;

bool js_app_ComBoxCollider_GetWidth(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBoxCollider* cobj = (Genius::ComBoxCollider *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBoxCollider_GetWidth : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetWidth();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComBoxCollider_GetWidth : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComBoxCollider_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBoxCollider* cobj = (Genius::ComBoxCollider *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBoxCollider_Create : Invalid Native Object");
    if (argc == 5) {
        bool arg0;
        double arg1 = 0;
        double arg2 = 0;
        double arg3 = 0;
        double arg4 = 0;
        arg0 = JS::ToBoolean(args.get(0));
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        ok &= JS::ToNumber( cx, args.get(3), &arg3) && !std::isnan(arg3);
        ok &= JS::ToNumber( cx, args.get(4), &arg4) && !std::isnan(arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBoxCollider_Create : Error processing arguments");
        cobj->Create(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBoxCollider_Create : wrong number of arguments: %d, was expecting %d", argc, 5);
    return false;
}
bool js_app_ComBoxCollider_GetHeight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBoxCollider* cobj = (Genius::ComBoxCollider *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBoxCollider_GetHeight : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetHeight();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComBoxCollider_GetHeight : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComBoxCollider(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBoxCollider_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBoxCollider_class->name = "ComBoxCollider";
    jsb_Genius_ComBoxCollider_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBoxCollider_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBoxCollider_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBoxCollider_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBoxCollider_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBoxCollider_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBoxCollider_class->convert = JS_ConvertStub;
    jsb_Genius_ComBoxCollider_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetWidth", js_app_ComBoxCollider_GetWidth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Create", js_app_ComBoxCollider_Create, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetHeight", js_app_ComBoxCollider_GetHeight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComBoxCollider_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBoxCollider_class,
        dummy_constructor<Genius::ComBoxCollider>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBoxCollider_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBoxCollider"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBoxCollider>(cx, jsb_Genius_ComBoxCollider_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComRenderRoot_class;
JSObject *jsb_Genius_ComRenderRoot_prototype;

bool js_app_ComRenderRoot_AddChild(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComRenderRoot* cobj = (Genius::ComRenderRoot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComRenderRoot_AddChild : Invalid Native Object");
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComRenderRoot_AddChild : Error processing arguments");
        cobj->AddChild(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComRenderRoot_AddChild : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComRenderRoot_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComRenderRoot* cobj = (Genius::ComRenderRoot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComRenderRoot_OnDestroy : Invalid Native Object");
    if (argc == 0) {
        cobj->OnDestroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComRenderRoot_OnDestroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComRenderRoot_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComRenderRoot* cobj = new (std::nothrow) Genius::ComRenderRoot();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::ComRenderRoot>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::ComRenderRoot"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IComponent_prototype;

void js_Genius_ComRenderRoot_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ComRenderRoot)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::ComRenderRoot *nobj = static_cast<Genius::ComRenderRoot *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_ComRenderRoot(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComRenderRoot_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComRenderRoot_class->name = "ComRenderRoot";
    jsb_Genius_ComRenderRoot_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComRenderRoot_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComRenderRoot_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComRenderRoot_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComRenderRoot_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComRenderRoot_class->resolve = JS_ResolveStub;
    jsb_Genius_ComRenderRoot_class->convert = JS_ConvertStub;
    jsb_Genius_ComRenderRoot_class->finalize = js_Genius_ComRenderRoot_finalize;
    jsb_Genius_ComRenderRoot_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AddChild", js_app_ComRenderRoot_AddChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("OnDestroy", js_app_ComRenderRoot_OnDestroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComRenderRoot_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComRenderRoot_class,
        js_app_ComRenderRoot_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComRenderRoot_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComRenderRoot"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComRenderRoot>(cx, jsb_Genius_ComRenderRoot_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComParticle_class;
JSObject *jsb_Genius_ComParticle_prototype;

bool js_app_ComParticle_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComParticle* cobj = (Genius::ComParticle *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComParticle_Create : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComParticle_Create : Error processing arguments");
        cobj->Create(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComParticle_Create : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComParticle(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComParticle_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComParticle_class->name = "ComParticle";
    jsb_Genius_ComParticle_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComParticle_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComParticle_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComParticle_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComParticle_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComParticle_class->resolve = JS_ResolveStub;
    jsb_Genius_ComParticle_class->convert = JS_ConvertStub;
    jsb_Genius_ComParticle_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Create", js_app_ComParticle_Create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComParticle_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComParticle_class,
        dummy_constructor<Genius::ComParticle>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComParticle_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComParticle"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComParticle>(cx, jsb_Genius_ComParticle_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBezierMovement_class;
JSObject *jsb_Genius_ComBezierMovement_prototype;

bool js_app_ComBezierMovement_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBezierMovement* cobj = (Genius::ComBezierMovement *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBezierMovement_Create : Invalid Native Object");
    if (argc == 5) {
        double arg0 = 0;
        double arg1 = 0;
        double arg2 = 0;
        double arg3 = 0;
        double arg4 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        ok &= JS::ToNumber( cx, args.get(3), &arg3) && !std::isnan(arg3);
        ok &= JS::ToNumber( cx, args.get(4), &arg4) && !std::isnan(arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBezierMovement_Create : Error processing arguments");
        cobj->Create(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBezierMovement_Create : wrong number of arguments: %d, was expecting %d", argc, 5);
    return false;
}
bool js_app_ComBezierMovement_Stop(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBezierMovement* cobj = (Genius::ComBezierMovement *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBezierMovement_Stop : Invalid Native Object");
    if (argc == 0) {
        cobj->Stop();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBezierMovement_Stop : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComBezierMovement_IsDone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBezierMovement* cobj = (Genius::ComBezierMovement *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBezierMovement_IsDone : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsDone();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComBezierMovement_IsDone : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComBezierMovement(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBezierMovement_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBezierMovement_class->name = "ComBezierMovement";
    jsb_Genius_ComBezierMovement_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBezierMovement_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBezierMovement_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBezierMovement_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBezierMovement_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBezierMovement_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBezierMovement_class->convert = JS_ConvertStub;
    jsb_Genius_ComBezierMovement_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Create", js_app_ComBezierMovement_Create, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Stop", js_app_ComBezierMovement_Stop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsDone", js_app_ComBezierMovement_IsDone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComBezierMovement_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBezierMovement_class,
        dummy_constructor<Genius::ComBezierMovement>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBezierMovement_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBezierMovement"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBezierMovement>(cx, jsb_Genius_ComBezierMovement_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComDelayTrackMovement_class;
JSObject *jsb_Genius_ComDelayTrackMovement_prototype;

bool js_app_ComDelayTrackMovement_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComDelayTrackMovement* cobj = (Genius::ComDelayTrackMovement *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComDelayTrackMovement_Create : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        double arg1 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComDelayTrackMovement_Create : Error processing arguments");
        cobj->Create(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComDelayTrackMovement_Create : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComDelayTrackMovement_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComDelayTrackMovement* cobj = new (std::nothrow) Genius::ComDelayTrackMovement();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::ComDelayTrackMovement>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::ComDelayTrackMovement"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IComponent_prototype;

void js_Genius_ComDelayTrackMovement_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ComDelayTrackMovement)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::ComDelayTrackMovement *nobj = static_cast<Genius::ComDelayTrackMovement *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_ComDelayTrackMovement(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComDelayTrackMovement_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComDelayTrackMovement_class->name = "ComDelayTrackMovement";
    jsb_Genius_ComDelayTrackMovement_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComDelayTrackMovement_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComDelayTrackMovement_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComDelayTrackMovement_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComDelayTrackMovement_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComDelayTrackMovement_class->resolve = JS_ResolveStub;
    jsb_Genius_ComDelayTrackMovement_class->convert = JS_ConvertStub;
    jsb_Genius_ComDelayTrackMovement_class->finalize = js_Genius_ComDelayTrackMovement_finalize;
    jsb_Genius_ComDelayTrackMovement_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Create", js_app_ComDelayTrackMovement_Create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComDelayTrackMovement_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComDelayTrackMovement_class,
        js_app_ComDelayTrackMovement_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComDelayTrackMovement_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComDelayTrackMovement"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComDelayTrackMovement>(cx, jsb_Genius_ComDelayTrackMovement_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComPawnAgent_class;
JSObject *jsb_Genius_ComPawnAgent_prototype;

bool js_app_ComPawnAgent_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAgent* cobj = (Genius::ComPawnAgent *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAgent_Create : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        bool arg1;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAgent_Create : Error processing arguments");
        cobj->Create(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAgent_Create : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComPawnAgent_AddAction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAgent* cobj = (Genius::ComPawnAgent *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAgent_AddAction : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAgent_AddAction : Error processing arguments");
        cobj->AddAction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAgent_AddAction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAgent_GetBlackboard(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAgent* cobj = (Genius::ComPawnAgent *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAgent_GetBlackboard : Invalid Native Object");
    if (argc == 0) {
        Genius::PawnBlackboard* ret = cobj->GetBlackboard();
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::PawnBlackboard>(cx, (Genius::PawnBlackboard*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAgent_GetBlackboard : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComPawnAgent(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComPawnAgent_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComPawnAgent_class->name = "ComPawnAgent";
    jsb_Genius_ComPawnAgent_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComPawnAgent_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComPawnAgent_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComPawnAgent_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComPawnAgent_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComPawnAgent_class->resolve = JS_ResolveStub;
    jsb_Genius_ComPawnAgent_class->convert = JS_ConvertStub;
    jsb_Genius_ComPawnAgent_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Create", js_app_ComPawnAgent_Create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddAction", js_app_ComPawnAgent_AddAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBlackboard", js_app_ComPawnAgent_GetBlackboard, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComPawnAgent_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComPawnAgent_class,
        dummy_constructor<Genius::ComPawnAgent>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComPawnAgent_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComPawnAgent"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComPawnAgent>(cx, jsb_Genius_ComPawnAgent_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComPawnAnim_class;
JSObject *jsb_Genius_ComPawnAnim_prototype;

bool js_app_ComPawnAnim_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_AnimationMovementCallback : Invalid Native Object");
    if (argc == 3) {
        cocostudio::Armature* arg0 = nullptr;
        cocostudio::MovementEventType arg1;
        std::string arg2;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_AnimationMovementCallback : Error processing arguments");
        cobj->AnimationMovementCallback(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_AnimationMovementCallback : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_ComPawnAnim_PlayFloatNumber(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_PlayFloatNumber : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_PlayFloatNumber : Error processing arguments");
        cobj->PlayFloatNumber(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_PlayFloatNumber : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComPawnAnim_HandleAction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_HandleAction : Invalid Native Object");
    if (argc == 1) {
        Genius::PawnAction* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::PawnAction*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_HandleAction : Error processing arguments");
        cobj->HandleAction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_HandleAction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_Create : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_Create : Error processing arguments");
        cobj->Create(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_Create : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_GetHeight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_GetHeight : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetHeight();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_GetHeight : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComPawnAnim_PlayAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_PlayAnimation : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_PlayAnimation : Error processing arguments");
        cobj->PlayAnimation(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_PlayAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_GetWidth(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_GetWidth : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetWidth();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_GetWidth : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComPawnAnim_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_OnDestroy : Invalid Native Object");
    if (argc == 0) {
        cobj->OnDestroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_OnDestroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComPawnAnim_SetDebugLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_SetDebugLabel : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_SetDebugLabel : Error processing arguments");
        cobj->SetDebugLabel(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_SetDebugLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_UpdateLifeBar(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_UpdateLifeBar : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_UpdateLifeBar : Error processing arguments");
        cobj->UpdateLifeBar(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_UpdateLifeBar : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_SetPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_SetPosition : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_SetPosition : Error processing arguments");
        cobj->SetPosition(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_SetPosition : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComPawnAnim_ContainAnim(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_ContainAnim : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_ContainAnim : Error processing arguments");
        bool ret = cobj->ContainAnim(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_ContainAnim : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComPawnAnim_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnAnim* cobj = (Genius::ComPawnAnim *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnAnim_AnimationFrameCallback : Invalid Native Object");
    if (argc == 4) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnAnim_AnimationFrameCallback : Error processing arguments");
        cobj->AnimationFrameCallback(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnAnim_AnimationFrameCallback : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}

void js_register_app_ComPawnAnim(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComPawnAnim_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComPawnAnim_class->name = "ComPawnAnim";
    jsb_Genius_ComPawnAnim_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComPawnAnim_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComPawnAnim_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComPawnAnim_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComPawnAnim_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComPawnAnim_class->resolve = JS_ResolveStub;
    jsb_Genius_ComPawnAnim_class->convert = JS_ConvertStub;
    jsb_Genius_ComPawnAnim_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AnimationMovementCallback", js_app_ComPawnAnim_AnimationMovementCallback, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("PlayFloatNumber", js_app_ComPawnAnim_PlayFloatNumber, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("HandleAction", js_app_ComPawnAnim_HandleAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Create", js_app_ComPawnAnim_Create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetHeight", js_app_ComPawnAnim_GetHeight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("PlayAnimation", js_app_ComPawnAnim_PlayAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWidth", js_app_ComPawnAnim_GetWidth, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("OnDestroy", js_app_ComPawnAnim_OnDestroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDebugLabel", js_app_ComPawnAnim_SetDebugLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("UpdateLifeBar", js_app_ComPawnAnim_UpdateLifeBar, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetPosition", js_app_ComPawnAnim_SetPosition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ContainAnim", js_app_ComPawnAnim_ContainAnim, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AnimationFrameCallback", js_app_ComPawnAnim_AnimationFrameCallback, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_ComPawnAnim_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_ComPawnAnim_class,
        dummy_constructor<Genius::ComPawnAnim>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComPawnAnim_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComPawnAnim"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComPawnAnim>(cx, jsb_Genius_ComPawnAnim_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_ComPawnDebugDraw_class;
JSObject *jsb_Genius_ComPawnDebugDraw_prototype;

bool js_app_ComPawnDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnDebugDraw* cobj = (Genius::ComPawnDebugDraw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnDebugDraw_Clear : Invalid Native Object");
    if (argc == 0) {
        cobj->Clear();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnDebugDraw_Clear : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComPawnDebugDraw_Refresh(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnDebugDraw* cobj = (Genius::ComPawnDebugDraw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnDebugDraw_Refresh : Invalid Native Object");
    if (argc == 0) {
        cobj->Refresh();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnDebugDraw_Refresh : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComPawnDebugDraw(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComPawnDebugDraw_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComPawnDebugDraw_class->name = "ComPawnDebugDraw";
    jsb_Genius_ComPawnDebugDraw_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComPawnDebugDraw_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComPawnDebugDraw_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComPawnDebugDraw_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComPawnDebugDraw_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComPawnDebugDraw_class->resolve = JS_ResolveStub;
    jsb_Genius_ComPawnDebugDraw_class->convert = JS_ConvertStub;
    jsb_Genius_ComPawnDebugDraw_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Clear", js_app_ComPawnDebugDraw_Clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Refresh", js_app_ComPawnDebugDraw_Refresh, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComPawnDebugDraw_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComPawnDebugDraw_class,
        dummy_constructor<Genius::ComPawnDebugDraw>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComPawnDebugDraw_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComPawnDebugDraw"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComPawnDebugDraw>(cx, jsb_Genius_ComPawnDebugDraw_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComPawnFight_class;
JSObject *jsb_Genius_ComPawnFight_prototype;

bool js_app_ComPawnFight_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComPawnFight* cobj = new (std::nothrow) Genius::ComPawnFight();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::ComPawnFight>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::ComPawnFight"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IComponent_prototype;

void js_Genius_ComPawnFight_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ComPawnFight)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::ComPawnFight *nobj = static_cast<Genius::ComPawnFight *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_ComPawnFight(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComPawnFight_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComPawnFight_class->name = "ComPawnFight";
    jsb_Genius_ComPawnFight_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComPawnFight_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComPawnFight_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComPawnFight_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComPawnFight_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComPawnFight_class->resolve = JS_ResolveStub;
    jsb_Genius_ComPawnFight_class->convert = JS_ConvertStub;
    jsb_Genius_ComPawnFight_class->finalize = js_Genius_ComPawnFight_finalize;
    jsb_Genius_ComPawnFight_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComPawnFight_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComPawnFight_class,
        js_app_ComPawnFight_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComPawnFight_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComPawnFight"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComPawnFight>(cx, jsb_Genius_ComPawnFight_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComPawnNavigation_class;
JSObject *jsb_Genius_ComPawnNavigation_prototype;

bool js_app_ComPawnNavigation_MoveTo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComPawnNavigation* cobj = (Genius::ComPawnNavigation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComPawnNavigation_MoveTo : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComPawnNavigation_MoveTo : Error processing arguments");
        cobj->MoveTo(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComPawnNavigation_MoveTo : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComPawnNavigation_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComPawnNavigation* cobj = new (std::nothrow) Genius::ComPawnNavigation();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::ComPawnNavigation>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::ComPawnNavigation"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IComponent_prototype;

void js_Genius_ComPawnNavigation_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ComPawnNavigation)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::ComPawnNavigation *nobj = static_cast<Genius::ComPawnNavigation *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_ComPawnNavigation(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComPawnNavigation_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComPawnNavigation_class->name = "ComPawnNavigation";
    jsb_Genius_ComPawnNavigation_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComPawnNavigation_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComPawnNavigation_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComPawnNavigation_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComPawnNavigation_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComPawnNavigation_class->resolve = JS_ResolveStub;
    jsb_Genius_ComPawnNavigation_class->convert = JS_ConvertStub;
    jsb_Genius_ComPawnNavigation_class->finalize = js_Genius_ComPawnNavigation_finalize;
    jsb_Genius_ComPawnNavigation_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("MoveTo", js_app_ComPawnNavigation_MoveTo, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComPawnNavigation_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComPawnNavigation_class,
        js_app_ComPawnNavigation_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComPawnNavigation_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComPawnNavigation"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComPawnNavigation>(cx, jsb_Genius_ComPawnNavigation_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletAnimBase_class;
JSObject *jsb_Genius_ComBulletAnimBase_prototype;

bool js_app_ComBulletAnimBase_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBase* cobj = (Genius::ComBulletAnimBase *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBase_Create : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimBase_Create : Error processing arguments");
        cobj->Create(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBase_Create : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComBulletAnimBase_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBase* cobj = (Genius::ComBulletAnimBase *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBase_OnDestroy : Invalid Native Object");
    if (argc == 0) {
        cobj->OnDestroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBase_OnDestroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComBulletAnimBase(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletAnimBase_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletAnimBase_class->name = "ComBulletAnimBase";
    jsb_Genius_ComBulletAnimBase_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimBase_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletAnimBase_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimBase_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletAnimBase_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletAnimBase_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletAnimBase_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletAnimBase_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Create", js_app_ComBulletAnimBase_Create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("OnDestroy", js_app_ComBulletAnimBase_OnDestroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComBulletAnimBase_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletAnimBase_class,
        dummy_constructor<Genius::ComBulletAnimBase>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletAnimBase_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletAnimBase"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletAnimBase>(cx, jsb_Genius_ComBulletAnimBase_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletAnimArrow_class;
JSObject *jsb_Genius_ComBulletAnimArrow_prototype;

bool js_app_ComBulletAnimArrow_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimArrow* cobj = (Genius::ComBulletAnimArrow *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimArrow_AnimationMovementCallback : Invalid Native Object");
    if (argc == 3) {
        cocostudio::Armature* arg0 = nullptr;
        cocostudio::MovementEventType arg1;
        std::string arg2;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimArrow_AnimationMovementCallback : Error processing arguments");
        cobj->AnimationMovementCallback(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimArrow_AnimationMovementCallback : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_ComBulletAnimArrow_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimArrow* cobj = (Genius::ComBulletAnimArrow *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimArrow_Create : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimArrow_Create : Error processing arguments");
        cobj->Create(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimArrow_Create : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComBulletAnimArrow_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimArrow* cobj = (Genius::ComBulletAnimArrow *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimArrow_AnimationFrameCallback : Invalid Native Object");
    if (argc == 4) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimArrow_AnimationFrameCallback : Error processing arguments");
        cobj->AnimationFrameCallback(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimArrow_AnimationFrameCallback : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_app_ComBulletAnimArrow_StayStill(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimArrow* cobj = (Genius::ComBulletAnimArrow *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimArrow_StayStill : Invalid Native Object");
    if (argc == 0) {
        cobj->StayStill();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimArrow_StayStill : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_ComBulletAnimBase_prototype;

void js_register_app_ComBulletAnimArrow(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletAnimArrow_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletAnimArrow_class->name = "ComBulletAnimArrow";
    jsb_Genius_ComBulletAnimArrow_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimArrow_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletAnimArrow_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimArrow_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletAnimArrow_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletAnimArrow_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletAnimArrow_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletAnimArrow_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AnimationMovementCallback", js_app_ComBulletAnimArrow_AnimationMovementCallback, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Create", js_app_ComBulletAnimArrow_Create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AnimationFrameCallback", js_app_ComBulletAnimArrow_AnimationFrameCallback, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("StayStill", js_app_ComBulletAnimArrow_StayStill, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_ComBulletAnimBase_prototype);
    jsb_Genius_ComBulletAnimArrow_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletAnimArrow_class,
        dummy_constructor<Genius::ComBulletAnimArrow>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletAnimArrow_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletAnimArrow"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletAnimArrow>(cx, jsb_Genius_ComBulletAnimArrow_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletAnimBomb_class;
JSObject *jsb_Genius_ComBulletAnimBomb_prototype;

bool js_app_ComBulletAnimBomb_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBomb* cobj = (Genius::ComBulletAnimBomb *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBomb_AnimationMovementCallback : Invalid Native Object");
    if (argc == 3) {
        cocostudio::Armature* arg0 = nullptr;
        cocostudio::MovementEventType arg1;
        std::string arg2;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimBomb_AnimationMovementCallback : Error processing arguments");
        cobj->AnimationMovementCallback(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBomb_AnimationMovementCallback : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_ComBulletAnimBomb_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBomb* cobj = (Genius::ComBulletAnimBomb *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBomb_Create : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimBomb_Create : Error processing arguments");
        cobj->Create(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBomb_Create : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_ComBulletAnimBomb_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBomb* cobj = (Genius::ComBulletAnimBomb *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBomb_AnimationFrameCallback : Invalid Native Object");
    if (argc == 4) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimBomb_AnimationFrameCallback : Error processing arguments");
        cobj->AnimationFrameCallback(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBomb_AnimationFrameCallback : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_app_ComBulletAnimBomb_StartExplode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimBomb* cobj = (Genius::ComBulletAnimBomb *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimBomb_StartExplode : Invalid Native Object");
    if (argc == 0) {
        cobj->StartExplode();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimBomb_StartExplode : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_ComBulletAnimBase_prototype;

void js_register_app_ComBulletAnimBomb(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletAnimBomb_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletAnimBomb_class->name = "ComBulletAnimBomb";
    jsb_Genius_ComBulletAnimBomb_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimBomb_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletAnimBomb_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimBomb_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletAnimBomb_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletAnimBomb_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletAnimBomb_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletAnimBomb_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AnimationMovementCallback", js_app_ComBulletAnimBomb_AnimationMovementCallback, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Create", js_app_ComBulletAnimBomb_Create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AnimationFrameCallback", js_app_ComBulletAnimBomb_AnimationFrameCallback, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("StartExplode", js_app_ComBulletAnimBomb_StartExplode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_ComBulletAnimBase_prototype);
    jsb_Genius_ComBulletAnimBomb_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletAnimBomb_class,
        dummy_constructor<Genius::ComBulletAnimBomb>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletAnimBomb_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletAnimBomb"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletAnimBomb>(cx, jsb_Genius_ComBulletAnimBomb_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletDamage_class;
JSObject *jsb_Genius_ComBulletDamage_prototype;

bool js_app_ComBulletDamage_SetTargetID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletDamage* cobj = (Genius::ComBulletDamage *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletDamage_SetTargetID : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletDamage_SetTargetID : Error processing arguments");
        cobj->SetTargetID(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletDamage_SetTargetID : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComBulletDamage(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletDamage_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletDamage_class->name = "ComBulletDamage";
    jsb_Genius_ComBulletDamage_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletDamage_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletDamage_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletDamage_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletDamage_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletDamage_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletDamage_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletDamage_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetTargetID", js_app_ComBulletDamage_SetTargetID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComBulletDamage_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletDamage_class,
        dummy_constructor<Genius::ComBulletDamage>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletDamage_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletDamage"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletDamage>(cx, jsb_Genius_ComBulletDamage_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletDebugDraw_class;
JSObject *jsb_Genius_ComBulletDebugDraw_prototype;

bool js_app_ComBulletDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletDebugDraw* cobj = (Genius::ComBulletDebugDraw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletDebugDraw_Clear : Invalid Native Object");
    if (argc == 0) {
        cobj->Clear();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletDebugDraw_Clear : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_ComBulletDebugDraw_Refresh(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletDebugDraw* cobj = (Genius::ComBulletDebugDraw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletDebugDraw_Refresh : Invalid Native Object");
    if (argc == 0) {
        cobj->Refresh();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletDebugDraw_Refresh : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_Genius_IComponent_prototype;

void js_register_app_ComBulletDebugDraw(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletDebugDraw_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletDebugDraw_class->name = "ComBulletDebugDraw";
    jsb_Genius_ComBulletDebugDraw_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletDebugDraw_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletDebugDraw_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletDebugDraw_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletDebugDraw_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletDebugDraw_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletDebugDraw_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletDebugDraw_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Clear", js_app_ComBulletDebugDraw_Clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Refresh", js_app_ComBulletDebugDraw_Refresh, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IComponent_prototype);
    jsb_Genius_ComBulletDebugDraw_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletDebugDraw_class,
        dummy_constructor<Genius::ComBulletDebugDraw>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletDebugDraw_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletDebugDraw"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletDebugDraw>(cx, jsb_Genius_ComBulletDebugDraw_class, proto, parent_proto);
}

JSClass  *jsb_Genius_ComBulletAnimEgg_class;
JSObject *jsb_Genius_ComBulletAnimEgg_prototype;

bool js_app_ComBulletAnimEgg_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimEgg* cobj = (Genius::ComBulletAnimEgg *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimEgg_AnimationMovementCallback : Invalid Native Object");
    if (argc == 3) {
        cocostudio::Armature* arg0 = nullptr;
        cocostudio::MovementEventType arg1;
        std::string arg2;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimEgg_AnimationMovementCallback : Error processing arguments");
        cobj->AnimationMovementCallback(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimEgg_AnimationMovementCallback : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_ComBulletAnimEgg_Create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimEgg* cobj = (Genius::ComBulletAnimEgg *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimEgg_Create : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimEgg_Create : Error processing arguments");
        cobj->Create(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimEgg_Create : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_ComBulletAnimEgg_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::ComBulletAnimEgg* cobj = (Genius::ComBulletAnimEgg *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_ComBulletAnimEgg_AnimationFrameCallback : Invalid Native Object");
    if (argc == 4) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocostudio::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_app_ComBulletAnimEgg_AnimationFrameCallback : Error processing arguments");
        cobj->AnimationFrameCallback(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_ComBulletAnimEgg_AnimationFrameCallback : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}

extern JSObject *jsb_Genius_ComBulletAnimBase_prototype;

void js_register_app_ComBulletAnimEgg(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_ComBulletAnimEgg_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_ComBulletAnimEgg_class->name = "ComBulletAnimEgg";
    jsb_Genius_ComBulletAnimEgg_class->addProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimEgg_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_ComBulletAnimEgg_class->getProperty = JS_PropertyStub;
    jsb_Genius_ComBulletAnimEgg_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_ComBulletAnimEgg_class->enumerate = JS_EnumerateStub;
    jsb_Genius_ComBulletAnimEgg_class->resolve = JS_ResolveStub;
    jsb_Genius_ComBulletAnimEgg_class->convert = JS_ConvertStub;
    jsb_Genius_ComBulletAnimEgg_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AnimationMovementCallback", js_app_ComBulletAnimEgg_AnimationMovementCallback, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Create", js_app_ComBulletAnimEgg_Create, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AnimationFrameCallback", js_app_ComBulletAnimEgg_AnimationFrameCallback, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_ComBulletAnimBase_prototype);
    jsb_Genius_ComBulletAnimEgg_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_ComBulletAnimEgg_class,
        dummy_constructor<Genius::ComBulletAnimEgg>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_ComBulletAnimEgg_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ComBulletAnimEgg"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::ComBulletAnimEgg>(cx, jsb_Genius_ComBulletAnimEgg_class, proto, parent_proto);
}

JSClass  *jsb_EntityUtility_class;
JSObject *jsb_EntityUtility_prototype;

bool js_app_EntityUtility_IsEnemy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        Genius::Entity* arg0 = nullptr;
        Genius::Entity* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::Entity*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::Entity*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_IsEnemy : Error processing arguments");

        bool ret = EntityUtility::IsEnemy(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_IsEnemy : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_IsInMyViewSight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        Genius::EntityWrapper* arg0 = nullptr;
        Genius::EntityWrapper* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_IsInMyViewSight : Error processing arguments");

        bool ret = EntityUtility::IsInMyViewSight(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_IsInMyViewSight : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_IsInMyFarRange(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        Genius::EntityWrapper* arg0 = nullptr;
        Genius::EntityWrapper* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_IsInMyFarRange : Error processing arguments");

        bool ret = EntityUtility::IsInMyFarRange(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_IsInMyFarRange : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_GetEnemyTag(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_GetEnemyTag : Error processing arguments");

        const std::string& ret = EntityUtility::GetEnemyTag(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_GetEnemyTag : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_IsInMyNearRange(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        Genius::EntityWrapper* arg0 = nullptr;
        Genius::EntityWrapper* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_IsInMyNearRange : Error processing arguments");

        bool ret = EntityUtility::IsInMyNearRange(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_IsInMyNearRange : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_AreEntitiesCloseEnough(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        Genius::EntityWrapper* arg0 = nullptr;
        Genius::EntityWrapper* arg1 = nullptr;
        double arg2 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_AreEntitiesCloseEnough : Error processing arguments");

        bool ret = EntityUtility::AreEntitiesCloseEnough(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_AreEntitiesCloseEnough : wrong number of arguments");
    return false;
}

bool js_app_EntityUtility_IsTagged(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        Genius::Entity* arg1 = nullptr;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
            if (args.get(1).isNull()) { arg1 = nullptr; break; }
            if (!args.get(1).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(1).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg1 = (Genius::Entity*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityUtility_IsTagged : Error processing arguments");

        bool ret = EntityUtility::IsTagged(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_EntityUtility_IsTagged : wrong number of arguments");
    return false;
}


void js_register_app_EntityUtility(JSContext *cx, JS::HandleObject global) {
    jsb_EntityUtility_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_EntityUtility_class->name = "EntityUtility";
    jsb_EntityUtility_class->addProperty = JS_PropertyStub;
    jsb_EntityUtility_class->delProperty = JS_DeletePropertyStub;
    jsb_EntityUtility_class->getProperty = JS_PropertyStub;
    jsb_EntityUtility_class->setProperty = JS_StrictPropertyStub;
    jsb_EntityUtility_class->enumerate = JS_EnumerateStub;
    jsb_EntityUtility_class->resolve = JS_ResolveStub;
    jsb_EntityUtility_class->convert = JS_ConvertStub;
    jsb_EntityUtility_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("IsEnemy", js_app_EntityUtility_IsEnemy, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsInMyViewSight", js_app_EntityUtility_IsInMyViewSight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsInMyFarRange", js_app_EntityUtility_IsInMyFarRange, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetEnemyTag", js_app_EntityUtility_GetEnemyTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsInMyNearRange", js_app_EntityUtility_IsInMyNearRange, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AreEntitiesCloseEnough", js_app_EntityUtility_AreEntitiesCloseEnough, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsTagged", js_app_EntityUtility_IsTagged, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_EntityUtility_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_EntityUtility_class,
        dummy_constructor<EntityUtility>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_EntityUtility_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "EntityUtility"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<EntityUtility>(cx, jsb_EntityUtility_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_SkillManager_class;
JSObject *jsb_Genius_SkillManager_prototype;

bool js_app_SkillManager_ClearSkill(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SkillManager* cobj = (Genius::SkillManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SkillManager_ClearSkill : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SkillManager_ClearSkill : Error processing arguments");
        cobj->ClearSkill(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_SkillManager_ClearSkill : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_SkillManager_UseSkill(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SkillManager* cobj = (Genius::SkillManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SkillManager_UseSkill : Invalid Native Object");
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SkillManager_UseSkill : Error processing arguments");
        bool ret = cobj->UseSkill(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_SkillManager_UseSkill : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_SkillManager_ClearAllSkill(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SkillManager* cobj = (Genius::SkillManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SkillManager_ClearAllSkill : Invalid Native Object");
    if (argc == 0) {
        cobj->ClearAllSkill();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_SkillManager_ClearAllSkill : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_SkillManager_CanUseSkill(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::SkillManager* cobj = (Genius::SkillManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_SkillManager_CanUseSkill : Invalid Native Object");
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_SkillManager_CanUseSkill : Error processing arguments");
        bool ret = cobj->CanUseSkill(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_SkillManager_CanUseSkill : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_SkillManager_GetMe(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        Genius::SkillManager* ret = Genius::SkillManager::GetMe();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::SkillManager>(cx, (Genius::SkillManager*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_SkillManager_GetMe : wrong number of arguments");
    return false;
}

bool js_app_SkillManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::SkillManager* cobj = new (std::nothrow) Genius::SkillManager();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::SkillManager>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::SkillManager"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_Genius_SkillManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (SkillManager)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::SkillManager *nobj = static_cast<Genius::SkillManager *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_SkillManager(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_SkillManager_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_SkillManager_class->name = "SkillManager";
    jsb_Genius_SkillManager_class->addProperty = JS_PropertyStub;
    jsb_Genius_SkillManager_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_SkillManager_class->getProperty = JS_PropertyStub;
    jsb_Genius_SkillManager_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_SkillManager_class->enumerate = JS_EnumerateStub;
    jsb_Genius_SkillManager_class->resolve = JS_ResolveStub;
    jsb_Genius_SkillManager_class->convert = JS_ConvertStub;
    jsb_Genius_SkillManager_class->finalize = js_Genius_SkillManager_finalize;
    jsb_Genius_SkillManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ClearSkill", js_app_SkillManager_ClearSkill, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("UseSkill", js_app_SkillManager_UseSkill, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ClearAllSkill", js_app_SkillManager_ClearAllSkill, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("CanUseSkill", js_app_SkillManager_CanUseSkill, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("GetMe", js_app_SkillManager_GetMe, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Genius_SkillManager_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_SkillManager_class,
        js_app_SkillManager_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_SkillManager_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SkillManager"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::SkillManager>(cx, jsb_Genius_SkillManager_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_BuffManager_class;
JSObject *jsb_Genius_BuffManager_prototype;

bool js_app_BuffManager_GetBuffCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::BuffManager* cobj = (Genius::BuffManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_BuffManager_GetBuffCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetBuffCount();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_BuffManager_GetBuffCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_BuffManager_RemoveBuff(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::BuffManager* cobj = (Genius::BuffManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_BuffManager_RemoveBuff : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_BuffManager_RemoveBuff : Error processing arguments");
        cobj->RemoveBuff(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_BuffManager_RemoveBuff : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_BuffManager_RemoveAllBuff(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::BuffManager* cobj = (Genius::BuffManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_BuffManager_RemoveAllBuff : Invalid Native Object");
    if (argc == 0) {
        cobj->RemoveAllBuff();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_BuffManager_RemoveAllBuff : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_BuffManager_AddBuff(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::BuffManager* cobj = (Genius::BuffManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_BuffManager_AddBuff : Invalid Native Object");
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_app_BuffManager_AddBuff : Error processing arguments");
        bool ret = cobj->AddBuff(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_BuffManager_AddBuff : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_app_BuffManager_GetMe(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        Genius::BuffManager* ret = Genius::BuffManager::GetMe();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::BuffManager>(cx, (Genius::BuffManager*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_BuffManager_GetMe : wrong number of arguments");
    return false;
}

bool js_app_BuffManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::BuffManager* cobj = new (std::nothrow) Genius::BuffManager();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::BuffManager>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::BuffManager"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_Genius_BuffManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (BuffManager)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::BuffManager *nobj = static_cast<Genius::BuffManager *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_BuffManager(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_BuffManager_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_BuffManager_class->name = "BuffManager";
    jsb_Genius_BuffManager_class->addProperty = JS_PropertyStub;
    jsb_Genius_BuffManager_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_BuffManager_class->getProperty = JS_PropertyStub;
    jsb_Genius_BuffManager_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_BuffManager_class->enumerate = JS_EnumerateStub;
    jsb_Genius_BuffManager_class->resolve = JS_ResolveStub;
    jsb_Genius_BuffManager_class->convert = JS_ConvertStub;
    jsb_Genius_BuffManager_class->finalize = js_Genius_BuffManager_finalize;
    jsb_Genius_BuffManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetBuffCount", js_app_BuffManager_GetBuffCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RemoveBuff", js_app_BuffManager_RemoveBuff, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RemoveAllBuff", js_app_BuffManager_RemoveAllBuff, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddBuff", js_app_BuffManager_AddBuff, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("GetMe", js_app_BuffManager_GetMe, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Genius_BuffManager_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_BuffManager_class,
        js_app_BuffManager_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_BuffManager_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "BuffManager"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::BuffManager>(cx, jsb_Genius_BuffManager_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_EntityWrapper_class;
JSObject *jsb_Genius_EntityWrapper_prototype;

bool js_app_EntityWrapper_RemoveTag(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::EntityWrapper* cobj = (Genius::EntityWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_EntityWrapper_RemoveTag : Invalid Native Object");
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityWrapper_RemoveTag : Error processing arguments");
        cobj->RemoveTag(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_EntityWrapper_RemoveTag : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_EntityWrapper_AddComponent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::EntityWrapper* cobj = (Genius::EntityWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_EntityWrapper_AddComponent : Invalid Native Object");
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityWrapper_AddComponent : Error processing arguments");
        Genius::IComponent* ret = cobj->AddComponent(arg0);
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::IComponent>(cx, (Genius::IComponent*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_EntityWrapper_AddComponent : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_EntityWrapper_GetID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::EntityWrapper* cobj = (Genius::EntityWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_EntityWrapper_GetID : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetID();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_EntityWrapper_GetID : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_EntityWrapper_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::EntityWrapper* cobj = (Genius::EntityWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_EntityWrapper_OnDestroy : Invalid Native Object");
    if (argc == 0) {
        cobj->OnDestroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_EntityWrapper_OnDestroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_EntityWrapper_AddTag(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::EntityWrapper* cobj = (Genius::EntityWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_EntityWrapper_AddTag : Invalid Native Object");
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_EntityWrapper_AddTag : Error processing arguments");
        cobj->AddTag(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_EntityWrapper_AddTag : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_EntityWrapper_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::Entity* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::Entity*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_app_EntityWrapper_constructor : Error processing arguments");
    Genius::EntityWrapper* cobj = new (std::nothrow) Genius::EntityWrapper(arg0);

    js_type_class_t *typeClass = js_get_type_from_native<Genius::EntityWrapper>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::EntityWrapper"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_Genius_EntityWrapper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (EntityWrapper)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::EntityWrapper *nobj = static_cast<Genius::EntityWrapper *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_EntityWrapper(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_EntityWrapper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_EntityWrapper_class->name = "Entity";
    jsb_Genius_EntityWrapper_class->addProperty = JS_PropertyStub;
    jsb_Genius_EntityWrapper_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_EntityWrapper_class->getProperty = JS_PropertyStub;
    jsb_Genius_EntityWrapper_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_EntityWrapper_class->enumerate = JS_EnumerateStub;
    jsb_Genius_EntityWrapper_class->resolve = JS_ResolveStub;
    jsb_Genius_EntityWrapper_class->convert = JS_ConvertStub;
    jsb_Genius_EntityWrapper_class->finalize = js_Genius_EntityWrapper_finalize;
    jsb_Genius_EntityWrapper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("RemoveTag", js_app_EntityWrapper_RemoveTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddComponent", js_app_EntityWrapper_AddComponent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetID", js_app_EntityWrapper_GetID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("OnDestroy", js_app_EntityWrapper_OnDestroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddTag", js_app_EntityWrapper_AddTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_EntityWrapper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_EntityWrapper_class,
        js_app_EntityWrapper_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_EntityWrapper_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "EntityWrapper"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::EntityWrapper>(cx, jsb_Genius_EntityWrapper_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_WorldWrapper_class;
JSObject *jsb_Genius_WorldWrapper_prototype;

bool js_app_WorldWrapper_CreateEntity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::WorldWrapper* cobj = (Genius::WorldWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_WorldWrapper_CreateEntity : Invalid Native Object");
    if (argc == 0) {
        Genius::EntityWrapper* ret = cobj->CreateEntity();
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::EntityWrapper>(cx, (Genius::EntityWrapper*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_WorldWrapper_CreateEntity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_WorldWrapper_DestroyEntity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::WorldWrapper* cobj = (Genius::WorldWrapper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_WorldWrapper_DestroyEntity : Invalid Native Object");
    if (argc == 1) {
        Genius::EntityWrapper* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::EntityWrapper*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_WorldWrapper_DestroyEntity : Error processing arguments");
        cobj->DestroyEntity(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_WorldWrapper_DestroyEntity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_WorldWrapper_GetWorld(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        Genius::WorldWrapper* ret = Genius::WorldWrapper::GetWorld();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::WorldWrapper>(cx, (Genius::WorldWrapper*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_app_WorldWrapper_GetWorld : wrong number of arguments");
    return false;
}


void js_register_app_WorldWrapper(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_WorldWrapper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_WorldWrapper_class->name = "World";
    jsb_Genius_WorldWrapper_class->addProperty = JS_PropertyStub;
    jsb_Genius_WorldWrapper_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_WorldWrapper_class->getProperty = JS_PropertyStub;
    jsb_Genius_WorldWrapper_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_WorldWrapper_class->enumerate = JS_EnumerateStub;
    jsb_Genius_WorldWrapper_class->resolve = JS_ResolveStub;
    jsb_Genius_WorldWrapper_class->convert = JS_ConvertStub;
    jsb_Genius_WorldWrapper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("CreateEntity", js_app_WorldWrapper_CreateEntity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DestroyEntity", js_app_WorldWrapper_DestroyEntity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("GetWorld", js_app_WorldWrapper_GetWorld, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Genius_WorldWrapper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_WorldWrapper_class,
        dummy_constructor<Genius::WorldWrapper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_WorldWrapper_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "WorldWrapper"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::WorldWrapper>(cx, jsb_Genius_WorldWrapper_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_PawnBlackboard_class;
JSObject *jsb_Genius_PawnBlackboard_prototype;

bool js_app_PawnBlackboard_AddAction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_AddAction : Invalid Native Object");
    if (argc == 1) {
        Genius::PawnAction* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::PawnAction*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_AddAction : Error processing arguments");
        cobj->AddAction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_AddAction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_SetTargetX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_SetTargetX : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_SetTargetX : Error processing arguments");
        cobj->SetTargetX(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_SetTargetX : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_SetTargetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_SetTargetType : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_SetTargetType : Error processing arguments");
        cobj->SetTargetType(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_SetTargetType : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_SetAttr(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_SetAttr : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_SetAttr : Error processing arguments");
        cobj->SetAttr(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_SetAttr : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_PawnBlackboard_ModAttr(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_ModAttr : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_ModAttr : Error processing arguments");
        cobj->ModAttr(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_ModAttr : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_app_PawnBlackboard_FinishAction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_FinishAction : Invalid Native Object");
    if (argc == 1) {
        Genius::PawnAction* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::PawnAction*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_FinishAction : Error processing arguments");
        cobj->FinishAction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_FinishAction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_AddActionHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_AddActionHandler : Invalid Native Object");
    if (argc == 1) {
        Genius::ActionHandler* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::ActionHandler*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_AddActionHandler : Error processing arguments");
        cobj->AddActionHandler(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_AddActionHandler : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_Update(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_Update : Invalid Native Object");
    if (argc == 0) {
        cobj->Update();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_Update : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_PawnBlackboard_GetAttr(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_GetAttr : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_GetAttr : Error processing arguments");
        int ret = cobj->GetAttr(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_GetAttr : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_SetTargetY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_SetTargetY : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_SetTargetY : Error processing arguments");
        cobj->SetTargetY(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_SetTargetY : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_SetTargetID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_SetTargetID : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_SetTargetID : Error processing arguments");
        cobj->SetTargetID(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_SetTargetID : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_RemoveActionHandler(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::PawnBlackboard* cobj = (Genius::PawnBlackboard *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_PawnBlackboard_RemoveActionHandler : Invalid Native Object");
    if (argc == 1) {
        Genius::ActionHandler* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::ActionHandler*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_RemoveActionHandler : Error processing arguments");
        cobj->RemoveActionHandler(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_PawnBlackboard_RemoveActionHandler : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_PawnBlackboard_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::ComPawnAgent* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (Genius::ComPawnAgent*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_app_PawnBlackboard_constructor : Error processing arguments");
    Genius::PawnBlackboard* cobj = new (std::nothrow) Genius::PawnBlackboard(arg0);

    js_type_class_t *typeClass = js_get_type_from_native<Genius::PawnBlackboard>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::PawnBlackboard"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_Genius_PawnBlackboard_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PawnBlackboard)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::PawnBlackboard *nobj = static_cast<Genius::PawnBlackboard *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_PawnBlackboard(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_PawnBlackboard_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_PawnBlackboard_class->name = "PawnBlackboard";
    jsb_Genius_PawnBlackboard_class->addProperty = JS_PropertyStub;
    jsb_Genius_PawnBlackboard_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_PawnBlackboard_class->getProperty = JS_PropertyStub;
    jsb_Genius_PawnBlackboard_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_PawnBlackboard_class->enumerate = JS_EnumerateStub;
    jsb_Genius_PawnBlackboard_class->resolve = JS_ResolveStub;
    jsb_Genius_PawnBlackboard_class->convert = JS_ConvertStub;
    jsb_Genius_PawnBlackboard_class->finalize = js_Genius_PawnBlackboard_finalize;
    jsb_Genius_PawnBlackboard_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AddAction", js_app_PawnBlackboard_AddAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTargetX", js_app_PawnBlackboard_SetTargetX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTargetType", js_app_PawnBlackboard_SetTargetType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAttr", js_app_PawnBlackboard_SetAttr, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ModAttr", js_app_PawnBlackboard_ModAttr, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("FinishAction", js_app_PawnBlackboard_FinishAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddActionHandler", js_app_PawnBlackboard_AddActionHandler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Update", js_app_PawnBlackboard_Update, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAttr", js_app_PawnBlackboard_GetAttr, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTargetY", js_app_PawnBlackboard_SetTargetY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTargetID", js_app_PawnBlackboard_SetTargetID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RemoveActionHandler", js_app_PawnBlackboard_RemoveActionHandler, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_PawnBlackboard_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_PawnBlackboard_class,
        js_app_PawnBlackboard_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_PawnBlackboard_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "PawnBlackboard"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::PawnBlackboard>(cx, jsb_Genius_PawnBlackboard_class, proto, JS::NullPtr());
}

void register_all_app(JSContext* cx, JS::HandleObject obj) {
    // Get the global ns
    JS::RootedObject ns(cx, ScriptingCore::getInstance()->getGlobalObject());

    js_register_app_TimeSystem(cx, ns);
    js_register_app_Log(cx, ns);
    js_register_app_WorldWrapper(cx, ns);
    js_register_app_IComponent(cx, ns);
    js_register_app_ComBoxCollider(cx, ns);
    js_register_app_ComPawnAgent(cx, ns);
    js_register_app_ComDelayTrackMovement(cx, ns);
    js_register_app_ComBulletAnimBase(cx, ns);
    js_register_app_ComBulletAnimArrow(cx, ns);
    js_register_app_ComBulletDamage(cx, ns);
    js_register_app_ComPawnNavigation(cx, ns);
    js_register_app_PawnBlackboard(cx, ns);
    js_register_app_RollNumberLabel(cx, ns);
    js_register_app_ComPawnDebugDraw(cx, ns);
    js_register_app_SkillManager(cx, ns);
    js_register_app_ComParticle(cx, ns);
    js_register_app_ComRenderRoot(cx, ns);
    js_register_app_JSInvoker(cx, ns);
    js_register_app_ComTransform(cx, ns);
    js_register_app_EntityWrapper(cx, ns);
    js_register_app_ComPawnAnim(cx, ns);
    js_register_app_EntityUtility(cx, ns);
    js_register_app_ComBulletDebugDraw(cx, ns);
    js_register_app_BuffManager(cx, ns);
    js_register_app_SceneManager(cx, ns);
    js_register_app_ComBulletAnimEgg(cx, ns);
    js_register_app_ComBezierMovement(cx, ns);
    js_register_app_ComBulletAnimBomb(cx, ns);
    js_register_app_ComPawnFight(cx, ns);
    js_register_app_LoadingManager(cx, ns);
}

