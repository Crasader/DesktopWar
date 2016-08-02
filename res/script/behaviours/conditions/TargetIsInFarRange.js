
/**
 * TargetIsInFarRange ?
 * by Locke
 * lololol~
 */


var TargetIsInFarRange = bt.Condition.extend({

    ctor:function()
    {
        this.name = "TargetIsInFarRange";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combat = entity.GetComponent(ComName.Combat);
        if (combat.GetTarget() != null && false)
        {
            return b3.SUCCESS;
        }
        else
        {
            return b3.FAILURE;
        }
    }

});


