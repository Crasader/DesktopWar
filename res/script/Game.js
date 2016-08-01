

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */


require("res/script/Class.js");
require("res/script/Defines.js");
require("res/script/mainfuncs.js");
require("res/script/GameState.js");

require("res/script/ComponentName.js");
require("res/script/prefabs/Soldier.js");
require("res/script/prefabs/Monster.js");
require("res/script/prefabs/Bullet.js");
require("res/script/EntityScript.js");

require("res/script/configs/_cfg_.js");
require("res/script/behaviours/_bev_.js");
require("res/script/components/_com_.js");







var Game =
{
    currentState:null,
    lastState:null,
    loadingState:null,
    lanchState:null,
    warState:null,

    updateTime:0.1,
    longUpdateTime:0.1,


    Start:function ()
    {
        //print("Game Init")
        this.loadingState = new LoadingState();
        this.lanchState = new LaunchState();
        this.warState = new WarState();
        this.ChangeState(this.lanchState)
    },


    ChangeState:function(newState)
    {
        if(newState != this.lanchState && newState != this.warState)
        {
            print("invalid state");
            return;
        }
        if(newState == this.currentState)
        {
            print("cannot enter the same state");
            return;
        }

        this.lastState = this.currentState;
        this.currentState = this.loadingState;
        this.loadingState.SetTwoStatus(this.lastState, newState)
    },


    OnUpdate:function (timeDelta)
    {
        this.updateTime = timeDelta;

        if(this.currentState != null)
        {
            if (this.currentState != this.lastState)
            {
                if (this.lastState != null)
                    this.lastState.OnExit();
                this.currentState.OnEnter();
                this.lastState = this.currentState
            }
            this.currentState.OnUpdate(timeDelta)
        }

        //entity
        UpdateEntities();

    },


    OnLongUpdate:function(timeDelta)
    {
        this.longUpdateTime = timeDelta;
        //entity
        LongUpdateEntities();
    },

    GetTime:function()
    {
        return TimeSystem.TimeSinceStart();
    }

};




