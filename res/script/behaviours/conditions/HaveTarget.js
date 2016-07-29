
/**
 * have a target now ?
 * by Locke
 * lololol~
 */


(function(){
    "use strict";

    var HaveTarget = b3.Class(b3.Condition);
    var p = HaveTarget.prototype;
    p.name = 'HaveTarget';


    p.tick = function(tick)
    {
        var entity = tick.target;
        var combat = entity.GetComponent(ComName.Combat);
        if (combat != null && combat.GetTarget() != null)
        {
            return b3.SUCCESS;
        }
        else
        {
            return b3.FAILURE;
        }
    };


})();
