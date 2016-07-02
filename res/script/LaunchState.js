
var LaunchState = GameState.extend({
    
    ctor:function () {
        this._super();
    },
    
    OnEnter:function () {
        this._super();
        Logger.print("enter");
    },
    
    OnUpdate:function () {
        this._super();
        Logger.print("upd");
    },
    
    OnExit:function () {
        this._super();
        Logger.print("exit");
    }
    
});