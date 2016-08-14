
/**
 * TurnAround action
 * by Locke
 * lololol~
 */


var TurnAround = bt.Action.extend({

    turnCount:0,
    turnWaitTime:0,
    //constants
    minTurnTime:0.8,
    maxTurnTime:1.2,


    ctor:function() {
        this._super();
        this.name = "TurnAround";
    },

    open:function(tick) {
        this.turnCount = Random(3, 5);
        this.turnWaitTime = Game.GetTime() + Random(this.minTurnTime, this.maxTurnTime);
    },

    tick:function(tick) {
        var entity = tick.target;

        if (this.turnCount <= 0) {
            return bt.SUCCESS;
        }
        else if (Game.GetTime() > this.turnWaitTime) {
            this.turnCount--;
            this.turnWaitTime = Game.GetTime() + Random(0.8, 1.2);
            this.TurnFace(entity);
        }

        return bt.RUNNING;
    },

    close:function(tick) {
    },


    TurnFace:function(entity){
        var trans = entity.GetComponent(gn.ComName.Transform);
        var currentDir = trans.GetDir();
        var newDir = gn.FaceDir.Left;
        if(currentDir & gn.FaceDir.Left){
            newDir = gn.FaceDir.Right;
        }else{
            newDir = gn.FaceDir.Left;
        }
        trans.SetDirection(newDir);
        var sg = entity.GetStateGraph();
        PlayPawnAnim(entity,sg.GetAnimPrefixName());
    }

});







