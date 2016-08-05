

var commonStatus = {};

commonStatus.sampleState =
{
    name:'sampleState',

    onenter:function(entity)
    {

    },

    onexit:function(entity)
    {

    },

    events:
    {

    }
};





commonStatus.AddIdle = function(status)
{
    var st =
    {
        name: 'idle',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Idle);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddDie = function(status)
{
    var st =
    {
        name: 'die',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Die);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddMove = function(status)
{
    var st =
    {
        name: 'move',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Move);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddAttackNear = function(status)
{
    var st =
    {
        name: 'attackNear',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Atk1);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddAttackFar = function(status)
{
    var st =
    {
        name: 'attackFar',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Atk2);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddSkill1 = function(status)
{
    var st =
    {
        name: 'skill1',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Skill1);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};


commonStatus.AddSkill2 = function(status)
{
    var st =
    {
        name: 'skill2',

        onenter: function (entity) {
            entity.PlayAnimation(AnimName.Skill2);
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = new State(st);
};



commonStatus.OnLocomote = function()
{
    return EventHandler('locomote',
    function(entity){
        var locomotor = entity.GetComponent(ComName.Locomotor);
        if(locomotor){
            var anim = entity.GetComponent(ComName.Animation);
            anim.PlayAnimation('idle');
        }
    }
    );
};





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
        new EventHandler('locomote', function(){}),
    ];


    return new StateGraph(entity, status, events, 'idle');
}






