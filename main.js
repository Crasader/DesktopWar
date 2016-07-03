

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */


require("res/script/Utils.js")
require("res/script/Class.js")
require("res/script/Configs.js")
require("res/script/GameState.js")
require("res/script/LaunchState.js")
require("res/script/LoadingState.js")
require("res/script/WarState.js")


Log(Config.anim["Tkdo"].filePath)
//Log("lololol JS bang!")


var Game =
{
    currentState:null,
    lastState:null,
    loadingState:null,
    lanchState:null,
    warState:null,



    Init:function ()
    {
        //Log("Game Init")
        this.loadingState = new LoadingState()
        this.lanchState = new LaunchState()
        this.warState = new WarState()
        this.ChangeState(this.lanchState)
    },


    ChangeState:function(newState)
    {
        if(newState != this.lanchState && newState != this.warState)
        {
            Log("invalid state")
            return
        }
        if(newState == this.currentState)
        {
            Log("cannot enter the same state")
            return
        }

        this.lastState = this.currentState
        this.currentState = this.loadingState
        this.loadingState.SetTwoStatus(this.lastState, newState)
    },


    OnUpdate:function (timeDelta)
    {
        //Log("game onupdate "+timeDelta)
        if(this.currentState != null)
        {
            if (this.currentState != this.lastState)
            {
                if (this.lastState != null)
                    this.lastState.OnExit()
                this.currentState.OnEnter()
                this.lastState = this.currentState
            }
            this.currentState.OnUpdate(timeDelta)
        }

    }



}

Game.Init()

















/*cc.game.onStart = function(){
 if(!cc.sys.isNative && document.getElementById("cocosLoading")) //If referenced loading.js, please remove it
 document.body.removeChild(document.getElementById("cocosLoading"))

 cc.view.enableRetina(cc.sys.os === cc.sys.OS_IOS ? true : false)
 cc.view.adjustViewPort(true)
 cc.view.setDesignResolutionSize(960, 640, cc.ResolutionPolicy.SHOW_ALL)
 cc.view.resizeWithBrowserSize(true)
 cc.LoaderScene.preload(g_resources, function () {
 cc.director.runScene(new HelloWorldScene())
 }, this)
 }
 cc.game.run()*/

