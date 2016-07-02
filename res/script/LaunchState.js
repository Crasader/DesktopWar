
var LaunchState = GameState.extend
({
    
    ctor:function ()
    {
        this._super();
    },
    
    OnEnter:function ()
    {
        Log("enter Launch");
    },
    
    OnUpdate:function ()
    {

    },
    
    OnExit:function ()
    {
        Log("exit Launch");
    },

    ParseResourceList:function(loadMgr)
    {
        loadMgr.AddResource(1, "HolyKnight");
        loadMgr.AddResource(1, "BigDevil");
    }

    
});