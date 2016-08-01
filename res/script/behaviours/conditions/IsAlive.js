
/**
 * is agent alive ?
 * by Locke
 * lololol~
 */


var IsAlive = b3.Class(b3.Condition);

(function(){
    "use strict";

    var p = IsAlive.prototype;
    p.name = 'IsAlive';


    p.tick = function(tick)
    {
        var entity = tick.target;
        var attr = entity.GetComponent(ComName.Attr);
        if (attr.Get(Attr.HP) > 0)
        {
            return b3.SUCCESS;
        }
        else
        {
            return b3.FAILURE;
        }
    };


})();
