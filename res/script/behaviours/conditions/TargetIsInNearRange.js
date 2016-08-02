
/**
 * TargetIsInNearRange ?
 * by Locke
 * lololol~
 */


var TargetIsInNearRange = bt.Condition.extend({

    ctor:function()
    {
        this.name = "TargetIsInNearRange";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combat = entity.GetComponent(ComName.Combat);
        if (combat.GetTarget() != null && false)
        {
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});



