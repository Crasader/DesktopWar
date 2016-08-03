
/**
 * locomotor component
 * by Locke
 * lololol~
 */



var Locomotor = BaseComponent.extend({

    name:"Locomotor",
    attrCom:null,

    ctor:function ()
    {

    },

    SetBTree:function(_btree)
    {
        this.btree = _btree;
    },

    OnStart:function()
    {
        this.attrCom = this.entity.GetComponent(ComName.Attr);
        if (null == this.attrCom)
        {
            print('Locomotor.OnStart: require com attr');
        }
    },

    OnUpdate:function()
    {

    },

    OnLongUpdate:function()
    {

    },

    SetPosition:function(x,y)
    {
        this.entity.GetComponent(ComName.Transform).SetPosition(x,y);
    },

    MoveToPoint:function(x,y)
    {
        var speed = this.attrCom.Get(Attr.SPD);
        this.entity.GetComponent(ComName.Transform).MoveTo(x,y,speed);
    },

    MoveTowards:function(angle)
    {
        var speed = this.attrCom.Get(Attr.SPD);
        this.entity.GetComponent(ComName.Transform).MoveTowards(angle,speed);
    },

    StopMove:function()
    {
        this.entity.GetComponent(ComName.Transform).SetVelocity(0,0);
    }

});





