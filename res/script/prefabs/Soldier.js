//士兵预制，配置了组件，资源，状态等

var Soldier = {

    Create:function(id, posx, posy)
    {
        //print("Soldier Create at " + posx + "," + posy);

        var inst = CreateEntity();
        var entCpp = inst.GetEntityNative();

        inst.AddComponent(Brain);

        var posCom = entCpp.AddComponent(ComponentName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

		var roleCfg = Config.Role[id];

        var agent = entCpp.AddComponent(ComponentName.PawnAgent);
		agent.Create(id,true);

        entCpp.AddComponent(ComponentName.Render);

        var paCom = entCpp.AddComponent(ComponentName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = entCpp.AddComponent(ComponentName.BoxCollider);
        box.Create(true, 0, height*0.5, width, height);

        var bev = entCpp.AddComponent(ComponentName.PawnBevtree);
        bev.Create(roleCfg.bevTreeFile);

        var nav = entCpp.AddComponent(ComponentName.PawnNavigation);
        var fht = entCpp.AddComponent(ComponentName.PawnFight);

        //var dd = entCpp.AddComponent(ComponentName.PawnDebugDraw);
        //dd.Create();

        entCpp.AddTag(Tag.Soldier)

        return inst;
    },

    lastfn:function(){}

}