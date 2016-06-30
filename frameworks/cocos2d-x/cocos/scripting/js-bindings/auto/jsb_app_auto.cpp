#include "jsb_app_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "JSBHeaders.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

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


void js_GamePlay_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GamePlay)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        GamePlay *nobj = static_cast<GamePlay *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
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
    jsb_GamePlay_class->finalize = js_GamePlay_finalize;
    jsb_GamePlay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
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
        JS::NullPtr(), // parent proto
        jsb_GamePlay_class,
        dummy_constructor<GamePlay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GamePlay", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GamePlay> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GamePlay_class;
        p->proto = jsb_GamePlay_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_Logger_class;
JSObject *jsb_Logger_prototype;



void js_Logger_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Logger)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        Logger *nobj = static_cast<Logger *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
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
    jsb_Logger_class->finalize = js_Logger_finalize;
    jsb_Logger_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_Logger_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_Logger_class,
        dummy_constructor<Logger>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "Logger", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<Logger> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_Logger_class;
        p->proto = jsb_Logger_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

void register_all_app(JSContext* cx, JS::HandleObject obj) {

    js_register_app_Logger(cx, ns);
    js_register_app_GamePlay(cx, ns);
}

