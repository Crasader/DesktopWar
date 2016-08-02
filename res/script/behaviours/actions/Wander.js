
/**
 * wander action
 * by Locke
 * lololol~
 */


var Wander = bt.Action.extend({

    isRunning:false,
    waitTime:0,

    ctor:function()
    {
        this._super();
        this.name = "Wander";
    },

    open:function(tick)
    {
        this.isRunning = false;
        this.waitTime = 0;
    },

    tick:function(tick)
    {
        print("wait " + this.waitTime);

        if (this.isRunning)
        {
            if (Game.GetTime() > this.waitTime)
            {
                this.isRunning = false;
                this.PickRandomDirection();
            }
        }
        else
        {
            if (Game.GetTime() > this.waitTime)
            {
                this.isRunning = true;
                this.PickRandomDirection();
            }
        }

        return b3.RUNNING;
    },

    close:function(tick)
    {
    },

    PickRandomDirection:function()
    {
        this.waitTime = Game.GetTime() + 5;
    }

});







