

//js层的组件，有自己的各种行为


var Component = Class.extend({

    name:"Component",
    entity:null,
    isComponentClass:true,

    GetName:function()
    {
        return this.name;
    },

    SetEntity:function(_entity)
    {
        this.entity = _entity;
    },

    OnAwake:function()
    {

    },

    OnStart:function()
    {

    },

    OnUpdate:function()
    {

    },

    OnLongUpdate:function()
    {

    },

    OnDestroy:function()
    {

    },

    OnEnable:function()
    {

    },

    OnDisable:function()
    {

    }


});

