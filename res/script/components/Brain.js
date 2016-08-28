
/**
 * brain component
 * by Locke
 * lololol~
 */



var Brain = BaseComponent.extend({

    name:"Brain",
    btree:null,
    blackboard:null,

    ctor:function (btree) {
        this.btree = btree;
        this.blackboard = new bt.Blackboard();
    },

    OnAwake:function(){

    },

    OnUpdate:function() {

        this.DoUpdate();

        if (null != this.btree) {
            this.btree.tick(this.entity, this.blackboard);
        }
    },

    OnLongUpdate:function() {
        print('brain long update.');
    },

    DoUpdate:function(){
        // find target for test.
        //return;
        var tar = this.entity.GetBlackboard(gn.BB.CombatTarget);
        if(tar==null){
            for(var id in Game.entityList){
                var ent = Game.entityList[id];
                if(ent === this.entity)
                    continue;
                var attr = ent.GetComponent(gn.ComName.Attr);
                if(attr==undefined || attr==null || attr.Get(gn.Attr.HP)<=0)
                    continue;
                print('brain find a target.');
                this.entity.SetBlackboard(gn.BB.CombatTarget, ent);
            }
        }
        else{
            var attr = tar.GetComponent(gn.ComName.Attr);
            if(attr.Get(gn.Attr.HP)<=0){
                tar = null;
                this.entity.SetBlackboard(gn.BB.CombatTarget,null);
            }
        }
    },

    PushEvent:function(event,data) {
        if(this.btree != null){
            this.btree.PushEvent(this.blackboard,event,data);
        }
    }

});





