

var Monster = {

    Create:function(id, posx, posy)
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
        var btree = CreateFootManBTree();
        PawnCommon.AddCommonJSComponents(inst,roleCfg,sg,btree);


        // tag
        inst.AddTag(gn.Tag.Monster);


        // end
        inst.OnAwake();
        return inst;
    }



}