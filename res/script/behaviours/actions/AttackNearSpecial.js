
/**
 * AttackNearSpecial action
 * by Locke
 * lololol~
 */


var AttackNearSpecial = bt.Action.extend({

    timeWait:0,

    ctor:function() {
        this.name = "AttackNearSpecial";

    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + 10;

        var entity = tick.target;
        var locomotor = entity.GetComponent(gn.ComName.Locomotor);
        locomotor.StopMove();
        var followTar = entity.GetBlackboard(gn.BB.CombatTarget);
        locomotor.FaceToEntity(followTar);

        entity.GetStateGraph().gotoState(gn.SG.AttackNearSpecial);

    },

    tick:function(tick) {
        var entity = tick.target;
        if (Game.GetTime() > this.timeWait) {
            entity.GetStateGraph().gotoState(gn.SG.Idle);
            return bt.SUCCESS;
        }

        var combatTar = entity.GetBlackboard(gn.BB.CombatTarget);
        if(null == combatTar){
            return bt.FAILURE;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    }

});







