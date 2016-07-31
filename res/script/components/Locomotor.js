
/**
 * locomotor component
 * by Locke
 * lololol~
 */



var Locomotor = BaseComponent.extend({

    name:"Locomotor",

    ctor:function ()
    {

    },

    SetBTree:function(_btree)
    {
        this.btree = _btree;
    },

    OnUpdate:function()
    {

    },

    OnLongUpdate:function()
    {

    },

    SetPosition:function(x,y)
    {
        this.entity.GetComponent(ComName.Transform).SetPosition(x,y);
    },

    MoveTo:function(x,y)
    {
        this.entity.GetComponent(ComName.Transform).MoveTo(x,y);
    }

});





