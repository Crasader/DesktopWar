

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */

// name space : genius
var gn = gn || {};


require("res/script/Class.js");
require("res/script/Defines.js");
require("res/script/mainfuncs.js");
require("res/script/GameState.js");
require("res/script/BrainMgr.js");

require("res/script/ComponentName.js");
require("res/script/EntityScript.js");

require("res/script/prefabs/_prefabs_.js");
require("res/script/configs/_cfg_.js");
require("res/script/behaviours/_bev_.js");
require("res/script/components/_com_.js");
require("res/script/states/_state_.js");


gn.SkillMgr = null;
gn.BuffMgr = null;




var Game =
{
    currentState:null,
    lastState:null,
    loadingState:null,
    lanchState:null,
    warState:null,

    updateTime:0.1,
    longUpdateTime:0.1,

    entityList:{},
    updatingEntities:{},
    deleteEntityList:{},


    Start:function() {

        //print("Game Init")

        gn.SkillMgr = SkillManager.GetMe();
        gn.BuffMgr = BuffManager.GetMe();

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

        BrainMgr.OnLongUpdate();
    },

    OnArmatureFrameEvent:function(entityID, eventName){
        var entity = this.entityList[entityID];
        if(entity == null){
            print('Game.OnFrameEvent: cannot find entity.id:'+entityID);
        }else {
            HandleArmatureFrameEvent(entity,eventName);
        }
    },

    OnArmatureMovementEvent:function(entityID, movement, animName){
        var entity = this.entityList[entityID];
        if(entity == null){
            print('Game.OnMovementEvent: cannot find entity.id:'+entityID);
        }else {
            HandleArmatureMovementEvent(entity,movement,animName);
        }
    },

    OnModifyEntityAttr:function(entityID, calType, attrType, value, atkType){
        var entity = this.entityList[entityID];
        if(entity == null){
            print('Game.OnModifyEntityAttr: cannot find entity.id:'+entityID);
        }else {
            ModifyEntityAttr(entity,calType,attrType,value,atkType);
        }
    },

    OnPushEvent:function(entityID, event){
        var entity = this.entityList[entityID];
        if(entity == null){
            print('Game.OnPushEvent: cannot find entity.id:'+entityID);
        }else {
            entity.PushEvent(event);
        }
    },

    // get time in seconds since game starts.
    GetTime:function() {
        return TimeSystem.TimeSinceStart();
    },


    CreateEntity:function() {
        var entNative = GetWorld().CreateEntity();
        var ent = new EntityScript();
        ent.SetEntityNative(entNative);
        var guid = ent.GetID();
        this.entityList[guid] = ent;
        return ent;
    },


    DestroyEntity:function(entity) {
        if (null == entity) {
            print("Game.DestroyEntity : entity is null.");
            return;
        }

        delete this.entityList[entity.GetID()];
        delete this.updatingEntities[entity.GetID()];

        this.deleteEntityList[entity.GetID()] = entity;

    },

    _DoDestroyEntity:function(entity){

        // to do : other handlers
        BrainMgr.RemoveBrain(entity);

        entity.OnDestroy();

        GetWorld().DestroyEntity(entity.GetEntityNative());

        //print("Game._DoDestroyEntity one");
    },


    UpdateEntities:function(timeDelta) {

        for(var id in this.deleteEntityList){
            this._DoDestroyEntity(this.deleteEntityList[id]);
            delete this.deleteEntityList[id];
        }

        for (var id in this.updatingEntities) {
            var ent = this.updatingEntities[id];
            ent.OnUpdate(timeDelta);
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
        delete this.updatingEntities[entity.GetID()];
    }



};




