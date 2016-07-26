
// brain component

var Brain = Component.extend({

    name:"Brain",
    btree:null,
    blackboard:new b3.Blackboard(),

    //
    SetBTree:function(_btree)
    {
        this.btree = _btree;
    },

    OnLongUpdate:function()
    {
        if (null != this.btree)
        {
            this.btree.tick(this.entity, blackboard);
        }
    },

});





