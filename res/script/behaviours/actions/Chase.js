






/**
 * Chase action
 * by Locke
 * lololol~
 */


var Chase = bt.Action.extend({

    // 延迟x秒跟随
    delayTime:1.5,
    // x秒再次定位
    checkTime:2,
    timeWait:0,

    ctor:function() {
        this._super();
        this.name = "Chase";
    },

    open:function(tick) {
        this.timeWait = Game.GetTime() + this.delayTime;
    },

    tick:function(tick) {
        var entity = tick.target;
        var locomotor = null;
        var followTar = entity.GetBlackboard(BB.CombatTarget);
        if (null == followTar) {
            print("Chase : no target !");
            return bt.ERROR;
        }

        if (EntityUtility.AreEntitiesCloseEnough(entity.GetEntityNative(), followTar.GetEntityNative(), 20)) {
            locomotor = entity.GetComponent(ComName.Locomotor);
            locomotor.StopMove();
            //return bt.SUCCESS;
        }

        if (Game.GetTime() > this.timeWait) {
            print("check to chase");

            locomotor = entity.GetComponent(ComName.Locomotor);
            locomotor.MoveToEntity(followTar);

            this.timeWait = Game.GetTime() + this.checkTime;
        }

        return bt.RUNNING;
    },


    close:function(tick) {

    }

});







