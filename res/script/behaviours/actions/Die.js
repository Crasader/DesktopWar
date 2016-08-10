
/**
 * Die action
 * by Locke
 * lololol~
 */


var Die = bt.Action.extend({

    timeWait:0,

    ctor:function()
    {
        this._super();
        this.name = "Die";
    },

    open:function(tick)
    {
        print("open die");
        this.timeWait = Game.GetTime() + 2;
        var entity = tick.target;
        entity.PushEvent(gn.Event.Die);
    },

    tick:function(tick)
    {
        //if (Game.GetTime() > this.timeWait)
        //{


            //return bt.SUCCESS;
        //}

        return bt.RUNNING;
    },


    close:function(tick)
    {

    }

});







