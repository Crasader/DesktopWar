
var LaunchState = GameState.extend
({
    
    ctor:function ()
    {
        this._super()
    },
    
    OnEnter:function ()
    {
        print("enter Launch")
    },
    
    OnUpdate:function ()
    {

    },
    
    OnExit:function ()
    {
        print("exit Launch")
    },

    ParseResourceList:function(loadMgr)
    {
        loadMgr.AddResource(1, "HolyKnight")
        loadMgr.AddResource(1, "BigDevil")
    }

    
})