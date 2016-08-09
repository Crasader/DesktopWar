



var Soldier = {

    OnAttacked:function(entity,attacker){
        entity.SetBlackboard(BB.CombatTarget,attacker);
    },


    Create:function(id, posx, posy)
    {
        "use strict";

        //print("Soldier Create at " + posx + "," + posy);

        var inst = Game.CreateEntity();

        var posCom = inst.AddComponent(ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

		var roleCfg = Config.Role[id];

        inst.SetBlackboard(BB.RoleCfg, roleCfg);
        inst.SetBlackboard(BB.HomePosition, {x:posx,y:posy});

        var agent = inst.AddComponent(ComName.PawnAgent);
		agent.Create(id,true);

        inst.AddComponent(ComName.Render);

        var paCom = inst.AddComponent(ComName.PawnAnim);
        paCom.Create(id);
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;

        var box = inst.AddComponent(ComName.BoxCollider);
        box.Create(true, 0, height*0.5, width, height);

        var nav = inst.AddComponent(ComName.PawnNavigation);
        var fht = inst.AddComponent(ComName.PawnFight);

        if(Setting.DebugDraw){
            inst.AddComponent(ComName.PawnDebugDraw);
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

        // events
        inst.ListenForEvent('attacked',this.OnAttacked);

        // tag
        inst.AddTag(Tag.Soldier);
        // end
        inst.OnAwake();
        return inst;
    }

}