


function CreateSimplePawnBTree(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInFarRange, new AttackFar),
            WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}





