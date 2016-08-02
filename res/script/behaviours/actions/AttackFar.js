
/**
 * AttackFar action
 * by Locke
 * lololol~
 */


var AttackFar = bt.Action.extend({

    timePassed:0,

    ctor:function()
    {
        this.timePassed = 0;
    },

    open:function(tick)
    {
        this.timePassed = 0;
    },

    tick:function(tick)
    {
        this.timePassed += Game.updateTime;

        if (this.timePassed > 3)
        {
            //change dir
            //return b3.SUCCESS;
        }

        return bt.RUNNING;
    },


    close:function(tick)
    {

    }

});







