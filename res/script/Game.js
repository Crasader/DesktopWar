

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */


require("res/script/Class.js");
require("res/script/Defines.js");
require("res/script/mainfuncs.js");
require("res/script/GameState.js");
require("res/script/BrainMgr.js");

require("res/script/ComponentName.js");
require("res/script/prefabs/Soldier.js");
require("res/script/prefabs/Monster.js");
require("res/script/prefabs/Bullet.js");
require("res/script/EntityScript.js");

require("res/script/configs/_cfg_.js");
require("res/script/behaviours/_bev_.js");
require("res/script/components/_com_.js");
require("res/script/states/_state_.js");







var Game =
{
    currentState:null,
    lastState:null,
    loadingState:null,
    lanchState:null,
    warState:null,

    updateTime:0.1,
    longUpdateTime:0.1,

    entityList:[],
    updatingEntities:[],


    Start:function() {
        //print("Game Init")
        this.loadingState = new LoadingState();
        this.lanchState = new LaunchState();
        this.warState = new WarState();
        this.ChangeState(this.lanchState)
    },


    ChangeState:function(newState) {
        if (newState != this.lanchState && newState != this.warState) {
            print("invalid state");
            return;
        }
        if (newState == this.currentState) {
            print("cannot enter the same state");
            return;
        }

        this.lastState = this.currentState;
        this.currentState = this.loadingState;
        this.loadingState.SetTwoStatus(this.lastState, newState)
    },


    OnUpdate:function(timeDelta) {
        this.updateTime = timeDelta;

        if (this.currentState != null) {
            if (this.currentState != this.lastState) {
                if (this.lastState != null)
                    this.lastState.OnExit();
                this.currentState.OnEnter();
                this.lastState = this.currentState
            }
            this.currentState.OnUpdate(timeDelta)
        }

        BrainMgr.OnUpdate();

        //entity
        this.UpdateEntities();
    },


    OnLongUpdate:function(timeDelta) {
        this.longUpdateTime = timeDelta;
        //entity
        this.LongUpdateEntities();
    },

    // get time in seconds since game starts.
    GetTime:function() {
        return TimeSystem.TimeSinceStart();
    },


    CreateEntity:function() {
        var entNative = GetWorld().CreateEntity();
        var ent = new EntityScript();
        ent.SetEntityNative(entNative);
        var guid = entNative.GetID();
        this.entityList[guid] = ent;

        return ent;
    },


    DestroyEntity:function(entity) {
        if (null == entity) {
            print("Game.DestroyEntity : entity is null.");
            return;
        }

        entity.OnDestroy();
        // to do : other handlers

        GetWorld().DestroyEntity(entity.GetEntityNative())

        for (var id in this.entityList) {
            if (this.entityList[id] == entity) {
                this.entityList.splice(id, 1);
                break;
            }
        }
        for (var id in this.updatingEntities) {
            if (this.updatingEntities[id] == entity) {
                this.updatingEntities.splice(id, 1);
                break;
            }
        }
        print("Game.DestroyEntity done.");
    },


    UpdateEntities:function(timeDelta) {
        for (var id in this.updatingEntities) {
            var ent = this.updatingEntities[id];
            ent.OnUpdate(timeDelta);
        }

    },


    LongUpdateEntities:function(timeDelta) {
        for (var id in this.updatingEntities) {
            var ent = this.updatingEntities[id];
            ent.OnLongUpdate(timeDelta);
        }
    },

    AddUpdatingEntity:function(entity){
        if(!entity instanceof EntityScript){
            print('Game.AddUpdatingEntity: entity is not EntityScript.')
            return;
        }
        this.updatingEntities[entity.GetID()] = entity;
    },

    RemoveUpdatingEntity:function(entity){
        if(!entity instanceof EntityScript){
            print('Game.RemoveUpdatingEntity: entity is not EntityScript.')
            return;
        }
        this.updatingEntities.splice(entity.GetID(), 1);
    }



};




