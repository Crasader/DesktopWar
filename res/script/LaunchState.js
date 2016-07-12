
var LaunchState = GameState.extend
({
    
    ctor:function ()
    {
        this._super()
    },
    
    OnEnter:function ()
    {
        //EntityCreator.CreatePawn(2012, 700, 133, 2)
        //EntityCreator.CreatePawn(2009, 300, 133, 2)
        EntityCreator.CreatePawn(2011, 300, 133, 2)
		EntityCreator.CreatePawn(2011, 280, 120, 2)
		EntityCreator.CreatePawn(2011, 260, 140, 2)
        EntityCreator.CreatePawn(1007, 500, 133, 1)
		EntityCreator.CreatePawn(1007, 520, 120, 1)
		EntityCreator.CreatePawn(1007, 540, 140, 1)
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
        loadMgr.AddRole(2012)
        loadMgr.AddRole(2011)
        loadMgr.AddRole(2009)
        loadMgr.AddRole(1007)

        loadMgr.AddAnim(3001)
        loadMgr.AddAnim(3002)
        loadMgr.AddAnim(3003)
    }

    
})