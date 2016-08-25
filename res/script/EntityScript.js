
/**
 * js层entityNative核心，负责管理js组件
 * Author:Locke
 * Date:2016-7-13
 */



// Entity
var EntityScript = Class.extend({

    entityNative:null,
    components:null,
    blackboard:null,
    stateGraph:null,
    brain:null,
    eventHandlers:null,
    updatingComponents:null,


    ctor:function () {
        this.blackboard = {};
        this.components = {};
        this.eventHandlers = {};
        this.updatingComponents = {};
    },

    GetID:function(){
        return this.entityNative.GetID();
    },

    SetEntityNative:function(ent) {
        this.entityNative = ent
    },

    GetEntityNative:function() {
        return this.entityNative;
    },

    GetBlackboard:function(name) {
        return this.blackboard[name];
    },

    SetBlackboard:function(name, value) {
        this.blackboard[name] = value;
    },

    SetStateGraph:function(sg) {
        this.stateGraph = sg;
    },

    GetStateGraph:function() {
        return this.stateGraph;
    },

    SetBrain:function(brain){
        this.brain = brain;
    },

    AddTag:function(tag) {
        this.entityNative.AddTag(tag);
    },

    // com: 加js组件则com是组件实例，加native组件则com是组件名.
    AddComponent:function(com) {
        if (com instanceof BaseComponent) {
            this.components[com.GetName()] = com;
            com.SetEntity(this);
            if (com.OnAwake != null)
                com.OnAwake();
            return com;
        }
        else {
            var comNative = this.entityNative.AddComponent(com);
            if (null != comNative) {
                this.components[com] = comNative;
            }
            else {
                print("EntityScript.AddComponent:com is invalid");
            }
            return comNative;
        }
    },

    GetComponent:function(name) {
        return this.components[name];
    },

    OnAwake:function(){
        for (var id in this.components) {
            var com = this.components[id];
            if (com instanceof BaseComponent) {
                if (com.GetIsFirstUpdate()) {
                    com.SetIsFirstUpdate(false);
                    com.OnStart();
                }
            }
        }

        //start sg
        if(this.stateGraph!=null){
            this.stateGraph.Start();
        }

    },


    OnUpdate:function() {
        for (var id in this.updatingComponents) {
            var com = this.updatingComponents[id];
            if (com instanceof BaseComponent) {
                if (com.OnUpdate != null)
                    com.OnUpdate();
            }
        }
    },

    OnDestroy:function() {
        for (var id in this.components) {
            var com = this.components[id];
            com.OnDestroy();
            com = undefined;
        }
    },

    //event
    ListenForEvent:function(event, handler) {
        if (typeof(event) != 'string') {
            print('EntityScript.ListenForEvent: event is not a string.');
            return;
        }
        if (typeof(handler) != 'function') {
            print('EntityScript.ListenForEvent: handler is not a function.');
            return;
        }
        if (this.eventHandlers[event] == null)
            this.eventHandlers[event] = Array();
        this.eventHandlers[event].push(handler);
    },

    PushEvent:function(event,data) {
        var handlers = this.eventHandlers[event];
        if (handlers != null) {
            for (var id in handlers) {
                handlers[id](this,data);
            }
        }

        // brain
        if(this.brain != null){
            this.brain.PushEvent(event,data);
        }

        // sg
        if(this.stateGraph != null) {
            this.stateGraph.PushEvent(event,data);
        }
    },

    StartUpdateComponent:function(com) {
        if(!com instanceof BaseComponent){
            print('com isnot BaseComponent');
            return;
        }
        this.updatingComponents[com.GetName()] = com;
        Game.AddUpdatingEntity(this);
    },

    StopUpdateComponent:function(com) {
        if(!com instanceof BaseComponent){
            print('com is not BaseComponent');
            return;
        }
        this.updatingComponents[com.GetName()] = undefined;
        if(this.updatingComponents.length==0){
            Game.RemoveUpdatingEntity(this);
        }
    }

});




