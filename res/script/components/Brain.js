
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

    GetBTree:function()
    {
        return this.btree;
    },

    OnUpdate:function(timeDelta)
    {
        if (null != this.btree)
        {
            var obj =
            {
                tree:this.btree,
                entity:this.entity,
                whatelse:null
            };
            this.btree.tick(obj, blackboard);
        }
    },

    OnLongUpdate:function(timeDelta)
    {

    },

});





