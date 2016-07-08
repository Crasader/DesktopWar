
var LaunchState = GameState.extend
({
    
    ctor:function ()
    {
        this._super()
    },
    
    OnEnter:function ()
    {
        //EntityCreator.CreatePawn(2012, 300, 133, 2)
        EntityCreator.CreatePawn(1007, 500, 133, 1)
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