

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
            entity.GetComponent(ComName.Animation).PlayAnimation('idle');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddDie = function(status)
{
    var st =
    {
        name: 'die',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('die');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddMove = function(status)
{
    var st =
    {
        name: 'move',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('move');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddAttackNear = function(status)
{
    var st =
    {
        name: 'attackNear',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('attackNear');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddAttackFar = function(status)
{
    var st =
    {
        name: 'attackFar',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('attackFar');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddSkill1 = function(status)
{
    var st =
    {
        name: 'skill1',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('skill1');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
};


commonStatus.AddSkill2 = function(status)
{
    var st =
    {
        name: 'skill2',

        onenter: function (entity) {
            entity.GetComponent(ComName.Animation).PlayAnimation('skill2');
        },

        onexit: function (entity) {

        },

        events: {}
    };
    status[st.name] = st;
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

    return new StateGraph(entity, status, 'idle');
}






