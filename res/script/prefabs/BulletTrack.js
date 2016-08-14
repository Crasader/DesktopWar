
//自主追踪类型子弹

var BulletTrack = {

    OnHit:function(bullet, entity){
        // bullet stop explode, entity damage
    },

    OnArrived:function(entity){
        // stop
    },

    Create:function(bulletId, targetId, posx, posy, tag, destX, destY)
    {
        "use strict";

        var inst = Game.CreateEntity();
        var bulletCfg = Config.Bullet[bulletId];
        var anim_cfg = Config.Animation[bulletCfg.bodyAnim];
        inst.SetBlackboard(gn.BB.BulletCfg, bulletCfg);


        // native coms
        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(bulletId,false);
        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);
        inst.AddComponent(gn.ComName.Render);
        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.BulletDebugDraw);
        }

        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);
        inst.AddComponent(gn.ComName.BulletDamage);
        inst.AddComponent(gn.ComName.Direction);

        posCom.SetVelocity(0, bulletCfg.flySpeed);

        inst.AddComponent(gn.ComName.DelayTrackMovement);

        var bom = inst.AddComponent(gn.ComName.BulletAnimBomb);
        bom.Create(anim_cfg.name, bulletCfg.tailAnim);



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