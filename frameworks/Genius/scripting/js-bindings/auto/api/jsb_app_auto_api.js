
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
 * @class Logger
 */
Logger = {

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
 * @method UpdateLoading
 */
UpdateLoading : function (
)
{
},

/**
 * @method AddResource
 * @param {int} arg0
 * @param {String} arg1
 */
AddResource : function (
int, 
str 
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
 * @method GenerateUnLoadList
 */
GenerateUnLoadList : function (
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
 * @class IDataManager
 */
IDataManager = {

/**
 * @method GetSize
 * @return {int}
 */
GetSize : function (
)
{
    return 0;
},

/**
 * @method Destroy
 */
Destroy : function (
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
 * @method GetName
 * @return {String}
 */
GetName : function (
)
{
    return ;
},

};

/**
 * @class AnimInfo
 */
AnimInfo = {

/**
 * @method FilePath
 * @return {String}
 */
FilePath : function (
)
{
    return ;
},

};

/**
 * @class AnimDataMgr
 */
AnimDataMgr = {

/**
 * @method GetName
 * @return {String}
 */
GetName : function (
)
{
    return ;
},

/**
 * @method FindAnimInfo
 * @param {String} arg0
 * @return {Genius::AnimInfo}
 */
FindAnimInfo : function (
str 
)
{
    return Genius::AnimInfo;
},

/**
 * @method GetSize
 * @return {int}
 */
GetSize : function (
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
 * @method Destroy
 */
Destroy : function (
)
{
},

/**
 * @method AnimDataMgr
 * @constructor
 */
AnimDataMgr : function (
)
{
},

};
