
/**
 * Combat component
 * by Locke
 * lololol~
 */



var Combat = BaseComponent.extend({

    name:"Combat",
    target:null,

    ctor:function ()
    {
        this.target = null;
    },

    GetTarget:function()
    {
        return this.target;
    },

    OnUpdate:function(timeDelta)
    {

    },

    OnLongUpdate:function(timeDelta)
    {

    },

});
