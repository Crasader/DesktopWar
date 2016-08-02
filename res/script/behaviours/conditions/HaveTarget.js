
/**
 * have a target now ?
 * by Locke
 * lololol~
 */


var HaveTarget = bt.Condition.extend({

    ctor:function()
    {
        this.name = "HaveTarget";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combat = entity.GetComponent(ComName.Combat);
        if (combat != null && combat.GetTarget() != null)
        {
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});

