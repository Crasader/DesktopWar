

var commonStatus = {};

///////////////////////////////anim event handlers/////////////////////////

commonStatus.OnFrameAttack1 = function()
{
    return new EventHandler(gn.Event.FrameAttack1,
        function(entity) {
            var target = entity.GetBlackboard(gn.BB.CombatTarget);
            if(target != null){
                var cfg = entity.GetBlackboard(gn.BB.RoleCfg);
                var can = gn.SkillMgr.CanUseSkill(entity.GetID(), target.GetID(), cfg.normalSkill1);
                if (can) {
                    gn.SkillMgr.UseSkill(entity.GetID(), target.GetID(), cfg.normalSkill1);
                }
            }
        }
    );
};

commonStatus.OnFrameSkill1 = function()
{
    return new EventHandler(gn.Event.FrameSkill1,
        function(entity) {
            var targetID = gn.InvalidEntityID;
            var target = entity.GetBlackboard(gn.BB.CombatTarget);
            if(target != null) {
                targetID = target.GetID();
            }
            var cfg = entity.GetBlackboard(gn.BB.RoleCfg);
            var can = gn.SkillMgr.CanUseSkill(entity.GetID(), targetID, cfg.specialSkill1);
            if (can) {
                gn.SkillMgr.UseSkill(entity.GetID(), targetID, cfg.specialSkill1);
            }
        }
    );
};

commonStatus.OnFrameSkill2 = function()
{
    return new EventHandler(gn.Event.FrameSkill2,
        function(entity) {
            var targetID = gn.InvalidEntityID;
            var target = entity.GetBlackboard(gn.BB.CombatTarget);
            if(target != null) {
                targetID = target.GetID();
            }
            var cfg = entity.GetBlackboard(gn.BB.RoleCfg);
            var can = gn.SkillMgr.CanUseSkill(entity.GetID(), targetID, cfg.specialSkill1);
            if (can) {
                gn.SkillMgr.UseSkill(entity.GetID(), targetID, cfg.specialSkill1);
            }
        }
    );
};


///////////////////////////////common state/////////////////////////

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.Idle,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Idle);
        },

        onexit: function (entity) {

        },

        events: []
    };

    commonStatus.idle = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.Die,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Die);
        },

        onexit: function (entity) {

        },

        events: [
            new EventHandler(gn.Event.AnimComplete, function(entity) {Game.DestroyEntity(entity);})
        ]
    };

    commonStatus.die = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.Move,

        onenter: function (entity) {
            PlayPawnAnim(entity, gn.AnimName.Move);
        },

        onexit: function (entity) {

        },

        events: [

        ]
    };

    commonStatus.move = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.AttackNear,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Atk1);
        },

        onexit: function (entity) {

        },

        events: [
            commonStatus.OnFrameAttack1(),
            new EventHandler(gn.Event.AnimLoopComplete, function(entity) {
                var tar = entity.GetBlackboard(gn.BB.CombatTarget);
                if(tar!=null){
                    var attr = tar.GetComponent(gn.ComName.Attr);
                    if(attr.Get(gn.Attr.HP)<=0){
                        entity.GetStateGraph().gotoState(gn.SG.Idle);
                    }
                }else{
                    entity.GetStateGraph().gotoState(gn.SG.Idle);
                }

            })
        ]
    };

    commonStatus.attackNear = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.AttackFar,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Atk2);
        },

        onexit: function (entity) {

        },

        events: {
            //
        }
    };

    commonStatus.attackFar = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.Skill1,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Skill1);
        },

        onexit: function (entity) {

        },

        events: [
            commonStatus.OnFrameSkill1(),
            commonStatus.OnFrameSkill2(),
            new EventHandler(gn.Event.AnimComplete, function(entity) {entity.GetStateGraph().gotoState(gn.SG.Idle)}),
        ]
    };

    commonStatus.skill1 = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: gn.SG.Skill2,

        onenter: function (entity) {
            entity.GetComponent(gn.ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, gn.AnimName.Skill2);
        },

        onexit: function (entity) {

        },

        events: [
            new EventHandler(gn.Event.AnimComplete, function(entity) {entity.GetStateGraph().gotoState(gn.SG.Idle)}),
        ]
    };

    commonStatus.skill2 = new State(st);

})();


commonStatus.AddIdle = function(status) {
    status[commonStatus.idle.getName()] = commonStatus.idle;
};
commonStatus.AddDie = function(status) {
    status[commonStatus.die.getName()] = commonStatus.die;
};
commonStatus.AddMove = function(status) {
    status[commonStatus.move.getName()] = commonStatus.move;
};
commonStatus.AddAttackNear = function(status) {
    status[commonStatus.attackNear.getName()] = commonStatus.attackNear;
};
commonStatus.AddAttackFar = function(status) {
    status[commonStatus.attackFar.getName()] = commonStatus.attackFar;
};
commonStatus.AddSkill1 = function(status) {
    status[commonStatus.skill1.getName()] = commonStatus.skill1;
};
commonStatus.AddSkill2 = function(status) {
    status[commonStatus.skill2.getName()] = commonStatus.skill2;
};



///////////////////////////////graph event handlers/////////////////////////

commonStatus.OnLocomote = function() {
    return new EventHandler(gn.Event.Locomote,
        function (entity) {
            var locomotor = entity.GetComponent(gn.ComName.Locomotor);
            var isMoving = locomotor.IsMoving();
            if (isMoving) {
                entity.GetStateGraph().gotoState(gn.SG.Move);
            }
            else {
                entity.GetStateGraph().gotoState(gn.SG.Idle);
            }
        }
    );
};

commonStatus.OnArrived = function(entity){
    return new EventHandler(gn.Event.Arrived,
        function(entity) {
            entity.GetStateGraph().gotoState(gn.SG.Idle);
        }
    );
},


commonStatus.OnFaceTo = function()
{
    return new EventHandler(gn.Event.FaceTo,
        function(entity, data) {
            //face to tar
            var transform = entity.GetComponent(gn.ComName.Transform);
            transform.FaceTo(data.targetX, data.targetY);
        }
    );
};


commonStatus.OnDie = function()
{
    return new EventHandler(gn.Event.Die,
        function(entity) {
            print('sg:on die');
            entity.GetStateGraph().gotoState(gn.SG.Die);
        }
    );
};


///////////////////////////////graph/////////////////////////

function CreateCommonGraph(entity)
{
    var status = {};
    commonStatus.AddIdle(status);
    commonStatus.AddDie(status);
    commonStatus.AddMove(status);
    commonStatus.AddAttackNear(status);
    commonStatus.AddAttackFar(status);
    commonStatus.AddSkill1(status);
    commonStatus.AddSkill2(status);

    var events = [
        commonStatus.OnLocomote(),
        commonStatus.OnArrived(),
        commonStatus.OnFaceTo(),
        commonStatus.OnDie()
    ];
    
    return new StateGraph(entity, status, events, gn.SG.Idle);
}






