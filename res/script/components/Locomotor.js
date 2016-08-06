
/**
 * locomotor component
 * by Locke
 * lololol~
 */



var Locomotor = BaseComponent.extend({

    name:"Locomotor",
    attrCom:null,
    isMoving:false,

    ctor:function () {

    },

    IsMoving:function() {
        return this.isMoving === true;
    },

    OnStart:function() {
        this.attrCom = this.entity.GetComponent(ComName.Attr);
        if (null == this.attrCom) {
            print('Locomotor.OnStart: require com attr');
        }
    },

    OnUpdate:function() {

    },

    SetPosition:function(x,y) {
        this.entity.GetComponent(ComName.Transform).SetPosition(x, y);
    },

    MoveToPoint:function(x,y) {
        this.isMoving = true;
        var speed = this.attrCom.Get(Attr.SPD);
        this.entity.GetComponent(ComName.Transform).MoveTo(x, y, speed);
        this.entity.StartUpdateComponent(this);
        this.entity.PushEvent('locomote');
    },

    MoveTowards:function(angle) {
        this.isMoving = true;
        var speed = this.attrCom.Get(Attr.SPD);
        this.entity.GetComponent(ComName.Transform).MoveTowards(angle, speed);
        this.entity.StartUpdateComponent(this);
        this.entity.PushEvent('locomote');
    },

    StopMove:function() {
        if (this.isMoving) {
            this.isMoving = false;
            this.entity.GetComponent(ComName.Transform).SetVelocity(0, 0);
            this.entity.StopUpdateComponent(this);
            this.entity.PushEvent('locomote');
        }
    }

});





