
var WarState = GameState.extend({
    
    ctor:function ()
    {
        this._super()
    },
    
    OnEnter:function ()
    {
        Log("enter War")
    },
    
    OnUpdate:function ()
    {

    },
    
    OnExit:function ()
    {
        Log("exit War")
    },

    ParseResourceList:function(loadMgr)
    {
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "HolyKnight")
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "BigDevil")
    }
    
})