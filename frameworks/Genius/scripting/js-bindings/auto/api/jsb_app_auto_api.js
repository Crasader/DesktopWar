
/**
 * @class GamePlay
 */
GamePlay = {

/**
 * @method SendMonster
 */
SendMonster : function (
)
{
},

/**
 * @method SendHuman
 */
SendHuman : function (
)
{
},

};

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
 * @class EntityCreator
 */
EntityCreator = {

/**
 * @method CreateBullet
 * @param {int} arg0
 * @param {int} arg1
 * @param {float} arg2
 * @param {float} arg3
 * @param {int} arg4
 * @param {float} arg5
 * @param {float} arg6
 * @return {int}
 */
CreateBullet : function (
int, 
int, 
float, 
float, 
int, 
float, 
float 
)
{
    return 0;
},

/**
 * @method CreatePawn
 * @param {int} arg0
 * @param {float} arg1
 * @param {float} arg2
 * @param {int} arg3
 * @return {int}
 */
CreatePawn : function (
int, 
float, 
float, 
int 
)
{
    return 0;
},

/**
 * @method CreateBornPoint
 * @param {float} arg0
 * @param {float} arg1
 * @param {int} arg2
 * @return {int}
 */
CreateBornPoint : function (
float, 
float, 
int 
)
{
    return 0;
},

};

/**
 * @class EntityWrapper
 */
Entity = {

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
 * @method AddComponent
 * @param {char} arg0
 * @return {Genius::Component}
 */
AddComponent : function (
char 
)
{
    return Genius::Component;
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

};
