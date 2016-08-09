
/**
 * Follow action
 * by Locke
 * lololol~
 */


var Follow = bt.Action.extend({

    // 延迟x秒跟随
    delayTime:1.5,
    // x秒再次定位
    checkTime:2,
    timeWait:0,

    ctor:function() {
        this._super();
        this.name = "Follow";
    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + this.delayTime;
    },

    tick:function(tick) {
        var entity = tick.target;
        var followTar = entity.GetBlackboard(gn.BB.FollowTarget);
        if (null == followTar) {
            print("Follow : no target !");
            return bt.ERROR;
        }

        if (EntityUtility.AreEntitiesCloseEnough(entity.GetEntityNative(), followTar.GetEntityNative(), 10)) {
            var locomotor = entity.GetComponent(gn.ComName.Locomotor);
            locomotor.StopMove();
            return bt.SUCCESS;
        }

        if (Game.GetTime() > this.timeWait) {
            print("check to follow");
            this.timeWait = Game.GetTime() + this.delayTime;

            var locomotor = entity.GetComponent(gn.ComName.Locomotor);
            locomotor.MoveToEntity(followTar);

            this.timeWait = Game.GetTime() + this.checkTime;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    }

});







