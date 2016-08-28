
/**
 * DoState action
 * by Locke
 * lololol~
 */


var DoState = bt.Action.extend({

    timeWait:0,
    animComplete:false,
    targetState:null,
    animationName:'',

    ctor:function(state,animName) {
        this.name = "DoState";
        this.animComplete = false;
        this.targetState = state;
        this.animationName = animName;
    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + 10;
        this.animComplete = false;

        var entity = tick.target;
        var locomotor = entity.GetComponent(gn.ComName.Locomotor);
        locomotor.StopMove();
        var followTar = entity.GetBlackboard(gn.BB.CombatTarget);
        locomotor.FaceToEntity(followTar);

        entity.GetStateGraph().gotoState(this.targetState);

    },

    tick:function(tick) {
        var entity = tick.target;

        if(this.animComplete){
            entity.GetStateGraph().gotoState(gn.SG.Idle);
            return bt.SUCCESS;
        }

        if (Game.GetTime() > this.timeWait) {
            entity.GetStateGraph().gotoState(gn.SG.Idle);
            return bt.SUCCESS;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    },

    PushEvent:function(event, data){
        if(event === gn.Event.AnimLoopComplete || event === gn.Event.AnimComplete){
            if(data === this.animationName){
                this.animComplete = true;
            }
        }
    }


});







