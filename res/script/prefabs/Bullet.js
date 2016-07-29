
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
        var entCpp = inst.GetEntityNative();

        var agent = entCpp.AddComponent(ComName.PawnAgent);
        agent.Create(bulletId,false);

        var posCom = entCpp.AddComponent(ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);

        var box = entCpp.AddComponent(ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);

        entCpp.AddComponent(ComName.Render);

        var damage = entCpp.AddComponent(ComName.BulletDamage);

        //var dd = entCpp.AddComponent(ComName.BulletDebugDraw);


        if (bulletCfg.moveType == BulletMoveType.Line)
        {
            posCom.SetVelocity(0, 0);

            var baegg = entCpp.AddComponent(ComName.BulletAnimEgg);
            baegg.Create(anim_cfg.name);
        }
        else if (bulletCfg.moveType == BulletMoveType.Bezier)
        {
            posCom.SetVelocity(0, 0);

            entCpp.AddComponent(ComName.Direction);

            var bez = entCpp.AddComponent(ComName.BezierMovement);
            bez.Create(posx, posy, destX, destY, (abs(posx - destX) + abs(posy - destY)) / bulletCfg.flySpeed);

            damage.SetTargetID(targetId);

            var banim = entCpp.AddComponent(ComName.BulletAnimArrow);
            banim.Create(anim_cfg.name);

            agent.GetBlackboard().SetTargetType(TargetType.Location);
            agent.GetBlackboard().SetTargetX(destX);
            agent.GetBlackboard().SetTargetY(destY);

        }
        else if(bulletCfg.moveType == BulletMoveType.Tracking)
        {
            entCpp.AddComponent(ComName.Direction);

            posCom.SetVelocity(0, bulletCfg.flySpeed);

            var delayTrack = entCpp.AddComponent(ComName.DelayTrackMovement);
            delayTrack.Create(targetId, bulletCfg.findTargetDelay);

            var bom = entCpp.AddComponent(ComName.BulletAnimBomb);
            bom.Create(anim_cfg.name, bulletCfg.tailAnim);

            agent.GetBlackboard().SetTargetType(TargetType.Entity);
            agent.GetBlackboard().SetTargetID(targetId);
        }

        entCpp.AddTag(tag);

        return inst;
    },

    lastfn:function(){}

};