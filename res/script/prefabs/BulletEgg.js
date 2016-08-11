
//召唤类型子弹，比如蜘蛛卵。

var BulletEgg = {

    // 动画帧事件（buff）
    OnFrameTriggered:function(entity){
        var bulletInfo = entity.GetBlackboard(gn.BB.BulletCfg);
        for (var i = 0; i < 3; ++i)
        {
            if (bulletInfo.buffs[i] != 0)
                BuffMgr.AddBuff(entity.GetID(), gn.InvalidEntityID, bulletInfo.buffs[i]);
        }
    },

    OnAnimComplete:function(entity){
        Game.DestroyEntity(entity);
    },

    Create:function(bulletId, posx, posy, tag)
    {
        var bulletCfg = Config.Bullet[bulletId];
        var anim_cfg = Config.Animation[bulletCfg.bodyAnim];

        var inst = Game.CreateEntity();

        inst.SetBlackboard(gn.BB.BulletCfg, bulletCfg);

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        inst.AddComponent(gn.ComName.Render);

        var baegg = inst.AddComponent(gn.ComName.BulletAnimEgg);
        baegg.Create(anim_cfg.name);

        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.BulletDebugDraw);
        }

        // js coms


        // events
        inst.ListenForEvent(gn.Event.BulletTriggered,this.OnFrameTriggered);
        inst.ListenForEvent(gn.Event.AnimComplete,this.OnAnimComplete);
        inst.ListenForEvent(gn.Event.AnimLoopComplete,this.OnAnimComplete);


        // end
        inst.AddTag(tag);
        inst.OnAwake();
        return inst;
    }


};