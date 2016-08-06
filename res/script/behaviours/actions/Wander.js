
/**
 * wander action
 * by Locke
 * lololol~
 */


var Wander = bt.Action.extend({

    isWalking:false,
    waitTime:0,

    ctor:function()
    {
        this._super();
        this.name = "Wander";
    },

    open:function(tick)
    {
        this.isWalking = false;
        this.waitTime = Game.GetTime() + 3;
    },

    tick:function(tick)
    {
        //print("wait " + this.waitTime);

        var entity = tick.target;

        if (this.isWalking)
        {
            if (Game.GetTime() > this.waitTime)
            {
                this.isWalking = false;
                this.waitTime = Game.GetTime() + 3;
                var locomotor = entity.GetComponent(ComName.Locomotor);
                locomotor.StopMove();
            }
        }
        else
        {
            if (Game.GetTime() > this.waitTime)
            {
                this.isWalking = true;
                this.waitTime = Game.GetTime() + 3;

                this.PickRandomDirection(entity);
            }
        }

        return bt.RUNNING;
    },

    close:function(tick)
    {
    },

    PickRandomDirection:function(entity)
    {
        var locomotor = entity.GetComponent(ComName.Locomotor);
        var angle = Math.random()*360;
        locomotor.MoveTowards(angle);
    }

});







