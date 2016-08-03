
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
        var combatTar = entity.GetBlackboard(BB.CombatTarget);
        if (combatTar != null && false)
        {
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});


