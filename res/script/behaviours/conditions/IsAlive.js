
/**
 * is agent alive ?
 * by Locke
 * lololol~
 */

var IsAlive = bt.Condition.extend({

    ctor:function()
    {
        this.name = "IsAlive";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var attr = entity.GetComponent(ComName.Attr);
        if (attr.Get(Attr.HP) > 0)
        {
            //print("alive");
            return bt.SUCCESS;
        }
        else
        {
            //print("not alive");
            return bt.FAILURE;
        }
    }

});

