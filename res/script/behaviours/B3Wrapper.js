

/**
 * my nodes ?
 * by Locke
 * lololol~
 */


//
// 对bt的“封装”，简化创建代码
//


function SequenceNode()
{
    var child = null;
    var nodeArray = Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof bt.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new bt.Sequence({children:nodeArray});
}


function PriorityNode()
{
    var child = null;
    var nodeArray = Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof bt.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new bt.Priority({children:nodeArray});
}

function MemSequenceNode()
{
    var child = null;
    var nodeArray = Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof bt.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new bt.MemSequence({children:nodeArray});
}

function MemPriorityNode()
{
    var child = null;
    var nodeArray = Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof bt.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new bt.MemPriority({children:nodeArray});
}

function ParallelNode()
{
    var child = null;
    var nodeArray = Array();
    for(var i = 0; i < arguments.length; ++i)
    {
        child = arguments[i];
        if(child instanceof bt.BaseNode)
        {
            nodeArray[i] = child;
        }
    }
    return new bt.Parallel({children:nodeArray});
}


function InverterNode(condition)
{
    if(!condition instanceof bt.Condition)
    {
        print("InverterNode : invalid param.");
        return null;
    }

    return new bt.Inverter({child:condition});
}


function WhileNode(condition, action)
{
    if (!condition instanceof bt.Condition || !action instanceof bt.Action)
    {
        print("WhileNode : invalid param.");
        return null;
    }

    return ParallelNode(condition, action);
}

function WaitNode(seconds){
    return new bt.Wait({milliseconds:seconds*1000});
}




