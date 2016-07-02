

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */

require("res/script/Utils.js");
require("res/script/Class.js");
require("res/script/GameState.js");
require("res/script/LaunchState.js");
require("res/script/LoadingState.js");
require("res/script/WarState.js");


Log("lololol JS bang!");


var Game =
{

    currentState:null,
    lastState:null,
    loadingState:null,
    lanchState:null,
    warState:null,
    
    Init:function ()
    {
        Log("Game Init");
        this.loadingState = new LoadingState();
        this.lanchState = new LaunchState(),
        this.warState = new WarState(),
        this.ChangeState("Launch");
    },

    ChangeState:function(state)
    {
        var newState = null;
        if(state == "Launch")
        {
            newState = this.lanchState;
        }
        else if(state == "War")
        {
            newState = this.warState;
        }
        this.lastState = this.currentState;
        this.currentState = newState;
        if (this.lastState != null)
            this.lastState.OnExit();
        this.currentState.OnEnter();
    },

    OnUpdate:function (timeDelta)
    {
        Log("game onupdate "+timeDelta);
    }



};

Game.Init();















/*cc.game.onStart = function(){
 if(!cc.sys.isNative && document.getElementById("cocosLoading")) //If referenced loading.js, please remove it
 document.body.removeChild(document.getElementById("cocosLoading"));

 cc.view.enableRetina(cc.sys.os === cc.sys.OS_IOS ? true : false);
 cc.view.adjustViewPort(true);
 cc.view.setDesignResolutionSize(960, 640, cc.ResolutionPolicy.SHOW_ALL);
 cc.view.resizeWithBrowserSize(true);
 cc.LoaderScene.preload(g_resources, function () {
 cc.director.runScene(new HelloWorldScene());
 }, this);
 };
 cc.game.run();*/

