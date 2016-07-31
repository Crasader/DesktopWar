

// names of all components
var ComName =
{
    // native coms
    Transform:"ComTransform",
    Render:"ComRenderRoot",
    BoxCollider:"ComBoxCollider",
    Direction:"ComDirection",
    Animation:"ComAnimation",
    Particle:"ComParticle",
    BezierMovement:"ComBezierMovement",
    DelayTrackMovement:"ComDelayTrackMovement",

    PawnAgent:"ComPawnAgent",
    PawnAnim:"ComPawnAnim",
    PawnDebugDraw:"ComPawnDebugDraw",
    PawnFight:"ComPawnFight",
    PawnNavigation:"ComPawnNavigation",
    PawnBevtree:"ComPawnBevtree",

    BulletAnimArrow:"ComBulletAnimArrow",
    BulletAnimBase:"ComBulletAnimBase",
    BulletAnimBomb:"ComBulletAnimBomb",
    BulletDamage:"ComBulletDamage",
    BulletDebugDraw:"ComBulletDebugDraw",
    BulletAnimEgg:"ComBulletAnimEgg",

    // js coms
    Attr:"Attr",
    Brain:"Brain",
    Combat:"Combat",
    Locomotor:"Locomotor",


};


var Tag =
{
    Soldier:"Soldier",
    Monster:"Monster",
};


var BulletMoveType =
{
    Unknown : 0,
    Line : 1,
    Bezier : 2,
    Tracking : 3
};

var TargetType =
{
    Entity:0,			// 以某entity做目标
    Location:1,		// 以某位置做目标
};


