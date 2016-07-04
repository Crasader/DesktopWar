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
JSClass  *jsb_GamePlay_class;
JSObject *jsb_GamePlay_prototype;

bool js_app_GamePlay_SendMonster(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GamePlay* cobj = (GamePlay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_GamePlay_SendMonster : Invalid Native Object");
    if (argc == 0) {
        cobj->SendMonster();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_GamePlay_SendMonster : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_GamePlay_SendHuman(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GamePlay* cobj = (GamePlay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_GamePlay_SendHuman : Invalid Native Object");
    if (argc == 0) {
        cobj->SendHuman();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_GamePlay_SendHuman : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_app_GamePlay(JSContext *cx, JS::HandleObject global) {
    jsb_GamePlay_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GamePlay_class->name = "GamePlay";
    jsb_GamePlay_class->addProperty = JS_PropertyStub;
    jsb_GamePlay_class->delProperty = JS_DeletePropertyStub;
    jsb_GamePlay_class->getProperty = JS_PropertyStub;
    jsb_GamePlay_class->setProperty = JS_StrictPropertyStub;
    jsb_GamePlay_class->enumerate = JS_EnumerateStub;
    jsb_GamePlay_class->resolve = JS_ResolveStub;
    jsb_GamePlay_class->convert = JS_ConvertStub;
    jsb_GamePlay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SendMonster", js_app_GamePlay_SendMonster, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SendHuman", js_app_GamePlay_SendHuman, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_GamePlay_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_GamePlay_class,
        dummy_constructor<GamePlay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_GamePlay_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "GamePlay"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<GamePlay>(cx, jsb_GamePlay_class, proto, JS::NullPtr());
}

JSClass  *jsb_Logger_class;
JSObject *jsb_Logger_prototype;

bool js_app_Logger_print(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_app_Logger_print : Error processing arguments");
        Log::print(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_app_Logger_print : wrong number of arguments");
    return false;
}


void js_register_app_Logger(JSContext *cx, JS::HandleObject global) {
    jsb_Logger_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Logger_class->name = "Logger";
    jsb_Logger_class->addProperty = JS_PropertyStub;
    jsb_Logger_class->delProperty = JS_DeletePropertyStub;
    jsb_Logger_class->getProperty = JS_PropertyStub;
    jsb_Logger_class->setProperty = JS_StrictPropertyStub;
    jsb_Logger_class->enumerate = JS_EnumerateStub;
    jsb_Logger_class->resolve = JS_ResolveStub;
    jsb_Logger_class->convert = JS_ConvertStub;
    jsb_Logger_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("print", js_app_Logger_print, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_Logger_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Logger_class,
        dummy_constructor<Log>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Logger_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Logger"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Log>(cx, jsb_Logger_class, proto, JS::NullPtr());
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
        JS_FN("AddToMapLayer", js_app_SceneManager_AddToMapLayer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Init", js_app_SceneManager_Init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Update", js_app_SceneManager_Update, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
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
bool js_app_LoadingManager_AddResource(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    LoadingManager* cobj = (LoadingManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_LoadingManager_AddResource : Invalid Native Object");
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_app_LoadingManager_AddResource : Error processing arguments");
        cobj->AddResource(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_LoadingManager_AddResource : wrong number of arguments: %d, was expecting %d", argc, 2);
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
        JS_FN("UpdateLoading", js_app_LoadingManager_UpdateLoading, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("AddResource", js_app_LoadingManager_AddResource, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsLoadingDone", js_app_LoadingManager_IsLoadingDone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLoadingPercent", js_app_LoadingManager_GetLoadingPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GenerateUnLoadList", js_app_LoadingManager_GenerateUnLoadList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
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

JSClass  *jsb_Genius_IDataManager_class;
JSObject *jsb_Genius_IDataManager_prototype;

bool js_app_IDataManager_GetSize(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IDataManager* cobj = (Genius::IDataManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IDataManager_GetSize : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetSize();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_IDataManager_GetSize : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_IDataManager_Destroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IDataManager* cobj = (Genius::IDataManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IDataManager_Destroy : Invalid Native Object");
    if (argc == 0) {
        cobj->Destroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_IDataManager_Destroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_IDataManager_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IDataManager* cobj = (Genius::IDataManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IDataManager_Init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->Init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_IDataManager_Init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_IDataManager_GetName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::IDataManager* cobj = (Genius::IDataManager *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_IDataManager_GetName : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->GetName();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_IDataManager_GetName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_app_IDataManager(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_IDataManager_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_IDataManager_class->name = "IDataManager";
    jsb_Genius_IDataManager_class->addProperty = JS_PropertyStub;
    jsb_Genius_IDataManager_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_IDataManager_class->getProperty = JS_PropertyStub;
    jsb_Genius_IDataManager_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_IDataManager_class->enumerate = JS_EnumerateStub;
    jsb_Genius_IDataManager_class->resolve = JS_ResolveStub;
    jsb_Genius_IDataManager_class->convert = JS_ConvertStub;
    jsb_Genius_IDataManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetSize", js_app_IDataManager_GetSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Destroy", js_app_IDataManager_Destroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Init", js_app_IDataManager_Init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetName", js_app_IDataManager_GetName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_IDataManager_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_IDataManager_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_IDataManager_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "IDataManager"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::IDataManager>(cx, jsb_Genius_IDataManager_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_AnimInfo_class;
JSObject *jsb_Genius_AnimInfo_prototype;

bool js_app_AnimInfo_FilePath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimInfo* cobj = (Genius::AnimInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimInfo_FilePath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->FilePath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_AnimInfo_FilePath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_app_AnimInfo(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_AnimInfo_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_AnimInfo_class->name = "AnimInfo";
    jsb_Genius_AnimInfo_class->addProperty = JS_PropertyStub;
    jsb_Genius_AnimInfo_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_AnimInfo_class->getProperty = JS_PropertyStub;
    jsb_Genius_AnimInfo_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_AnimInfo_class->enumerate = JS_EnumerateStub;
    jsb_Genius_AnimInfo_class->resolve = JS_ResolveStub;
    jsb_Genius_AnimInfo_class->convert = JS_ConvertStub;
    jsb_Genius_AnimInfo_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("FilePath", js_app_AnimInfo_FilePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Genius_AnimInfo_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_Genius_AnimInfo_class,
        dummy_constructor<Genius::AnimInfo>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_AnimInfo_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "AnimInfo"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::AnimInfo>(cx, jsb_Genius_AnimInfo_class, proto, JS::NullPtr());
}

JSClass  *jsb_Genius_AnimDataMgr_class;
JSObject *jsb_Genius_AnimDataMgr_prototype;

bool js_app_AnimDataMgr_GetName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimDataMgr* cobj = (Genius::AnimDataMgr *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimDataMgr_GetName : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->GetName();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_AnimDataMgr_GetName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_AnimDataMgr_FindAnimInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimDataMgr* cobj = (Genius::AnimDataMgr *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimDataMgr_FindAnimInfo : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_app_AnimDataMgr_FindAnimInfo : Error processing arguments");
        Genius::AnimInfo* ret = cobj->FindAnimInfo(arg0);
        jsval jsret = JSVAL_NULL;
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<Genius::AnimInfo>(cx, (Genius::AnimInfo*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_AnimDataMgr_FindAnimInfo : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_app_AnimDataMgr_GetSize(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimDataMgr* cobj = (Genius::AnimDataMgr *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimDataMgr_GetSize : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetSize();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_AnimDataMgr_GetSize : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_AnimDataMgr_Init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimDataMgr* cobj = (Genius::AnimDataMgr *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimDataMgr_Init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->Init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_app_AnimDataMgr_Init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_AnimDataMgr_Destroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    Genius::AnimDataMgr* cobj = (Genius::AnimDataMgr *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_app_AnimDataMgr_Destroy : Invalid Native Object");
    if (argc == 0) {
        cobj->Destroy();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_app_AnimDataMgr_Destroy : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_app_AnimDataMgr_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    Genius::AnimDataMgr* cobj = new (std::nothrow) Genius::AnimDataMgr();

    js_type_class_t *typeClass = js_get_type_from_native<Genius::AnimDataMgr>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "Genius::AnimDataMgr"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_Genius_IDataManager_prototype;

void js_Genius_AnimDataMgr_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (AnimDataMgr)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        Genius::AnimDataMgr *nobj = static_cast<Genius::AnimDataMgr *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            delete nobj;
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_app_AnimDataMgr(JSContext *cx, JS::HandleObject global) {
    jsb_Genius_AnimDataMgr_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_Genius_AnimDataMgr_class->name = "AnimDataMgr";
    jsb_Genius_AnimDataMgr_class->addProperty = JS_PropertyStub;
    jsb_Genius_AnimDataMgr_class->delProperty = JS_DeletePropertyStub;
    jsb_Genius_AnimDataMgr_class->getProperty = JS_PropertyStub;
    jsb_Genius_AnimDataMgr_class->setProperty = JS_StrictPropertyStub;
    jsb_Genius_AnimDataMgr_class->enumerate = JS_EnumerateStub;
    jsb_Genius_AnimDataMgr_class->resolve = JS_ResolveStub;
    jsb_Genius_AnimDataMgr_class->convert = JS_ConvertStub;
    jsb_Genius_AnimDataMgr_class->finalize = js_Genius_AnimDataMgr_finalize;
    jsb_Genius_AnimDataMgr_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetName", js_app_AnimDataMgr_GetName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("FindAnimInfo", js_app_AnimDataMgr_FindAnimInfo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSize", js_app_AnimDataMgr_GetSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Init", js_app_AnimDataMgr_Init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Destroy", js_app_AnimDataMgr_Destroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_Genius_IDataManager_prototype);
    jsb_Genius_AnimDataMgr_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_Genius_AnimDataMgr_class,
        js_app_AnimDataMgr_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_Genius_AnimDataMgr_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "AnimDataMgr"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<Genius::AnimDataMgr>(cx, jsb_Genius_AnimDataMgr_class, proto, parent_proto);
}

void register_all_app(JSContext* cx, JS::HandleObject obj) {
    // Get the global ns
    JS::RootedObject ns(cx, ScriptingCore::getInstance()->getGlobalObject());

    js_register_app_SceneManager(cx, ns);
    js_register_app_RollNumberLabel(cx, ns);
    js_register_app_IDataManager(cx, ns);
    js_register_app_AnimDataMgr(cx, ns);
    js_register_app_Logger(cx, ns);
    js_register_app_AnimInfo(cx, ns);
    js_register_app_GamePlay(cx, ns);
    js_register_app_LoadingManager(cx, ns);
}

