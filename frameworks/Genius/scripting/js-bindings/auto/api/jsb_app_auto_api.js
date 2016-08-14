
/**
 * @class Log
 */
Log = {

/**
 * @method print
 * @param {char} arg0
 */
print : function (
char 
)
{
},

};

/**
 * @class JSInvoker
 */
JSInvoker = {

/**
 * @method Invoke_PushEvent
 * @param {int} arg0
 * @param {char} arg1
 */
Invoke_PushEvent : function (
int, 
char 
)
{
},

/**
 * @method Invoke_Update
 * @param {float} arg0
 */
Invoke_Update : function (
float 
)
{
},

/**
 * @method Invoke_ArmatureFrameEvent
 * @param {int} arg0
 * @param {char} arg1
 */
Invoke_ArmatureFrameEvent : function (
int, 
char 
)
{
},

/**
 * @method Invoke_LongUpdate
 * @param {float} arg0
 */
Invoke_LongUpdate : function (
float 
)
{
},

/**
 * @method Invoke_ModifyEntityAttr
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 * @param {int} arg3
 * @param {int} arg4
 */
Invoke_ModifyEntityAttr : function (
int, 
int, 
int, 
int, 
int 
)
{
},

/**
 * @method Invoke_ArmatureMovementEvent
 * @param {int} arg0
 * @param {int} arg1
 * @param {char} arg2
 */
Invoke_ArmatureMovementEvent : function (
int, 
int, 
char 
)
{
},

};

/**
 * @class TimeSystem
 */
TimeSystem = {

/**
 * @method TimeSinceStart
 * @return {float}
 */
TimeSinceStart : function (
)
{
    return 0;
},

/**
 * @method TimeSystem
 * @constructor
 */
TimeSystem : function (
)
{
},

};

/**
 * @class SceneManager
 */
SceneManager = {

/**
 * @method ShakeScene
 */
ShakeScene : function (
)
{
},

/**
 * @method Init
 * @return {bool}
 */
Init : function (
)
{
    return false;
},

/**
 * @method Update
 */
Update : function (
)
{
},

/**
 * @method AddToMapLayer
 * @param {cc.Node} arg0
 * @param {float} arg1
 * @param {float} arg2
 * @param {int} arg3
 */
AddToMapLayer : function (
node, 
float, 
float, 
int 
)
{
},

/**
 * @method GetMapLayer
 * @return {cc.Node}
 */
GetMapLayer : function (
)
{
    return cc.Node;
},

/**
 * @method GetSingleton
 * @return {Genius::SceneManager}
 */
GetSingleton : function (
)
{
    return Genius::SceneManager;
},

};

/**
 * @class RollNumberLabel
 */
RollNumberLabel = {

/**
 * @method setColor
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 */
setColor : function (
int, 
int, 
int 
)
{
},

/**
 * @method update
 * @param {float} arg0
 */
update : function (
float 
)
{
},

/**
 * @method setStartNumber
 * @param {int} arg0
 */
setStartNumber : function (
int 
)
{
},

/**
 * @method rollTo
 * @param {int} arg0
 */
rollTo : function (
int 
)
{
},

/**
 * @method isRollDone
 * @return {bool}
 */
isRollDone : function (
)
{
    return false;
},

/**
 * @method create
 * @return {RollNumberLabel}
 */
create : function (
)
{
    return RollNumberLabel;
},

/**
 * @method RollNumberLabel
 * @constructor
 */
RollNumberLabel : function (
)
{
},

};

/**
 * @class LoadingManager
 */
LoadingManager = {

/**
 * @method StartLoading
 */
StartLoading : function (
)
{
},

/**
 * @method AddBullet
 * @param {int} arg0
 */
AddBullet : function (
int 
)
{
},

/**
 * @method AddAnim
 * @param {int} arg0
 */
AddAnim : function (
int 
)
{
},

/**
 * @method UpdateLoading
 */
UpdateLoading : function (
)
{
},

/**
 * @method GenerateUnLoadList
 */
GenerateUnLoadList : function (
)
{
},

/**
 * @method IsLoadingDone
 * @return {bool}
 */
IsLoadingDone : function (
)
{
    return false;
},

/**
 * @method GetLoadingPercent
 * @return {int}
 */
GetLoadingPercent : function (
)
{
    return 0;
},

/**
 * @method AddRole
 * @param {int} arg0
 */
AddRole : function (
int 
)
{
},

/**
 * @method ClearLoadingList
 */
ClearLoadingList : function (
)
{
},

/**
 * @method LoadingManager
 * @constructor
 */
LoadingManager : function (
)
{
},

};

/**
 * @class IComponent
 */
IComponent = {

/**
 * @method OnDestroy
 */
OnDestroy : function (
)
{
},

/**
 * @method GetEntity
 * @return {Genius::Entity}
 */
GetEntity : function (
)
{
    return Genius::Entity;
},

};

/**
 * @class ComTransform
 */
ComTransform = {

/**
 * @method MoveTo
 * @param {float} arg0
 * @param {float} arg1
 * @param {float} arg2
 */
MoveTo : function (
float, 
float, 
float 
)
{
},

/**
 * @method SetDirection
 * @param {int} arg0
 */
SetDirection : function (
int 
)
{
},

/**
 * @method GetDir
 * @return {int}
 */
GetDir : function (
)
{
    return 0;
},

/**
 * @method GetX
 * @return {float}
 */
GetX : function (
)
{
    return 0;
},

/**
 * @method GetY
 * @return {float}
 */
GetY : function (
)
{
    return 0;
},

/**
 * @method GetVY
 * @return {float}
 */
GetVY : function (
)
{
    return 0;
},

/**
 * @method GetVX
 * @return {float}
 */
GetVX : function (
)
{
    return 0;
},

/**
 * @method FaceTo
 * @param {float} arg0
 * @param {float} arg1
 */
FaceTo : function (
float, 
float 
)
{
},

/**
 * @method SetPosition
 * @param {float} arg0
 * @param {float} arg1
 */
SetPosition : function (
float, 
float 
)
{
},

/**
 * @method SetVelocity
 * @param {float} arg0
 * @param {float} arg1
 */
SetVelocity : function (
float, 
float 
)
{
},

/**
 * @method MoveTowards
 * @param {float} arg0
 * @param {float} arg1
 */
MoveTowards : function (
float, 
float 
)
{
},

/**
 * @method ComTransform
 * @constructor
 */
ComTransform : function (
)
{
},

};

/**
 * @class ComBoxCollider
 */
ComBoxCollider = {

/**
 * @method GetWidth
 * @return {float}
 */
GetWidth : function (
)
{
    return 0;
},

/**
 * @method Create
 * @param {bool} arg0
 * @param {float} arg1
 * @param {float} arg2
 * @param {float} arg3
 * @param {float} arg4
 */
Create : function (
bool, 
float, 
float, 
float, 
float 
)
{
},

/**
 * @method GetHeight
 * @return {float}
 */
GetHeight : function (
)
{
    return 0;
},

};

/**
 * @class ComRenderRoot
 */
ComRenderRoot = {

/**
 * @method AddChild
 * @param {cc.Node} arg0
 */
AddChild : function (
node 
)
{
},

/**
 * @method OnDestroy
 */
OnDestroy : function (
)
{
},

/**
 * @method ComRenderRoot
 * @constructor
 */
ComRenderRoot : function (
)
{
},

};

/**
 * @class ComParticle
 */
ComParticle = {

/**
 * @method Create
 * @param {String} arg0
 */
Create : function (
str 
)
{
},

};

/**
 * @class ComBezierMovement
 */
ComBezierMovement = {

/**
 * @method Create
 * @param {float} arg0
 * @param {float} arg1
 * @param {float} arg2
 * @param {float} arg3
 * @param {float} arg4
 */
Create : function (
float, 
float, 
float, 
float, 
float 
)
{
},

/**
 * @method Stop
 */
Stop : function (
)
{
},

/**
 * @method IsDone
 * @return {bool}
 */
IsDone : function (
)
{
    return false;
},

};

/**
 * @class ComDelayTrackMovement
 */
ComDelayTrackMovement = {

/**
 * @method Create
 * @param {int} arg0
 * @param {float} arg1
 */
Create : function (
int, 
float 
)
{
},

/**
 * @method ComDelayTrackMovement
 * @constructor
 */
ComDelayTrackMovement : function (
)
{
},

};

/**
 * @class ComPawnAgent
 */
ComPawnAgent = {

/**
 * @method Create
 * @param {int} arg0
 * @param {bool} arg1
 */
Create : function (
int, 
bool 
)
{
},

/**
 * @method AddAction
 * @param {int} arg0
 */
AddAction : function (
int 
)
{
},

};

/**
 * @class ComPawnAnim
 */
ComPawnAnim = {

/**
 * @method AnimationMovementCallback
 * @param {ccs.Armature} arg0
 * @param {ccs.MovementEventType} arg1
 * @param {String} arg2
 */
AnimationMovementCallback : function (
armature, 
movementeventtype, 
str 
)
{
},

/**
 * @method PlayFloatNumber
 * @param {int} arg0
 * @param {int} arg1
 */
PlayFloatNumber : function (
int, 
int 
)
{
},

/**
 * @method Create
 * @param {int} arg0
 */
Create : function (
int 
)
{
},

/**
 * @method GetHeight
 * @return {float}
 */
GetHeight : function (
)
{
    return 0;
},

/**
 * @method PlayAnimation
 * @param {String} arg0
 */
PlayAnimation : function (
str 
)
{
},

/**
 * @method GetWidth
 * @return {float}
 */
GetWidth : function (
)
{
    return 0;
},

/**
 * @method OnDestroy
 */
OnDestroy : function (
)
{
},

/**
 * @method SetDebugLabel
 * @param {String} arg0
 */
SetDebugLabel : function (
str 
)
{
},

/**
 * @method UpdateLifeBar
 * @param {int} arg0
 */
UpdateLifeBar : function (
int 
)
{
},

/**
 * @method SetPosition
 * @param {float} arg0
 * @param {float} arg1
 */
SetPosition : function (
float, 
float 
)
{
},

/**
 * @method ContainAnim
 * @param {String} arg0
 * @return {bool}
 */
ContainAnim : function (
str 
)
{
    return false;
},

/**
 * @method AnimationFrameCallback
 * @param {ccs.Bone} arg0
 * @param {String} arg1
 * @param {int} arg2
 * @param {int} arg3
 */
AnimationFrameCallback : function (
bone, 
str, 
int, 
int 
)
{
},

};

/**
 * @class ComPawnDebugDraw
 */
ComPawnDebugDraw = {

/**
 * @method Clear
 */
Clear : function (
)
{
},

/**
 * @method Refresh
 */
Refresh : function (
)
{
},

};

/**
 * @class ComBulletAnimBase
 */
ComBulletAnimBase = {

/**
 * @method Create
 * @param {String} arg0
 */
Create : function (
str 
)
{
},

/**
 * @method OnDestroy
 */
OnDestroy : function (
)
{
},

};

/**
 * @class ComBulletAnimArrow
 */
ComBulletAnimArrow = {

/**
 * @method AnimationMovementCallback
 * @param {ccs.Armature} arg0
 * @param {ccs.MovementEventType} arg1
 * @param {String} arg2
 */
AnimationMovementCallback : function (
armature, 
movementeventtype, 
str 
)
{
},

/**
 * @method Create
 * @param {String} arg0
 */
Create : function (
str 
)
{
},

/**
 * @method AnimationFrameCallback
 * @param {ccs.Bone} arg0
 * @param {String} arg1
 * @param {int} arg2
 * @param {int} arg3
 */
AnimationFrameCallback : function (
bone, 
str, 
int, 
int 
)
{
},

/**
 * @method StayStill
 */
StayStill : function (
)
{
},

};

/**
 * @class ComBulletAnimBomb
 */
ComBulletAnimBomb = {

/**
 * @method AnimationMovementCallback
 * @param {ccs.Armature} arg0
 * @param {ccs.MovementEventType} arg1
 * @param {String} arg2
 */
AnimationMovementCallback : function (
armature, 
movementeventtype, 
str 
)
{
},

/**
 * @method Create
 * @param {String} arg0
 * @param {String} arg1
 */
Create : function (
str, 
str 
)
{
},

/**
 * @method AnimationFrameCallback
 * @param {ccs.Bone} arg0
 * @param {String} arg1
 * @param {int} arg2
 * @param {int} arg3
 */
AnimationFrameCallback : function (
bone, 
str, 
int, 
int 
)
{
},

/**
 * @method StartExplode
 */
StartExplode : function (
)
{
},

};

/**
 * @class ComBulletDamage
 */
ComBulletDamage = {

};

/**
 * @class ComBulletDebugDraw
 */
ComBulletDebugDraw = {

/**
 * @method Clear
 */
Clear : function (
)
{
},

/**
 * @method Refresh
 */
Refresh : function (
)
{
},

};

/**
 * @class ComBulletAnimEgg
 */
ComBulletAnimEgg = {

/**
 * @method AnimationMovementCallback
 * @param {ccs.Armature} arg0
 * @param {ccs.MovementEventType} arg1
 * @param {String} arg2
 */
AnimationMovementCallback : function (
armature, 
movementeventtype, 
str 
)
{
},

/**
 * @method Create
 * @param {String} arg0
 */
Create : function (
str 
)
{
},

/**
 * @method AnimationFrameCallback
 * @param {ccs.Bone} arg0
 * @param {String} arg1
 * @param {int} arg2
 * @param {int} arg3
 */
AnimationFrameCallback : function (
bone, 
str, 
int, 
int 
)
{
},

};

/**
 * @class EntityUtility
 */
EntityUtility = {

/**
 * @method IsEnemy
 * @param {Genius::Entity} arg0
 * @param {Genius::Entity} arg1
 * @return {bool}
 */
IsEnemy : function (
entity, 
entity 
)
{
    return false;
},

/**
 * @method IsInMyViewSight
 * @param {Genius::EntityWrapper} arg0
 * @param {Genius::EntityWrapper} arg1
 * @return {bool}
 */
IsInMyViewSight : function (
entitywrapper, 
entitywrapper 
)
{
    return false;
},

/**
 * @method IsInMyFarRange
 * @param {Genius::EntityWrapper} arg0
 * @param {Genius::EntityWrapper} arg1
 * @return {bool}
 */
IsInMyFarRange : function (
entitywrapper, 
entitywrapper 
)
{
    return false;
},

/**
 * @method FindTargetsInScope
 * @param {int} arg0
 * @param {int} arg1
 * @param {bool} arg2
 * @param {bool} arg3
 * @param {Array} arg4
 */
FindTargetsInScope : function (
int, 
int, 
bool, 
bool, 
array 
)
{
},

/**
 * @method GetEnemyTag
 * @param {String} arg0
 * @return {String}
 */
GetEnemyTag : function (
str 
)
{
    return ;
},

/**
 * @method FindRandTargetByTag
 * @param {String} arg0
 * @return {int}
 */
FindRandTargetByTag : function (
str 
)
{
    return 0;
},

/**
 * @method IsInMyNearRange
 * @param {Genius::EntityWrapper} arg0
 * @param {Genius::EntityWrapper} arg1
 * @return {bool}
 */
IsInMyNearRange : function (
entitywrapper, 
entitywrapper 
)
{
    return false;
},

/**
 * @method AreEntitiesCloseEnough
 * @param {Genius::EntityWrapper} arg0
 * @param {Genius::EntityWrapper} arg1
 * @param {float} arg2
 * @return {bool}
 */
AreEntitiesCloseEnough : function (
entitywrapper, 
entitywrapper, 
float 
)
{
    return false;
},

/**
 * @method IsTagged
 * @param {String} arg0
 * @param {Genius::Entity} arg1
 * @return {bool}
 */
IsTagged : function (
str, 
entity 
)
{
    return false;
},

/**
 * @method FindNearestTarget
 * @param {Genius::Entity} arg0
 * @param {bool} arg1
 * @param {bool} arg2
 * @return {int}
 */
FindNearestTarget : function (
entity, 
bool, 
bool 
)
{
    return 0;
},

};

/**
 * @class SkillManager
 */
SkillManager = {

/**
 * @method ClearSkill
 * @param {int} arg0
 */
ClearSkill : function (
int 
)
{
},

/**
 * @method LoadSkill
 * @param {int} arg0
 * @param {int} arg1
 * @return {bool}
 */
LoadSkill : function (
int, 
int 
)
{
    return false;
},

/**
 * @method UseSkill
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 * @return {bool}
 */
UseSkill : function (
int, 
int, 
int 
)
{
    return false;
},

/**
 * @method SaveSkill
 * @param {int} arg0
 * @return {bool}
 */
SaveSkill : function (
int 
)
{
    return false;
},

/**
 * @method ClearAllSkill
 */
ClearAllSkill : function (
)
{
},

/**
 * @method CanUseSkill
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 * @return {bool}
 */
CanUseSkill : function (
int, 
int, 
int 
)
{
    return false;
},

/**
 * @method GetMe
 * @return {Genius::SkillManager}
 */
GetMe : function (
)
{
    return Genius::SkillManager;
},

/**
 * @method SkillManager
 * @constructor
 */
SkillManager : function (
)
{
},

};

/**
 * @class BuffManager
 */
BuffManager = {

/**
 * @method GetBuffCount
 * @return {int}
 */
GetBuffCount : function (
)
{
    return 0;
},

/**
 * @method RemoveBuff
 * @param {int} arg0
 */
RemoveBuff : function (
int 
)
{
},

/**
 * @method RemoveAllBuff
 */
RemoveAllBuff : function (
)
{
},

/**
 * @method AddBuff
 * @param {int} arg0
 * @param {int} arg1
 * @param {int} arg2
 * @return {bool}
 */
AddBuff : function (
int, 
int, 
int 
)
{
    return false;
},

/**
 * @method GetMe
 * @return {Genius::BuffManager}
 */
GetMe : function (
)
{
    return Genius::BuffManager;
},

/**
 * @method BuffManager
 * @constructor
 */
BuffManager : function (
)
{
},

};

/**
 * @class EntityWrapper
 */
Entity = {

/**
 * @method RemoveTag
 * @param {char} arg0
 */
RemoveTag : function (
char 
)
{
},

/**
 * @method AddComponent
 * @param {char} arg0
 * @return {Genius::IComponent}
 */
AddComponent : function (
char 
)
{
    return Genius::IComponent;
},

/**
 * @method GetID
 * @return {int}
 */
GetID : function (
)
{
    return 0;
},

/**
 * @method OnDestroy
 */
OnDestroy : function (
)
{
},

/**
 * @method AddTag
 * @param {char} arg0
 */
AddTag : function (
char 
)
{
},

/**
 * @method EntityWrapper
 * @constructor
 * @param {Genius::Entity} arg0
 */
EntityWrapper : function (
entity 
)
{
},

};

/**
 * @class WorldWrapper
 */
World = {

/**
 * @method CreateEntity
 * @return {Genius::EntityWrapper}
 */
CreateEntity : function (
)
{
    return Genius::EntityWrapper;
},

/**
 * @method DestroyEntity
 * @param {Genius::EntityWrapper} arg0
 */
DestroyEntity : function (
entitywrapper 
)
{
},

/**
 * @method GetWorld
 * @return {Genius::WorldWrapper}
 */
GetWorld : function (
)
{
    return Genius::WorldWrapper;
},

};
