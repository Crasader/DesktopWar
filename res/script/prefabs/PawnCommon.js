

var PawnCommon = {

    // 添加士兵/怪物通用native组件
    AddCommonNativeComponents:function(inst,id,posx,posy){
        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        inst.AddComponent(gn.ComName.Render);

        var paCom = inst.AddComponent(gn.ComName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(true, 0, height*0.5, width, height);

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(id,true);


        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.PawnDebugDraw);
        }
    },

    // 添加士兵/怪物通用js组件
    AddCommonJSComponents:function(inst,roleCfg,sg,btree){
        var attr = inst.AddComponent(new Attr);
        attr.InitWithRoleCfg(roleCfg);
        inst.AddComponent(new Locomotor);
        inst.SetStateGraph(sg);
        var brain = inst.AddComponent(new Brain(btree));
        BrainMgr.AddBrain(inst, brain);
        inst.AddComponent(new Combat);
    },


};