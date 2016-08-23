
/**
 * wander action
 * by Locke
 * lololol~
 */


var Wander = bt.Action.extend({

    isWalking:false,
    waitTime:0,

    //const
    minIdleTime:1,
    maxIdleTime:3,
    minMoveTime:1,
    maxMoveTime:2,


    ctor:function() {
        this._super();
        this.name = "Wander";
    },

    open:function(tick) {
        this.isWalking = false;
        this.waitTime = Game.GetTime() + Random(this.minIdleTime,this.maxIdleTime);
    },

    tick:function(tick) {

        var entity = tick.target;

        if (this.isWalking) {
            if (Game.GetTime() > this.waitTime) {
                this.isWalking = false;
                this.waitTime = Game.GetTime() + Random(this.minIdleTime,this.maxIdleTime);
                var locomotor = entity.GetComponent(gn.ComName.Locomotor);
                locomotor.StopMove();
                return bt.SUCCESS;
            }
        }
        else {
            if (Game.GetTime() > this.waitTime) {
                this.isWalking = true;
                this.PickRandomDirection(entity);
            }
        }

        return bt.RUNNING;
    },

    close:function(tick) {
    },

    PickRandomDirection:function(entity) {
        var locomotor = entity.GetComponent(gn.ComName.Locomotor);
        var tranform = entity.GetComponent(gn.ComName.Transform);
        var homePos = entity.GetBlackboard(gn.BB.HomePosition);
        if (Math.abs(homePos.x - tranform.GetX()) > 100 || Math.abs(homePos.y - tranform.GetY()) > 100) {
            this.waitTime = Game.GetTime() + Random(5, 6);
            locomotor.MoveToPoint(homePos.x, homePos.y);
        } else {
            this.waitTime = Game.GetTime() + Random(this.minMoveTime,this.maxMoveTime);
            var angle = Math.random() * 360;
            locomotor.MoveTowards(angle);
        }

    }

});







