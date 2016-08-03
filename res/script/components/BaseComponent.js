

//js层的组件，有自己的各种行为


var BaseComponent = Class.extend({

    name:"BaseComponent",
    entity:null,
    isFirstUpdate:true,


    GetName:function()
    {
        return this.name;
    },

    SetEntity:function(_entity)
    {
        this.entity = _entity;
    },

    GetIsFirstUpdate:function()
    {
        return this.isFirstUpdate;
    },

    SetIsFirstUpdate:function(value)
    {
        this.isFirstUpdate = value;
    },

    OnAwake:function()
    {

    },

    OnStart:function()
    {

    },

    /*OnUpdate:function()
    {

    },

    OnLongUpdate:function()
    {

    },*/

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


