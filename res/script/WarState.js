
var WarState = GameState.extend({
    
    ctor:function ()
    {
        this._super()
    },
    
    OnEnter:function ()
    {
        print("enter War")
    },
    
    OnUpdate:function ()
    {

    },
    
    OnExit:function ()
    {
        print("exit War")
    },

    ParseResourceList:function(loadMgr)
    {
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "HolyKnight")
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "BigDevil")
    }
    
})