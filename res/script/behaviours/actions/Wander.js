
/**
 * wander action
 * by Locke
 * lololol~
 */


var Wander = b3.Class(b3.Action);

(function(){
    "use strict";

    var p = Wander.prototype;
    p.name = 'Wander';


    p.enter = function(tick) {};


    p.open = function(tick)
    {
        var bb = tick.blackboard;
        bb.set('isRunning', false, tick.tree.id, this.id);
        bb.set('waitTime', 0, tick.tree.id, this.id);
    };


    p.tick = function(tick)
    {
        var bb = tick.blackboard;
        var isRunning = bb.get('isRunning', tick.tree.id, this.id);
        var waitTime = bb.get('waitTime', tick.tree.id, this.id);

        if (isRunning)
        {
            if (Game.GetTime() > waitTime)
            {
                isRunning = false;
                waitTime = PickRandomDirection();
            }
        }
        else
        {
            if (Game.GetTime() > waitTime)
            {
                isRunning = true;
                waitTime = PickRandomDirection();
            }
        }

        // save mem
        bb.set('isRunning', isRunning, tick.tree.id, this.id);
        bb.set('waitTime', waitTime, tick.tree.id, this.id);

        return b3.RUNNING;
    };


    p.close = function(tick)
    {

    };


    p.exit = function(tick) {};

    //
    function PickRandomDirection()
    {
        var waitTime = Game.GetTime() + 5;
        return waitTime
    }

})();





