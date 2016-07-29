

/**
 * die action
 * by Locke
 * lololol~
 */



var Die = b3.Class(b3.Action);

(function(){
    "use strict";


    var p = Die.prototype;
    p.name = 'Die';


    p.open = function(tick)
    {
        tick.blackboard.set('timePassed', 0, tick.tree.id, this.id);
    };


    p.tick = function(tick)
    {
        var timePassed = tick.blackboard.get('timePassed', tick.tree.id, this.id);
        timePassed += tick.target.curUpdateTime;

        if (timePassed > 3)
        {
            //change dir
            //return b3.SUCCESS;
        }
        print("die")

        return b3.RUNNING;
    };


    p.close = function(tick)
    {

    };


})();





