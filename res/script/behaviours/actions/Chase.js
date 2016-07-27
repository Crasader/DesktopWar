


var Chase = b3.Class(b3.Action);

var p = Chase.prototype;

p.name = 'Chase';


p.enter = function(tick) {};


p.open = function(tick)
{
    tick.blackboard.set('timePassed', 0, tick.tree.id, this.id);
};


p.tick = function(tick)
{
    var timePassed = tick.blackboard.get('timePassed', tick.tree.id, this.id);
    timePassed += tick.entity.curUpdateTime;

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


p.exit = function(tick) {};



