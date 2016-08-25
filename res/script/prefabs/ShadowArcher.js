

//暗影射手

var ShadowArcher = {

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
        var btree = CreateBTree_Archer();
        PawnCommon.AddCommonJSComponents(inst,roleCfg,sg,btree);


        // tag
        //inst.AddTag(gn.Tag.Monster);
        inst.AddTag(tag);

        // end
        inst.OnAwake();
        return inst;
    }



}