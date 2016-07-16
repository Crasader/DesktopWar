#include "base/ccConfig.h"
#ifndef __app_h__
#define __app_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_Log_class;
extern JSObject *jsb_Log_prototype;

bool js_app_Log_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_Log_finalize(JSContext *cx, JSObject *obj);
void js_register_app_Log(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_Log_print(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_SceneManager_class;
extern JSObject *jsb_Genius_SceneManager_prototype;

bool js_app_SceneManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_SceneManager_finalize(JSContext *cx, JSObject *obj);
void js_register_app_SceneManager(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_SceneManager_ShakeScene(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_Init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_Update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SceneManager_AddToMapLayer(JSContext *cx, uint32_t argc, jsval *vp);
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
bool js_app_LoadingManager_AddBullet(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_AddAnim(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_UpdateLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_GenerateUnLoadList(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_IsLoadingDone(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_GetLoadingPercent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_AddRole(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_ClearLoadingList(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_LoadingManager_LoadingManager(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_IComponent_class;
extern JSObject *jsb_Genius_IComponent_prototype;

bool js_app_IComponent_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_IComponent_finalize(JSContext *cx, JSObject *obj);
void js_register_app_IComponent(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);

extern JSClass  *jsb_Genius_ComTransform_class;
extern JSObject *jsb_Genius_ComTransform_prototype;

bool js_app_ComTransform_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComTransform_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComTransform(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComTransform_SetPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_SetVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_SetDirection(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_create_ComTransform(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBoxCollider_class;
extern JSObject *jsb_Genius_ComBoxCollider_prototype;

bool js_app_ComBoxCollider_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBoxCollider_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBoxCollider(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBoxCollider_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBoxCollider_create_ComBoxCollider(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComColliderHandler_class;
extern JSObject *jsb_Genius_ComColliderHandler_prototype;

bool js_app_ComColliderHandler_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComColliderHandler_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComColliderHandler(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComColliderHandler_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComColliderHandler_create_ComColliderHandler(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComAnimation_class;
extern JSObject *jsb_Genius_ComAnimation_prototype;

bool js_app_ComAnimation_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComAnimation_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComAnimation(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComAnimation_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComAnimation_create_ComAnimation(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComAnimation_ComAnimation(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComParticle_class;
extern JSObject *jsb_Genius_ComParticle_prototype;

bool js_app_ComParticle_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComParticle_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComParticle(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComParticle_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComParticle_create_ComParticle(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBezierMovement_class;
extern JSObject *jsb_Genius_ComBezierMovement_prototype;

bool js_app_ComBezierMovement_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBezierMovement_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBezierMovement(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBezierMovement_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBezierMovement_Stop(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBezierMovement_IsDone(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBezierMovement_create_ComBezierMovement(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnAgent_class;
extern JSObject *jsb_Genius_ComPawnAgent_prototype;

bool js_app_ComPawnAgent_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnAgent_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnAgent(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnAgent_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAgent_AddAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAgent_GetBlackboard(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAgent_create_ComPawnAgent(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnAnim_class;
extern JSObject *jsb_Genius_ComPawnAnim_prototype;

bool js_app_ComPawnAnim_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnAnim_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnAnim(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnAnim_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_PlayFloatNumber(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_HaveThisAnimation(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_HandleAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_GetHeight(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_PlayAnimation(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_GetWidth(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_Init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_SetDebugLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_SetPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnDebugDraw_class;
extern JSObject *jsb_Genius_ComPawnDebugDraw_prototype;

bool js_app_ComPawnDebugDraw_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnDebugDraw_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnDebugDraw(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnDebugDraw_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnDebugDraw_create_ComPawnDebugDraw(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnFight_class;
extern JSObject *jsb_Genius_ComPawnFight_prototype;

bool js_app_ComPawnFight_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnFight_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnFight(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnFight_Init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnFight_create_ComPawnFight(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnFight_ComPawnFight(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnNavigation_class;
extern JSObject *jsb_Genius_ComPawnNavigation_prototype;

bool js_app_ComPawnNavigation_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnNavigation_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnNavigation(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnNavigation_MoveTo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnNavigation_create_ComPawnNavigation(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnNavigation_ComPawnNavigation(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnBevtree_class;
extern JSObject *jsb_Genius_ComPawnBevtree_prototype;

bool js_app_ComPawnBevtree_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnBevtree_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnBevtree(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnBevtree_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnBevtree_create_ComPawnBevtree(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimBase_class;
extern JSObject *jsb_Genius_ComBulletAnimBase_prototype;

bool js_app_ComBulletAnimBase_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimBase_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimBase(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimBase_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBase_create_ComBulletAnimBase(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimArrow_class;
extern JSObject *jsb_Genius_ComBulletAnimArrow_prototype;

bool js_app_ComBulletAnimArrow_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimArrow_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimArrow(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimArrow_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimArrow_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimArrow_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimArrow_StayStill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimArrow_create_ComBulletAnimArrow(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimBomb_class;
extern JSObject *jsb_Genius_ComBulletAnimBomb_prototype;

bool js_app_ComBulletAnimBomb_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimBomb_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimBomb(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimBomb_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBomb_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBomb_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBomb_StartExplode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBomb_create_ComBulletAnimBomb(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletDamageNone_class;
extern JSObject *jsb_Genius_ComBulletDamageNone_prototype;

bool js_app_ComBulletDamageNone_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDamageNone_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDamageNone(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletDamageNone_create_ComBulletDamageNone(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletDamageNone_ComBulletDamageNone(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletDamageScope_class;
extern JSObject *jsb_Genius_ComBulletDamageScope_prototype;

bool js_app_ComBulletDamageScope_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDamageScope_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDamageScope(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletDamageScope_create_ComBulletDamageScope(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletDamageScope_ComBulletDamageScope(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletDamageSingle_class;
extern JSObject *jsb_Genius_ComBulletDamageSingle_prototype;

bool js_app_ComBulletDamageSingle_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDamageSingle_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDamageSingle(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletDamageSingle_create_ComBulletDamageSingle(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletDebugDraw_class;
extern JSObject *jsb_Genius_ComBulletDebugDraw_prototype;

bool js_app_ComBulletDebugDraw_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDebugDraw_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDebugDraw(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletDebugDraw_create_ComBulletDebugDraw(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletDebugDraw_ComBulletDebugDraw(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimEgg_class;
extern JSObject *jsb_Genius_ComBulletAnimEgg_prototype;

bool js_app_ComBulletAnimEgg_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimEgg_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimEgg(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimEgg_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimEgg_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimEgg_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimEgg_create_ComBulletAnimEgg(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_EntityCreator_class;
extern JSObject *jsb_Genius_EntityCreator_prototype;

bool js_app_EntityCreator_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_EntityCreator_finalize(JSContext *cx, JSObject *obj);
void js_register_app_EntityCreator(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_EntityCreator_CreateBullet(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityCreator_CreatePawn(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityCreator_CreateBornPoint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_EntityWrapper_class;
extern JSObject *jsb_Genius_EntityWrapper_prototype;

bool js_app_EntityWrapper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_EntityWrapper_finalize(JSContext *cx, JSObject *obj);
void js_register_app_EntityWrapper(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_EntityWrapper_GetID(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_RemoveTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_AddTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_AddComponent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_EntityWrapper(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_WorldWrapper_class;
extern JSObject *jsb_Genius_WorldWrapper_prototype;

bool js_app_WorldWrapper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_WorldWrapper_finalize(JSContext *cx, JSObject *obj);
void js_register_app_WorldWrapper(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_WorldWrapper_CreateEntity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_WorldWrapper_GetWorld(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_PawnBlackboard_class;
extern JSObject *jsb_Genius_PawnBlackboard_prototype;

bool js_app_PawnBlackboard_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_PawnBlackboard_finalize(JSContext *cx, JSObject *obj);
void js_register_app_PawnBlackboard(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_PawnBlackboard_AddAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_SetAttr(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_ModAttr(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_FinishAction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_AddActionHandler(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_Update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_GetAttr(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_RemoveActionHandler(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_PawnBlackboard_PawnBlackboard(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __app_h__
