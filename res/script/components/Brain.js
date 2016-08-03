
/**
 * brain component
 * by Locke
 * lololol~
 */



var Brain = BaseComponent.extend({

    name:"Brain",
    btree:null,
    blackboard:null,

    ctor:function (btree)
    {
        this.btree = btree;
        this.blackboard = new bt.Blackboard();
    },

    /*SetBTree:function(_btree)
    {
        this.btree = _btree;
    },*/

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





