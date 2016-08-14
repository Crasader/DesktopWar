
/**
 * Skill1 action
 * by Locke
 * lololol~
 */


var Skill1 = bt.Action.extend({

    timeWait:0,

    ctor:function() {
        this.name = "Skill1";

    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + 5;

        var entity = tick.target;
        var locomotor = entity.GetComponent(gn.ComName.Locomotor);
        locomotor.StopMove();

        entity.GetStateGraph().gotoState(gn.SG.Skill1);

        //print('open skill1');
    },

    tick:function(tick) {
        var entity = tick.target;
        if (Game.GetTime() > this.timeWait) {
            entity.GetStateGraph().gotoState(gn.SG.Idle);
            return bt.SUCCESS;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    }

});







