

var commonStatus = {};

///////////////////////////////common state/////////////////////////

(function(){
    "use strict";

    var st =
    {
        name: 'idle',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Idle);
        },

        onexit: function (entity) {

        },

        events: {}
    };

    commonStatus.idle = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'die',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Die);
        },

        onexit: function (entity) {

        },

        events: {}
    };

    commonStatus.die = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'move',

        onenter: function (entity) {
            PlayPawnAnim(entity, AnimName.Move);
        },

        onexit: function (entity) {

        },

        events: {}
    };

    commonStatus.move = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'attackNear',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Atk1);
        },

        onexit: function (entity) {

        },

        events: {
            //帧事件、动画结束事件
        }
    };

    commonStatus.attackNear = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'attackFar',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Atk2);
        },

        onexit: function (entity) {

        },

        events: {
            //帧事件、动画结束事件
        }
    };

    commonStatus.attackFar = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'skill1',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Skill1);
        },

        onexit: function (entity) {

        },

        events: {
            //帧事件、动画结束事件
        }
    };

    commonStatus.skill1 = new State(st);

})();

(function(){
    "use strict";

    var st =
    {
        name: 'skill2',

        onenter: function (entity) {
            entity.GetComponent(ComName.Locomotor).StopMove();
            PlayPawnAnim(entity, AnimName.Skill2);
        },

        onexit: function (entity) {

        },

        events: {
            //帧事件、动画结束事件
        }
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

///////////////////////////////event handlers/////////////////////////

commonStatus.OnLocomote = function()
{
    return new EventHandler('locomote',
    function(entity) {
        var locomotor = entity.GetComponent(ComName.Locomotor);
        var isMoving = locomotor.IsMoving();
        if (isMoving){
            entity.GetStateGraph().gotoState(SG.Move);
        }
        else{
            entity.GetStateGraph().gotoState(SG.Idle);
        }
    }
    );
};


commonStatus.OnFaceTo = function()
{
    return new EventHandler('faceto',
        function(entity, data) {
            //face to tar
            var transform = entity.GetComponent(ComName.Transform);
            transform.FaceTo(data.targetX, data.targetY);
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
        commonStatus.OnFaceTo()
    ];
    
    return new StateGraph(entity, status, events, 'idle');
}






