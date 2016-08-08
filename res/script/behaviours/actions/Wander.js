
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
                this.waitTime = Game.GetTime() + Random(3, 5);
                var locomotor = entity.GetComponent(ComName.Locomotor);
                locomotor.StopMove();
            }
        }
        else
        {
            if (Game.GetTime() > this.waitTime)
            {
                this.isWalking = true;
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
        var tranform = entity.GetComponent(ComName.Transform);
        var homePos = entity.GetBlackboard(BB.HomePosition);
        if(Math.abs(homePos.x - tranform.GetX()) > 200 || Math.abs(homePos.y - tranform.GetY()) > 200){
            this.waitTime = Game.GetTime() + Random(6, 10);
            locomotor.MoveToPoint(homePos.x, homePos.y);
        }else{
            this.waitTime = Game.GetTime() + Random(3, 5);
            var angle = Math.random()*360;
            locomotor.MoveTowards(angle);
        }

    }

});







