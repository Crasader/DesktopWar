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

extern JSClass  *jsb_JSInvoker_class;
extern JSObject *jsb_JSInvoker_prototype;

bool js_app_JSInvoker_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_JSInvoker_finalize(JSContext *cx, JSObject *obj);
void js_register_app_JSInvoker(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_JSInvoker_Invoke_PushEvent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_JSInvoker_Invoke_Update(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_JSInvoker_Invoke_ArmatureFrameEvent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_JSInvoker_Invoke_LongUpdate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_JSInvoker_Invoke_ModifyEntityAttr(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_JSInvoker_Invoke_ArmatureMovementEvent(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_TimeSystem_class;
extern JSObject *jsb_Genius_TimeSystem_prototype;

bool js_app_TimeSystem_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_TimeSystem_finalize(JSContext *cx, JSObject *obj);
void js_register_app_TimeSystem(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_TimeSystem_TimeSinceStart(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_TimeSystem_TimeSystem(JSContext *cx, uint32_t argc, jsval *vp);

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
bool js_app_IComponent_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_IComponent_GetEntity(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComTransform_class;
extern JSObject *jsb_Genius_ComTransform_prototype;

bool js_app_ComTransform_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComTransform_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComTransform(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComTransform_MoveTo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_SetDirection(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_GetDir(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_GetX(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_GetY(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_GetVY(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_GetVX(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_FaceTo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_SetPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_SetVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_MoveTowards(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComTransform_ComTransform(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBoxCollider_class;
extern JSObject *jsb_Genius_ComBoxCollider_prototype;

bool js_app_ComBoxCollider_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBoxCollider_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBoxCollider(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBoxCollider_GetWidth(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBoxCollider_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBoxCollider_GetHeight(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComRenderRoot_class;
extern JSObject *jsb_Genius_ComRenderRoot_prototype;

bool js_app_ComRenderRoot_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComRenderRoot_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComRenderRoot(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComRenderRoot_AddChild(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComRenderRoot_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComRenderRoot_ComRenderRoot(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComParticle_class;
extern JSObject *jsb_Genius_ComParticle_prototype;

bool js_app_ComParticle_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComParticle_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComParticle(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComParticle_Create(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBezierMovement_class;
extern JSObject *jsb_Genius_ComBezierMovement_prototype;

bool js_app_ComBezierMovement_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBezierMovement_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBezierMovement(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBezierMovement_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBezierMovement_Stop(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBezierMovement_IsDone(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComDelayTrackMovement_class;
extern JSObject *jsb_Genius_ComDelayTrackMovement_prototype;

bool js_app_ComDelayTrackMovement_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComDelayTrackMovement_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComDelayTrackMovement(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComDelayTrackMovement_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComDelayTrackMovement_ComDelayTrackMovement(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnAgent_class;
extern JSObject *jsb_Genius_ComPawnAgent_prototype;

bool js_app_ComPawnAgent_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnAgent_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnAgent(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnAgent_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAgent_AddAction(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnAnim_class;
extern JSObject *jsb_Genius_ComPawnAnim_prototype;

bool js_app_ComPawnAnim_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnAnim_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnAnim(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnAnim_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_PlayFloatNumber(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_GetHeight(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_PlayAnimation(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_GetWidth(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_SetDebugLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_UpdateLifeBar(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_SetPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_ContainAnim(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnAnim_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComPawnDebugDraw_class;
extern JSObject *jsb_Genius_ComPawnDebugDraw_prototype;

bool js_app_ComPawnDebugDraw_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComPawnDebugDraw_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComPawnDebugDraw(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComPawnDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComPawnDebugDraw_Refresh(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimBase_class;
extern JSObject *jsb_Genius_ComBulletAnimBase_prototype;

bool js_app_ComBulletAnimBase_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimBase_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimBase(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimBase_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimBase_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp);

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

extern JSClass  *jsb_Genius_ComBulletDamage_class;
extern JSObject *jsb_Genius_ComBulletDamage_prototype;

bool js_app_ComBulletDamage_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDamage_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDamage(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);

extern JSClass  *jsb_Genius_ComBulletDebugDraw_class;
extern JSObject *jsb_Genius_ComBulletDebugDraw_prototype;

bool js_app_ComBulletDebugDraw_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletDebugDraw_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletDebugDraw(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletDebugDraw_Clear(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletDebugDraw_Refresh(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_ComBulletAnimEgg_class;
extern JSObject *jsb_Genius_ComBulletAnimEgg_prototype;

bool js_app_ComBulletAnimEgg_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_ComBulletAnimEgg_finalize(JSContext *cx, JSObject *obj);
void js_register_app_ComBulletAnimEgg(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_ComBulletAnimEgg_AnimationMovementCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimEgg_Create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_ComBulletAnimEgg_AnimationFrameCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_EntityUtility_class;
extern JSObject *jsb_EntityUtility_prototype;

bool js_app_EntityUtility_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_EntityUtility_finalize(JSContext *cx, JSObject *obj);
void js_register_app_EntityUtility(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_EntityUtility_IsEnemy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_IsInMyViewSight(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_IsInMyFarRange(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_FindTargetsInScope(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_GetEnemyTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_FindRandTargetByTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_IsInMyNearRange(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_AreEntitiesCloseEnough(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_IsTagged(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityUtility_FindNearestTarget(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_SkillManager_class;
extern JSObject *jsb_Genius_SkillManager_prototype;

bool js_app_SkillManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_SkillManager_finalize(JSContext *cx, JSObject *obj);
void js_register_app_SkillManager(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_SkillManager_ClearSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_LoadSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_UseSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_SaveSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_ClearAllSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_CanUseSkill(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_GetMe(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_SkillManager_SkillManager(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_BuffManager_class;
extern JSObject *jsb_Genius_BuffManager_prototype;

bool js_app_BuffManager_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_BuffManager_finalize(JSContext *cx, JSObject *obj);
void js_register_app_BuffManager(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_BuffManager_GetBuffCount(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_BuffManager_RemoveBuff(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_BuffManager_RemoveAllBuff(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_BuffManager_AddBuff(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_BuffManager_GetMe(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_BuffManager_BuffManager(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_EntityWrapper_class;
extern JSObject *jsb_Genius_EntityWrapper_prototype;

bool js_app_EntityWrapper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_EntityWrapper_finalize(JSContext *cx, JSObject *obj);
void js_register_app_EntityWrapper(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_EntityWrapper_RemoveTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_AddComponent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_GetID(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_OnDestroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_AddTag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_EntityWrapper_EntityWrapper(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_Genius_WorldWrapper_class;
extern JSObject *jsb_Genius_WorldWrapper_prototype;

bool js_app_WorldWrapper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_app_WorldWrapper_finalize(JSContext *cx, JSObject *obj);
void js_register_app_WorldWrapper(JSContext *cx, JS::HandleObject global);
void register_all_app(JSContext* cx, JS::HandleObject obj);
bool js_app_WorldWrapper_CreateEntity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_WorldWrapper_DestroyEntity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_app_WorldWrapper_GetWorld(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __app_h__
