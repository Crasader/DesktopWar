#include "base/ccConfig.h"
#ifndef __app_h__
#define __app_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_GamePlay_class;
extern JSObject *jsb_GamePlay_prototype;

bool js_app_GamePlay_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_GamePlay_finalize(JSContext *cx, JSObject *obj);
void js_register_app_GamePlay(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_GamePlay_SendMonster(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_GamePlay_SendHuman(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Logger_class;
extern JSObject *jsb_Logger_prototype;

bool js_app_Logger_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_Logger_finalize(JSContext *cx, JSObject *obj);
void js_register_app_Logger(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_Logger_print(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __app_h__
