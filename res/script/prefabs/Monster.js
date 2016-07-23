//怪物预制，配置了组件，资源，状态等

var Monster = {

    Create:function(id, posx, posy, team)
    {
        //print("Soldier Create at " + posx + "," + posy);
        var inst = CreateEntity();
        var entCpp = inst.GetEntity();
        //inst.LoadComponent("bev");
        var posCom = entCpp.AddComponent(ComponentName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

		var roleCfg = Config.Role[id];

        var agent = entCpp.AddComponent(ComponentName.PawnAgent);
		agent.Create(id,true);

        entCpp.AddComponent(ComponentName.Render);

        //var targ = entCpp.AddComponent(ComponentName.Target);
        //targ.Create(0,0,0,0);

        var paCom = entCpp.AddComponent(ComponentName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = entCpp.AddComponent(ComponentName.BoxCollider);
        box.Create(false, 0, height*0.5, width, height);

       // var han = entCpp.AddComponent(ComponentName.ColliderHandler);
        //han.Create(null, null);

        //var dir = entCpp.AddComponent(ComponentName.PawnDirection);

        var bev = entCpp.AddComponent(ComponentName.PawnBevtree);
        bev.Create(roleCfg.bevTreeFile);

        var nav = entCpp.AddComponent(ComponentName.PawnNavigation);
        var fht = entCpp.AddComponent(ComponentName.PawnFight);

        //var dd = entCpp.AddComponent(ComponentName.PawnDebugDraw);
        //dd.Create();

        entCpp.AddTag(Defines.Tag_Monster);

        return inst;
    },

    lastfn:function(){}

}