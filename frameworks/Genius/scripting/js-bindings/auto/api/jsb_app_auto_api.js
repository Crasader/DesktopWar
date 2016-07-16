
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
 * @method SetDirection
 * @param {int} arg0
 */
SetDirection : function (
int 
)
{
},

/**
 * @method create_ComTransform
 * @return {Genius::IComponent}
 */
create_ComTransform : function (
)
{
    return Genius::IComponent;
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
 * @method create_ComBoxCollider
 * @return {Genius::IComponent}
 */
create_ComBoxCollider : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class ComColliderHandler
 */
ComColliderHandler = {

/**
 * @method Create
 * @param {function} arg0
 * @param {function} arg1
 */
Create : function (
func, 
func 
)
{
},

/**
 * @method create_ComColliderHandler
 * @return {Genius::IComponent}
 */
create_ComColliderHandler : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class ComAnimation
 */
ComAnimation = {

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
 * @method create_ComAnimation
 * @return {Genius::IComponent}
 */
create_ComAnimation : function (
)
{
    return Genius::IComponent;
},

/**
 * @method ComAnimation
 * @constructor
 */
ComAnimation : function (
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

/**
 * @method create_ComParticle
 * @return {Genius::IComponent}
 */
create_ComParticle : function (
)
{
    return Genius::IComponent;
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

/**
 * @method create_ComBezierMovement
 * @return {Genius::IComponent}
 */
create_ComBezierMovement : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class ComPawnAgent
 */
ComPawnAgent = {

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

/**
 * @method create_ComPawnAgent
 * @return {Genius::IComponent}
 */
create_ComPawnAgent : function (
)
{
    return Genius::IComponent;
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
 * @method GetWidth
 * @return {float}
 */
GetWidth : function (
)
{
    return 0;
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

/**
 * @method create_ComPawnDebugDraw
 * @return {Genius::IComponent}
 */
create_ComPawnDebugDraw : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class ComPawnFight
 */
ComPawnFight = {

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
 * @method create_ComPawnFight
 * @return {Genius::IComponent}
 */
create_ComPawnFight : function (
)
{
    return Genius::IComponent;
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
 * @method create_ComPawnNavigation
 * @return {Genius::IComponent}
 */
create_ComPawnNavigation : function (
)
{
    return Genius::IComponent;
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
 * @method create_ComPawnBevtree
 * @return {Genius::IComponent}
 */
create_ComPawnBevtree : function (
)
{
    return Genius::IComponent;
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
 * @method create_ComBulletAnimBase
 * @return {Genius::IComponent}
 */
create_ComBulletAnimBase : function (
)
{
    return Genius::IComponent;
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

/**
 * @method create_ComBulletAnimArrow
 * @return {Genius::IComponent}
 */
create_ComBulletAnimArrow : function (
)
{
    return Genius::IComponent;
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

/**
 * @method create_ComBulletAnimBomb
 * @return {Genius::IComponent}
 */
create_ComBulletAnimBomb : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class ComBulletDamageNone
 */
ComBulletDamageNone = {

/**
 * @method create_ComBulletDamageNone
 * @return {Genius::IComponent}
 */
create_ComBulletDamageNone : function (
)
{
    return Genius::IComponent;
},

/**
 * @method ComBulletDamageNone
 * @constructor
 */
ComBulletDamageNone : function (
)
{
},

};

/**
 * @class ComBulletDamageScope
 */
ComBulletDamageScope = {

/**
 * @method create_ComBulletDamageScope
 * @return {Genius::IComponent}
 */
create_ComBulletDamageScope : function (
)
{
    return Genius::IComponent;
},

/**
 * @method ComBulletDamageScope
 * @constructor
 */
ComBulletDamageScope : function (
)
{
},

};

/**
 * @class ComBulletDamageSingle
 */
ComBulletDamageSingle = {

/**
 * @method create_ComBulletDamageSingle
 * @return {Genius::IComponent}
 */
create_ComBulletDamageSingle : function (
)
{
    return Genius::IComponent;
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
 * @method create_ComBulletDebugDraw
 * @return {Genius::IComponent}
 */
create_ComBulletDebugDraw : function (
)
{
    return Genius::IComponent;
},

/**
 * @method ComBulletDebugDraw
 * @constructor
 */
ComBulletDebugDraw : function (
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

/**
 * @method create_ComBulletAnimEgg
 * @return {Genius::IComponent}
 */
create_ComBulletAnimEgg : function (
)
{
    return Genius::IComponent;
},

};

/**
 * @class EntityWrapper
 */
Entity = {

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
