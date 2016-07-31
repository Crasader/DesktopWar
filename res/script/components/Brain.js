
/**
 * brain component
 * by Locke
 * lololol~
 */



var Brain = BaseComponent.extend({

    name:"Brain",
    btree:null,
    blackboard:null,

    ctor:function ()
    {
        this.btree = null;
        this.blackboard = new b3.Blackboard();
    },

    SetBTree:function(_btree)
    {
        this.btree = _btree;
    },

    OnUpdate:function()
    {
        if (null != this.btree)
        {
            this.btree.tick(this.entity, this.blackboard);
        }
    },

    OnLongUpdate:function()
    {

    },

});





