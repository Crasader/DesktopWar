//士兵预制，配置了组件，资源，状态等

var Soldier = {

    Create:function()
    {
        var entity = CreateEntity()
        var entCpp = entity.GetEntity()
        //entity.LoadComponent("bev")
        var posCom = entCpp.AddComponent(ComponentName.Position)
        posCom.x = 100;
        posCom.y = 100;
        var velCom = entCpp.AddComponent(ComponentName.Velocity)
        velCom.x = 0;
        velCom.y = 0;


        //Role_cfg* roleInfo = FIND_CFG(Role_cfg, id);


        //Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
       // var agent = new ComPawnAgent();
        //agentCpp.Create(roleInfo);
        var agent = entCpp.AddComponent(ComponentName.PawnAgent)
        //var tm = new ComTeam();
        //tm->team = team;
        var tm = entCpp.AddComponent(ComponentName.Team)
       // var targ = new ComTarget();
        //targ->Create(Target_Entity);
        var targ = entCpp.AddComponent(ComponentName.Target)
        //var paCom = new ComPawnAnim();
        //paCom->Create(id);
        var paCom = entCpp.AddComponent(ComponentName.PawnAnim)
        var width = paCom.GetWidth()*0.5;
        var height = paCom.GetHeight()*0.7;
        //var box = new ComBoxCollider();
        //box->Create(false, 0, height*0.5f, width, height);
        var box = entCpp.AddComponent(ComponentName.BoxCollider)
        //var han = new ComColliderHandler();
       // han->Create(nullptr, nullptr);
        var han = entCpp.AddComponent(ComponentName.ColliderHandler)
        var dir = entCpp.AddComponent(ComponentName.PawnDirection)
        //var bev = new ComPawnBevtree();
        //bev->Create(roleInfo->bevTreeFile);
        var bev = entCpp.AddComponent(ComponentName.PawnBevtree)
        var nav = entCpp.AddComponent(ComponentName.PawnNavigation)
        var fht = entCpp.AddComponent(ComponentName.PawnFight)
        //if (cfg_EnableDebugDraw)
        //{
            //var dd = new ComPawnDebugDraw();
           // dd->Create();
            var dd = entCpp.AddComponent(ComponentName.PawnDebugDraw)
        //}


    },

    what:function(){}

}