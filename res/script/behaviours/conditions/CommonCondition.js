
/**
 * common entity conditions
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
        var attr = entity.GetComponent(gn.ComName.Attr);
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


var HaveTarget = bt.Condition.extend({

    ctor:function()
    {
        this.name = "HaveTarget";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combatTar = entity.GetBlackboard(gn.BB.CombatTarget);
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


var TargetIsInNearRange = bt.Condition.extend({

    ctor:function()
    {
        this.name = "TargetIsInNearRange";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combatTar = entity.GetBlackboard(gn.BB.CombatTarget);
        if (combatTar != null && EntityUtility.IsInMyNearRange(entity.GetEntityNative(),combatTar.GetEntityNative()))
        {
            //print('TargetIsInNearRange');
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});


var TargetIsInFarRange = bt.Condition.extend({

    ctor:function()
    {
        this.name = "TargetIsInFarRange";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combatTar = entity.GetBlackboard(gn.BB.CombatTarget);
        if (combatTar != null && EntityUtility.IsInMyFarRange(entity.GetEntityNative(),combatTar.GetEntityNative()))
        {
            //print('TargetIsInFarRange');
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});


var TargetIsInViewSight = bt.Condition.extend({

    ctor:function()
    {
        this.name = "TargetIsInViewSight";
    },

    tick:function(tick)
    {
        var entity = tick.target;
        var combatTar = entity.GetBlackboard(gn.BB.CombatTarget);
        if (combatTar != null && EntityUtility.IsInMyViewSight(entity.GetEntityNative(),combatTar.GetEntityNative()))
        {
            //print('TargetIsInViewSight');
            return bt.SUCCESS;
        }
        else
        {
            return bt.FAILURE;
        }
    }

});



