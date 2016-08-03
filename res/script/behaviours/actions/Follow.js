
/**
 * Follow action
 * by Locke
 * lololol~
 */


var Follow = bt.Action.extend({

    // 延迟x秒跟随
    delayTime:2,
    timeWait:0,

    ctor:function()
    {
        this._super();
        this.name = "Follow";
    },

    open:function(tick)
    {
        this.timeWait = Game.GetTime() + this.delayTime;
    },

    tick:function(tick)
    {
        if (Game.GetTime() > this.timeWait)
        {
            print("check to follow");
            this.timeWait = Game.GetTime() + this.delayTime;

            var entity = tick.target;
            var followTar = entity.GetBlackboard(BB.FollowTarget);
            if(null == followTar)
            {
                print("Follow : no target !");
                return bt.ERROR;
            }
            var x,y;
            var targetTran = followTar.GetComponent(ComName.Transform);
            x = targetTran.GetX();
            y = targetTran.GetY();
            var locomotor =  entity.GetComponent(ComName.Locomotor);
            locomotor.MoveToPoint(x, y);
        }

        return bt.RUNNING;
    },


    close:function(tick)
    {

    }

});







