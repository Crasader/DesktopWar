
/**
 * AttackNearSpecial action
 * by Locke
 * lololol~
 */


var AttackNearSpecial = bt.Action.extend({

    timeWait:0,
    animComplete:false,

    ctor:function() {
        this.name = "AttackNearSpecial";
        this.animComplete = false;
    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + 10;
        this.animComplete = false;

        var entity = tick.target;
        var locomotor = entity.GetComponent(gn.ComName.Locomotor);
        locomotor.StopMove();
        var followTar = entity.GetBlackboard(gn.BB.CombatTarget);
        locomotor.FaceToEntity(followTar);

        entity.GetStateGraph().gotoState(gn.SG.AttackNearSpecial);

    },

    tick:function(tick) {
        var entity = tick.target;

        if(this.animComplete){
            return bt.SUCCESS;
        }

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

    },

    PushEvent:function(event, data){
        var animName = data;
        if(event === gn.Event.AnimLoopComplete){
            if(animName === gn.AnimName.Atk2){
                this.animComplete = true;
            }
        }
    }

});







