
/**
 * TargetIsInNearRange ?
 * by Locke
 * lololol~
 */


var TargetIsInNearRange = b3.Class(b3.Condition);

(function(){
    "use strict";

    var p = TargetIsInNearRange.prototype;
    p.name = 'TargetIsInNearRange';


    p.tick = function(tick)
    {
        var entity = tick.target;
        var combat = entity.GetComponent(ComName.Combat);
        if (combat.GetTarget() != null && false)
        {
            return b3.SUCCESS;
        }
        else
        {
            return b3.FAILURE;
        }
    };


})();
