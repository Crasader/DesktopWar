
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

/**
 * @method OnAwake
 */
OnAwake : function (
)
{
},

};

/**
 * @class ComTransform
 */
ComTransform = {

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
 * @method SetDirection
 * @param {int} arg0
 */
SetDirection : function (
int 
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
 * @method OnAwake
 */
OnAwake : function (
)
{
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
 * @method OnAwake
 */
OnAwake : function (
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
 * @method OnAwake
 */
OnAwake : function (
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

/**
 * @method GetBlackboard
 * @return {Genius::PawnBlackboard}
 */
GetBlackboard : function (
)
{
    return Genius::PawnBlackboard;
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
 * @method HaveThisAnimation
 * @param {String} arg0
 * @return {bool}
 */
HaveThisAnimation : function (
str 
)
{
    return false;
},

/**
 * @method HandleAction
 * @param {Genius::PawnAction} arg0
 */
HandleAction : function (
pawnaction 
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
 * @method OnAwake
 */
OnAwake : function (
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
 * @method Create
 */
Create : function (
)
{
},

/**
 * @method Clear
 */
Clear : function (
)
{
},

};

/**
 * @class ComPawnFight
 */
ComPawnFight = {

/**
 * @method OnAwake
 */
OnAwake : function (
)
{
},

/**
 * @method ComPawnFight
 * @constructor
 */
ComPawnFight : function (
)
{
},

};

/**
 * @class ComPawnNavigation
 */
ComPawnNavigation = {

/**
 * @method MoveTo
 * @param {float} arg0
 * @param {float} arg1
 */
MoveTo : function (
float, 
float 
)
{
},

/**
 * @method ComPawnNavigation
 * @constructor
 */
ComPawnNavigation : function (
)
{
},

};

/**
 * @class ComPawnBevtree
 */
ComPawnBevtree = {

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
 * @method ComPawnBevtree
 * @constructor
 */
ComPawnBevtree : function (
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

/**
 * @method SetTargetID
 * @param {int} arg0
 */
SetTargetID : function (
int 
)
{
},

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
 * @method OnAwake
 */
OnAwake : function (
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

/**
 * @class PawnBlackboard
 */
PawnBlackboard = {

/**
 * @method AddAction
 * @param {Genius::PawnAction} arg0
 */
AddAction : function (
pawnaction 
)
{
},

/**
 * @method SetTargetX
 * @param {float} arg0
 */
SetTargetX : function (
float 
)
{
},

/**
 * @method SetTargetType
 * @param {int} arg0
 */
SetTargetType : function (
int 
)
{
},

/**
 * @method SetAttr
 * @param {int} arg0
 * @param {int} arg1
 */
SetAttr : function (
int, 
int 
)
{
},

/**
 * @method ModAttr
 * @param {int} arg0
 * @param {int} arg1
 */
ModAttr : function (
int, 
int 
)
{
},

/**
 * @method FinishAction
 * @param {Genius::PawnAction} arg0
 */
FinishAction : function (
pawnaction 
)
{
},

/**
 * @method AddActionHandler
 * @param {Genius::ActionHandler} arg0
 */
AddActionHandler : function (
actionhandler 
)
{
},

/**
 * @method Update
 */
Update : function (
)
{
},

/**
 * @method GetAttr
 * @param {int} arg0
 * @return {int}
 */
GetAttr : function (
int 
)
{
    return 0;
},

/**
 * @method SetTargetY
 * @param {float} arg0
 */
SetTargetY : function (
float 
)
{
},

/**
 * @method SetTargetID
 * @param {int} arg0
 */
SetTargetID : function (
int 
)
{
},

/**
 * @method RemoveActionHandler
 * @param {Genius::ActionHandler} arg0
 */
RemoveActionHandler : function (
actionhandler 
)
{
},

/**
 * @method PawnBlackboard
 * @constructor
 * @param {Genius::ComPawnAgent} arg0
 */
PawnBlackboard : function (
compawnagent 
)
{
},

};
