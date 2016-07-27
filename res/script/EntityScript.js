
/**
 * js层entityNative核心，负责管理js组件
 * Author:Locke
 * Date:2016-7-13
 */



var EntityScript = Class.extend({

    entityNative:null,
    components:null,
    curUpdateTime:0,
    curLongUpdateTime:0,


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

    AddComponent:function(com)
    {
        if (null!=com.isComponentClass)
        {
            this.components[com.GetName()] = com;
            com.SetEntity(this);
        }
        return com;
    },

    GetComponent:function(com)
    {
        return this.components[com.GetName()]
    },


    OnUpdate:function(timedelta)
    {
        curUpdateTime = timedelta;
        for(var id in this.components)
        {
            var com = this.components[id];
            com.OnUpdate(timedelta)
        }
    },

    OnLongUpdate:function(timedelta)
    {
        curLongUpdateTime = timedelta;
        for(var id in this.components)
        {
            var com = this.components[id];
            com.OnLongUpdate(timedelta)
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


})




