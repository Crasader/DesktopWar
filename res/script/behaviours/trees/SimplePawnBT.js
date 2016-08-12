

//普通近战单位
function CreateFootManBTree(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}

//普通远近战单位，例如暗影射手
function CreateArcherBTree(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new TargetIsInFarRange, new Skill1),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}


//蜘蛛之母
// 近战》追击》巡逻+产卵
function CreateBTree_NoxiousCreeeper(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new AttackNear),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, MemSequenceNode(new Wander, WaitNode(3), new Skill1))
        );
    return tree;
}



















