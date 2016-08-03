
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



