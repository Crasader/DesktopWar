
/**
 * js层entity核心，负责管理js组件
 * Author:Locke
 * Date:2016-7-13
 */



var EntityScript = Class.extend({

    entity:null,
    components:null,


    ctor:function ()
    {
        this.components = {}
    },

    SetEntity:function(ent)
    {
        this.entity = ent
    },

    LoadComponent:function(name)
    {

    },

    GetComponent:function(name)
    {
        return components[name]
    },

    OnLongUpdate:function(dt)
    {
        for(var com in components)
        {
            if (com.OnLongUpdate != null)
                com.OnLongUpdate(dt)
        }
    },

    OnUpdate:function ()
    {
        for(var com in components)
        {
            if (com.OnUpdate != null)
                com.OnUpdate(dt)
        }
    }


})




