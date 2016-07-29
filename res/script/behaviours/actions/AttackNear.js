
/**
 * AttackNear action
 * by Locke
 * lololol~
 */


var AttackNear = b3.Class(b3.Action);

(function(){
    "use strict";


    var p = AttackNear.prototype;
    p.name = 'AttackNear';


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

        return b3.RUNNING;
    };


    p.close = function(tick)
    {

    };


})();





