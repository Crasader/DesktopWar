//怪物预制，配置了组件，资源，状态等

var Monster = {

    Create:function(id, posx, posy)
    {
        //print("Soldier Create at " + posx + "," + posy);

        var inst = CreateEntity();
        var entCpp = inst.GetEntityNative();


        var posCom = entCpp.AddComponent(ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

		var roleCfg = Config.Role[id];

        var agent = entCpp.AddComponent(ComName.PawnAgent);
		agent.Create(id,true);

        entCpp.AddComponent(ComName.Render);

        var paCom = entCpp.AddComponent(ComName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = entCpp.AddComponent(ComName.BoxCollider);
        box.Create(true, 0, height*0.5, width, height);

        var bev = entCpp.AddComponent(ComName.PawnBevtree);
        bev.Create(roleCfg.bevTreeFile);

        var nav = entCpp.AddComponent(ComName.PawnNavigation);
        var fht = entCpp.AddComponent(ComName.PawnFight);

        //var dd = entCpp.AddComponent(ComName.PawnDebugDraw);
        //dd.Create();


        // js coms
        var brain = inst.AddComponent(new Brain);
        brain.SetBTree(SimplePawnBT);

        var combat = inst.AddComponent(new Combat);

        var attr = inst.AddComponent(new Attr);


        entCpp.AddTag(Tag.Monster);

        return inst;
    },

    lastfn:function(){}

}