//怪物预制，配置了组件，资源，状态等

var Monster = {

    Create:function(id, posx, posy)
    {
        //print("Soldier Create at " + posx + "," + posy);

        var inst = Game.CreateEntity();

        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

		var roleCfg = Config.Role[id];

        inst.SetBlackboard(gn.BB.RoleCfg, roleCfg);
        inst.SetBlackboard(gn.BB.HomePosition, {x:posx,y:posy});

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
		agent.Create(id,true);

        inst.AddComponent(gn.ComName.Render);

        var paCom = inst.AddComponent(gn.ComName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(true, 0, height*0.5, width, height);

        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.PawnDebugDraw);
        }


        // js coms
        inst.AddComponent(new Locomotor);
        var SimplePawnBT = CreateFootManBTree();
        var brain = inst.AddComponent(new Brain(SimplePawnBT));
        BrainMgr.AddBrain(inst, brain);
        inst.AddComponent(new Combat);
        var attr = inst.AddComponent(new Attr);
        attr.InitWithRoleCfg(roleCfg);


        inst.SetStateGraph(CreateCommonGraph(inst));


        inst.AddTag(gn.Tag.Monster);

        inst.OnAwake();

        return inst;
    }



}