


// manualy

var SimplePawnBT = new bt.BehaviorTree();

SimplePawnBT.root =
    PriorityNode(
        WhileNode(InverterNode(new IsAlive), new Die),
        WhileNode(new TargetIsInFarRange, new AttackFar),
        WhileNode(new TargetIsInNearRange, new AttackNear),
        WhileNode(new IsAlive, new Wander)
    );






