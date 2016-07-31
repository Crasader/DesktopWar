
/**
 * js层entityNative核心，负责管理js组件
 * Author:Locke
 * Date:2016-7-13
 */



var EntityScript = Class.extend({

    entityNative:null,
    components:null,


    ctor:function ()
    {
        this.components = {}
    },

    SetEntityNative:function(ent)
    {
        this.entityNative = ent
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
            if (com.OnUpdate != null)
                com.OnUpdate();
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




