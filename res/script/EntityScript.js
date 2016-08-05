
/**
 * js层entityNative核心，负责管理js组件
 * Author:Locke
 * Date:2016-7-13
 */

// Blackboard中的Key
var BB = {};
BB.FollowTarget = "FollowTarget";
BB.CombatTarget = "CombatTarget";


// Entity
var EntityScript = Class.extend({

    entityNative:null,
    components:null,
    blackboard:{},
    stateGraph:null,
    eventHandlers:{},


    ctor:function ()
    {
        this.components = {}
    },

    SetEntityNative:function(ent)
    {
        this.entityNative = ent
    },

    GetEntityNative:function()
    {
        return this.entityNative;
    },

    GetBlackboard:function(name)
    {
        return this.blackboard[name];
    },

    SetBlackboard:function(name, value)
    {
        this.blackboard[name] = value;
    },

    SetStateGraph:function(sg)
    {
        this.stateGraph = sg;
    },

    GetStateGraph:function()
    {
        return this.stateGraph;
    },

    AddTag:function(tag)
    {
        this.entityNative.AddTag(tag);
    },

    // com: 加js组件则com是组件实例，加native组件则com是组件名.
    AddComponent:function(com)
    {
        if (com instanceof BaseComponent)
        {
            this.components[com.GetName()] = com;
            com.SetEntity(this);
            if (com.OnAwake != null)
                com.OnAwake();
            return com;
        }
        else
        {
            var comNative = this.entityNative.AddComponent(com);
            if (null != comNative)
            {
                this.components[com] = comNative;
            }
            else
            {
                print("EntityScript.AddComponent:com is invalid");
            }
            return comNative;
        }
    },

    GetComponent:function(name)
    {
        return this.components[name]
    },


    OnUpdate:function()
    {
        for(var id in this.components)
        {
            var com = this.components[id];
            if (com instanceof BaseComponent)
            {
                if (com.GetIsFirstUpdate())
                {
                    com.SetIsFirstUpdate(false);
                    com.OnStart();
                }
                if (com.OnUpdate != null)
                    com.OnUpdate();
            }
        }
    },

    OnLongUpdate:function()
    {
        for(var id in this.components)
        {
            var com = this.components[id];
            if (com.OnLongUpdate != null)
                com.OnLongUpdate();
        }
    },

    OnDestroy:function()
    {
        for(var id in this.components)
        {
            var com = this.components[id];
            com.OnDestroy()
        }
    },

    //event
    ListenForEvent:function(event, handler)
    {
        if(typeof(event)!='string')
        {
            print('EntityScript.ListenForEvent: event is not a string.');
            return;
        }
        if(typeof(handler)!='function')
        {
            print('EntityScript.ListenForEvent: handler is not a function.');
            return;
        }
        if(this.eventHandlers[event] == null)
            this.eventHandlers[event] = Array();
        this.eventHandlers[event].push(handler);
    },

    PushEvent:function(event)
    {
        var handlers = this.eventHandlers[event];
        if (handlers != null)
        {
            for(var id in handlers)
            {
                handlers[id](this);
            }
        }

        // sg
        if (this.stateGraph != null)
        {
            this.stateGraph.PushEvent(event);
        }
    },


});




