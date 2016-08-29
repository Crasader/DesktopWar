
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
        this.attrCom = this.entity.GetComponent(gn.ComName.Attr);
        if (null == this.attrCom) {
            print('Locomotor.OnStart: require com attr');
        }
    },

    OnUpdate:function() {

    },

    SetPosition:function(x,y) {
        this.entity.GetComponent(gn.ComName.Transform).SetPosition(x, y);
    },

    MoveToPoint:function(x,y) {
        this.isMoving = true;
        var speed = this.attrCom.Get(gn.Attr.SPD);
        this.entity.GetComponent(gn.ComName.Transform).MoveTo(x, y, speed);
        this.entity.StartUpdateComponent(this);
        this.entity.PushEvent(gn.Event.Locomote);
    },

    MoveToEntity:function(entity){
        var targetTran = entity.GetComponent(gn.ComName.Transform);
        var x = targetTran.GetX();
        var y = targetTran.GetY();
        this.MoveToPoint(x, y);
    },

    MoveTowards:function(angle) {
        this.isMoving = true;
        var speed = this.attrCom.Get(gn.Attr.SPD);
        this.entity.GetComponent(gn.ComName.Transform).MoveTowards(angle, speed);
        this.entity.StartUpdateComponent(this);
        this.entity.PushEvent(gn.Event.Locomote);
    },

    StopMove:function() {
        if (this.isMoving) {
            this.isMoving = false;
            this.entity.GetComponent(gn.ComName.Transform).SetVelocity(0, 0);
            this.entity.StopUpdateComponent(this);
            this.entity.PushEvent(gn.Event.Locomote);
        }
    },

    FaceToEntity:function(target){
        if(target instanceof EntityScript){
            var targetTran = target.GetComponent(gn.ComName.Transform);
            var x = targetTran.GetX();
            var y = targetTran.GetY();
            this.entity.PushEvent(gn.Event.FaceTo,{targetX:x,targetY:y});
        }

    }

});





