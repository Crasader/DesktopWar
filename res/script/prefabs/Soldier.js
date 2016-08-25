



var Soldier = {

    OnAttacked:function(entity,attacker){
        entity.SetBlackboard(gn.BB.CombatTarget,attacker);
    },


    Create:function(id, posx, posy, tag)
    {
        "use strict";

        var inst = Game.CreateEntity();
        var roleCfg = Config.Role[id];
        inst.SetBlackboard(gn.BB.RoleCfg, roleCfg);
        inst.SetBlackboard(gn.BB.HomePosition, {x:posx,y:posy});


        // native coms
        PawnCommon.AddCommonNativeComponents(inst, id, posx, posy);


        // js coms
        var sg = CreateCommonGraph(inst);
        var btree = CreateBTree_CommonSolider();
        PawnCommon.AddCommonJSComponents(inst,roleCfg,sg,btree);


        // events
        inst.ListenForEvent(gn.Event.Attacked,this.OnAttacked);


        // tag
        //inst.AddTag(gn.Tag.Soldier);
        inst.AddTag(tag);

        // end
        inst.OnAwake();
        return inst;
    }

}