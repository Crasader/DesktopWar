
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
        this.timeWait = Game.GetTime() + 2;
    },

    tick:function(tick)
    {
        if (Game.GetTime() > this.timeWait)
        {
            print("die succeed");
            var entity = tick.target;
            Game.DestroyEntity(entity);
            return bt.SUCCESS;
        }

        return bt.RUNNING;
    },


    close:function(tick)
    {

    }

});







