
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

        var agent = inst.AddComponent(ComName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = inst.AddComponent(ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        var box = inst.AddComponent(ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);

        inst.AddComponent(ComName.Render);

        var damage = inst.AddComponent(ComName.BulletDamage);


        if (bulletCfg.moveType == BulletMoveType.Line)
        {
            posCom.SetVelocity(0, 0);

            var baegg = inst.AddComponent(ComName.BulletAnimEgg);
            baegg.Create(anim_cfg.name);
        }
        else if (bulletCfg.moveType == BulletMoveType.Bezier)
        {
            posCom.SetVelocity(0, 0);

            inst.AddComponent(ComName.Direction);

            var bez = inst.AddComponent(ComName.BezierMovement);
            bez.Create(posx, posy, destX, destY, (abs(posx - destX) + abs(posy - destY)) / bulletCfg.flySpeed);

            damage.SetTargetID(targetId);

            var banim = inst.AddComponent(ComName.BulletAnimArrow);
            banim.Create(anim_cfg.name);

            agent.GetBlackboard().SetTargetType(TargetType.Location);
            agent.GetBlackboard().SetTargetX(destX);
            agent.GetBlackboard().SetTargetY(destY);

        }
        else if(bulletCfg.moveType == BulletMoveType.Tracking)
        {
            inst.AddComponent(ComName.Direction);

            posCom.SetVelocity(0, bulletCfg.flySpeed);

            var delayTrack = inst.AddComponent(ComName.DelayTrackMovement);
            delayTrack.Create(targetId, bulletCfg.findTargetDelay);

            var bom = inst.AddComponent(ComName.BulletAnimBomb);
            bom.Create(anim_cfg.name, bulletCfg.tailAnim);

            agent.GetBlackboard().SetTargetType(TargetType.Entity);
            agent.GetBlackboard().SetTargetID(targetId);
        }

        if(Setting.DebugDraw){
            inst.AddComponent(ComName.BulletDebugDraw);
        }

        // js coms

        inst.AddTag(tag);
        // end
        inst.OnAwake();
        return inst;
    }


};