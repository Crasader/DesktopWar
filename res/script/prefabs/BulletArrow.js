
//投射类型子弹，比如箭。

var BulletArrow = {

    OnHit:function(bullet, entity){
        // bullet stop explode, entity damage
    },

    OnArrived:function(entity){
        // stop
    },

    Create:function(bulletId, targetId, posx, posy, tag, destX, destY)
    {
        var bulletCfg = Config.Bullet[bulletId];
        if (null == bulletCfg)
        {
            print("wrong bullet id " + bulletId);
        }

        var anim_cfg = Config.Animation[bulletCfg.bodyAnim];

        var inst = Game.CreateEntity();

        inst.SetBlackboard(gn.BB.BulletCfg, bulletCfg);

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);

        inst.AddComponent(gn.ComName.Render);

        var damage = inst.AddComponent(gn.ComName.BulletDamage);


        posCom.SetVelocity(0, 0);

        inst.AddComponent(gn.ComName.Direction);

        var bez = inst.AddComponent(gn.ComName.BezierMovement);
        bez.Create(posx, posy, destX, destY, (Math.abs(posx - destX) + Math.abs(posy - destY)) / bulletCfg.flySpeed);

        damage.SetTargetID(targetId);

        var banim = inst.AddComponent(gn.ComName.BulletAnimArrow);
        banim.Create(anim_cfg.name);

        //agent.GetBlackboard().SetTargetType(gn.TargetType.Location);
        //agent.GetBlackboard().SetTargetX(destX);
        //agent.GetBlackboard().SetTargetY(destY);




        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.BulletDebugDraw);
        }

        // js coms


        // events
        inst.ListenForEvent(gn.Event.Arrived,this.OnArrived);
        inst.ListenForEvent(gn.Event.Hit,this.OnHit);


        inst.AddTag(tag);
        // end
        inst.OnAwake();
        return inst;
    }


};