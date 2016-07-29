
/**
 * TargetIsInFarRange ?
 * by Locke
 * lololol~
 */


var TargetIsInFarRange = b3.Class(b3.Condition);

(function(){
    "use strict";

    var p = TargetIsInFarRange.prototype;
    p.name = 'TargetIsInFarRange';


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
