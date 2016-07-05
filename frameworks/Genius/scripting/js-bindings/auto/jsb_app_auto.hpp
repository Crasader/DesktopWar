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

extern JSClass  *jsb_Genius_SceneManager_class;
extern JSObject *jsb_Genius_SceneManager_prototype;

bool js_app_SceneManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_SceneManager_finalize(JSContext *cx, JSObject *obj);
void js_register_app_SceneManager(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_SceneManager_ShakeScene(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_AddToMapLayer(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_Init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_Update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_GetMapLayer(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_GetSingleton(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_RollNumberLabel_class;
extern JSObject *jsb_RollNumberLabel_prototype;

bool js_app_RollNumberLabel_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_RollNumberLabel_finalize(JSContext *cx, JSObject *obj);
void js_register_app_RollNumberLabel(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_RollNumberLabel_setColor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_setStartNumber(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_rollTo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_isRollDone(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_RollNumberLabel_RollNumberLabel(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_LoadingManager_class;
extern JSObject *jsb_LoadingManager_prototype;

bool js_app_LoadingManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_LoadingManager_finalize(JSContext *cx, JSObject *obj);
void js_register_app_LoadingManager(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_LoadingManager_StartLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_UpdateLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_AddResource(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_IsLoadingDone(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_GetLoadingPercent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_GenerateUnLoadList(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_ClearLoadingList(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_LoadingManager(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __app_h__
