

/**
 * my nodes ?
 * by Locke
 * lololol~
 */



/**
 * The Parallel node ticks its children parallelly.If one child returns the failure state,the parallel also returns `FAILURE`.
 **/
var Parallel = b3.Class(b3.Composite);
(function() {
    "use strict";

    var p = Parallel.prototype;

    p.name = 'Parallel';

    p.tick = function(tick) {
        var done = true;
        for (var i=0; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== b3.SUCCESS) {
                done = false;
            }else if (status === b3.FAILURE) {
                return b3.FAILURE;
            }
        }

        if (done)
            return b3.SUCCESS;
        else
            return b3.RUNNING;
    }

})();


//
// 对b3的“封装”，简化创建代码
//


function SequenceNode()
{
    var child = null;
    var nodeArray = new Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof b3.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new b3.Sequence({children:nodeArray});
}


function PriorityNode()
{
    var child = null;
    var nodeArray = new Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof b3.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new b3.Priority({children:nodeArray});
}

function MemSequenceNode()
{
    var child = null;
    var nodeArray = new Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof b3.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new b3.MemSequence({children:nodeArray});
}

function MemPriorityNode()
{
    var child = null;
    var nodeArray = new Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof b3.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new b3.MemPriority({children:nodeArray});
}

function ParallelNode()
{
    var child = null;
    var nodeArray = new Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof b3.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new Parallel({children:nodeArray});
}


function InverterNode(condition)
{
    if(!condition instanceof b3.Condition)
    {
        print("InverterNode : invalid param.");
        return null;
    }

    return new b3.Inverter({child:condition});
}


function WhileNode(condition, action)
{
    if (!condition instanceof b3.Condition || !action instanceof b3.Action)
    {
        print("WhileNode : invalid param.");
        return null;
    }

    return ParallelNode(condition, action);
}
