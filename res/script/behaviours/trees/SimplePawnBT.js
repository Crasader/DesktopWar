

//普通近战单位
function CreateFootManBTree(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            //WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}

//普通远近战单位
function CreateArcherBTree(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new TargetIsInFarRange, new AttackFar),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}





