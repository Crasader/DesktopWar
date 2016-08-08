
/**
 * AttackNear action
 * by Locke
 * lololol~
 */


var AttackNear = bt.Action.extend({

    timeWait:0,

    ctor:function() {
        this.name = "AttackNear";

    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + 10;

        var entity = tick.target;
        var locomotor = entity.GetComponent(ComName.Locomotor);
        locomotor.StopMove();
        var followTar = entity.GetBlackboard(BB.CombatTarget);
        locomotor.FaceToEntity(followTar);

        entity.GetStateGraph().gotoState(SG.AttackNear);

        print('open attack near');
    },

    tick:function(tick) {
        var entity = tick.target;
        if (Game.GetTime() > this.timeWait) {
            entity.GetStateGraph().gotoState(SG.Idle);
            return bt.SUCCESS;
        }

        var combatTar = entity.GetBlackboard(BB.CombatTarget);
        if(null == combatTar){
            return bt.FAILURE;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    }

});







