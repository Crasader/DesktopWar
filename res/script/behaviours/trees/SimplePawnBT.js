

//沉默的羔羊
function CreateBTree_Sheep(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.Idle,gn.AnimName.Idle)),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}


//普通近战单位
function CreateBTree_FootMan(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, new Wander)
        );
    return tree;
}

//普通士兵近战单位，会警戒
function CreateBTree_CommonSolider(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, MemSequenceNode(new Wander, new TurnAround))
        );
    return tree;
}


//圣骑士 神圣打击 治疗之光
function CreateBTree_HolyKnight(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new LowerHp(150), new DoState(gn.SG.Skill1,gn.AnimName.Skill1)),// 治疗之光
            WhileNode(new TargetIsInNearRange, MemSequenceNode(
                CounterNode(3,new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)), 
                new DoState(gn.SG.AttackNearSpecial,gn.AnimName.Atk2))),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, MemSequenceNode(new Wander, new TurnAround))
        );
    return tree;
}


//普通远近战单位，例如暗影射手
function CreateBTree_Archer(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)),
            WhileNode(new TargetIsInFarRange, new DoState(gn.SG.Skill1,gn.AnimName.Skill1)),
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
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)),
            WhileNode(new TargetIsInViewSight, new Chase),
            WhileNode(new IsAlive, MemSequenceNode(new Wander, WaitNode(2), new DoState(gn.SG.Skill1,gn.AnimName.Skill1)))
        );
    return tree;
}


//狂暴魔像
// 近战》巡逻+火箭弹
function CreateBTree_Juggernaut(){

    var tree = new bt.BehaviorTree();
    tree.root =
        PriorityNode(
            WhileNode(InverterNode(new IsAlive), new Die),
            WhileNode(new TargetIsInNearRange, new DoState(gn.SG.AttackNear,gn.AnimName.Atk1)),
            WhileNode(new IsAlive, MemSequenceNode(new Wander, WaitNode(3), new DoState(gn.SG.Skill1,gn.AnimName.Skill1)))
        );
    return tree;
}


















