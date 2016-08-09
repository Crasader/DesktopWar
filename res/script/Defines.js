
var gn = gn || {};

// global toggles and settings
gn.Setting =
{
    DebugDraw:false,
};

/////////////////////////////////

// names of all components
gn.ComName =
{
    // native coms
    Transform: "ComTransform",
    Render: "ComRenderRoot",
    BoxCollider: "ComBoxCollider",
    Direction: "ComDirection",
    Animation: "ComAnimation",
    Particle: "ComParticle",
    BezierMovement: "ComBezierMovement",
    DelayTrackMovement: "ComDelayTrackMovement",

    PawnAgent: "ComPawnAgent",
    PawnAnim: "ComPawnAnim",
    PawnDebugDraw: "ComPawnDebugDraw",
    PawnFight: "ComPawnFight",
    PawnNavigation: "ComPawnNavigation",
    PawnBevtree: "ComPawnBevtree",

    BulletAnimArrow: "ComBulletAnimArrow",
    BulletAnimBase: "ComBulletAnimBase",
    BulletAnimBomb: "ComBulletAnimBomb",
    BulletDamage: "ComBulletDamage",
    BulletDebugDraw: "ComBulletDebugDraw",
    BulletAnimEgg: "ComBulletAnimEgg",

    // js coms
    Attr: "Attr",
    Brain: "Brain",
    Combat: "Combat",
    Locomotor: "Locomotor",


};


gn.Tag =
{
    Soldier:"Soldier",
    Monster:"Monster",
};


gn.BulletMoveType =
{
    Unknown : 0,
    Line : 1,
    Bezier : 2,
    Tracking : 3
};

gn.TargetType =
{
    Entity:0,			// 以某entity做目标
    Location:1,		// 以某位置做目标
};

// 攻击类型
gn.AttackType =
{
    Physic:1,
    Magic:2
};

// 角色朝向
gn.FaceDir =
{
    Left:1 << 1,
    Right:1 << 2,
    Up	:1 << 3,
    Down:1 << 4
};


// 状态名
gn.SG =
{
    Idle:'idle',
    Die:'die',
    Move:'move',
    AttackNear:'attackNear',
    AttackFar:'attackFar',
    Atk3:'attack3',
    Skill1:'skill',
    Skill2:'skill2',
    Skill3:'skill3'
};

// 约定动画名
gn.AnimName =
{
    Idle:'idle',
    Die:'die',
    Move:'move',
    Atk1:'attack',
    Atk2:'attack2',
    Atk3:'attack3',
    Skill1:'skill',
    Skill2:'skill2',
    Skill3:'skill3'
};

gn.PawnAnimName =
{
    Idle_L:"idle_left",
    Idle_R:"idle_right",
    Die_L:"die_left",
    Die_R:"die_right",

    Move_L:"move_left",
    Move_R:"move_right",
    Move_Up:"move_up",
    Move_Down:"move_down",

    Attack1_L:"attack_left",
    Attack1_R:"attack_right",
    Attack2_L:"attack2_left",
    Attack2_R:"attack2_right",
    Attack3_L:"attack3_left",
    Attack3_R:"attack3_right",
    Skill1_L:"skill_left",
    Skill1_R:"skill_right",
    Skill2_L:"skill2_left",
    Skill2_R:"skill2_right",
    Skill3_L:"skill3_left",
    Skill3_R:"skill3_right"

};

// event names
gn.Event =
{
    Locomote:"Locomote",
    FaceTo:"FaceTo",
    Attack:"Attack",
    Attacked:"Attacked",

    //armature frame event
    FrameAttack1:"attack",
    FrameAttack2:"attack",
    FrameAttack3:"attack",
    FrameSkill1:"skill",
    FrameSkill2:"skill2",
    FrameSkill3:"skill3",

    //armature movement event
    AnimStart:"AnimStart",
    AnimComplete:"AnimComplete",
    AnimLoopComplete:"AnimLoopComplete",

};


// EntityScript Blackboard中的Key
gn.BB = {
    RoleCfg:"RoleCfg",
    FollowTarget:"FollowTarget",
    CombatTarget:"CombatTarget",
    HomePosition:"HomePosition"
};
