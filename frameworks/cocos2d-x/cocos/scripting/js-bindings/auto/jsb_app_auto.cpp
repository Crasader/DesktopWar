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
        Logger::print(arg0);
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
        dummy_constructor<Logger>, 0, // no constructor
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
    jsb_register_class<Logger>(cx, jsb_Logger_class, proto, JS::NullPtr());
}

void register_all_app(JSContext* cx, JS::HandleObject obj) {
    // Get the global ns
    JS::RootedObject ns(cx, ScriptingCore::getInstance()->getGlobalObject());

    js_register_app_Logger(cx, ns);
    js_register_app_GamePlay(cx, ns);
}

