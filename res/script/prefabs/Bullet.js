
//子弹

var Bullet = {

    Create:function(bulletId, targetId, posx, posy, tag, destX, destY)
    {
        var bulletCfg = Config.Bullet[bulletId];
        if (null == bulletCfg)
        {
            print("wrong bullet id " + bulletId);
        }

        var anim_cfg = Config.Animation[bulletCfg.bodyAnim];

        var inst = Game.CreateEntity();

        inst.SetBlackboard('bulletCfg', bulletCfg);

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);

        inst.AddComponent(gn.ComName.Render);

        var damage = inst.AddComponent(gn.ComName.BulletDamage);


        if (bulletCfg.moveType == gn.BulletMoveType.Line)
        {
            posCom.SetVelocity(0, 0);

            var baegg = inst.AddComponent(gn.ComName.BulletAnimEgg);
            baegg.Create(anim_cfg.name);
        }
        else if (bulletCfg.moveType == gn.BulletMoveType.Bezier)
        {
            posCom.SetVelocity(0, 0);

            inst.AddComponent(gn.ComName.Direction);

            var bez = inst.AddComponent(gn.ComName.BezierMovement);
            bez.Create(posx, posy, destX, destY, (Math.abs(posx - destX) + Math.abs(posy - destY)) / bulletCfg.flySpeed);

            damage.SetTargetID(targetId);

            var banim = inst.AddComponent(gn.ComName.BulletAnimArrow);
            banim.Create(anim_cfg.name);

            agent.GetBlackboard().SetTargetType(gn.TargetType.Location);
            agent.GetBlackboard().SetTargetX(destX);
            agent.GetBlackboard().SetTargetY(destY);

        }
        else if(bulletCfg.moveType == gn.BulletMoveType.Tracking)
        {
            inst.AddComponent(gn.ComName.Direction);

            posCom.SetVelocity(0, bulletCfg.flySpeed);

            var delayTrack = inst.AddComponent(gn.ComName.DelayTrackMovement);
            delayTrack.Create(targetId, bulletCfg.findTargetDelay);

            var bom = inst.AddComponent(gn.ComName.BulletAnimBomb);
            bom.Create(anim_cfg.name, bulletCfg.tailAnim);

            agent.GetBlackboard().SetTargetType(gn.TargetType.Entity);
            agent.GetBlackboard().SetTargetID(targetId);
        }

        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.BulletDebugDraw);
        }

        // js coms

        inst.AddTag(tag);
        // end
        inst.OnAwake();
        return inst;
    }


};