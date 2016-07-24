
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

        var inst = CreateEntity();
        var entCpp = inst.GetEntity();

        var agent = entCpp.AddComponent(ComponentName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = entCpp.AddComponent(ComponentName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        var box = entCpp.AddComponent(ComponentName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);

        entCpp.AddComponent(ComponentName.Render);

        var damage = entCpp.AddComponent(ComponentName.BulletDamage);

        //var dd = entCpp.AddComponent(ComponentName.BulletDebugDraw);


        if (bulletCfg.moveType == BulletMoveType.Line)
        {
            posCom.SetVelocity(0, 0);

            var baegg = entCpp.AddComponent(ComponentName.BulletAnimEgg);
            baegg.Create(anim_cfg.name);
        }
        else if (bulletCfg.moveType == BulletMoveType.Bezier)
        {
            posCom.SetVelocity(0, 0);

            entCpp.AddComponent(ComponentName.Direction);

            var bez = entCpp.AddComponent(ComponentName.BezierMovement);
            bez.Create(posx, posy, destX, destY, (abs(posx - destX) + abs(posy - destY)) / bulletCfg.flySpeed);

            damage.SetTargetID(targetId);

            var banim = entCpp.AddComponent(ComponentName.BulletAnimArrow);
            banim.Create(anim_cfg.name);

            agent.GetBlackboard().SetTargetType(TargetType.Location);
            agent.GetBlackboard().SetTargetX(destX);
            agent.GetBlackboard().SetTargetY(destY);

        }
        else if(bulletCfg.moveType == BulletMoveType.Tracking)
        {
            entCpp.AddComponent(ComponentName.Direction);

            posCom.SetVelocity(0, bulletCfg.flySpeed);

            var delayTrack = entCpp.AddComponent(ComponentName.DelayTrackMovement);
            delayTrack.Create(targetId, bulletCfg.findTargetDelay);

            var bom = entCpp.AddComponent(ComponentName.BulletAnimBomb);
            bom.Create(anim_cfg.name, bulletCfg.tailAnim);

            agent.GetBlackboard().SetTargetType(TargetType.Entity);
            agent.GetBlackboard().SetTargetID(targetId);
        }

        entCpp.AddTag(tag);

        return inst;
    },

    lastfn:function(){}

};