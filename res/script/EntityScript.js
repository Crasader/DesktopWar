
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
    }


});




