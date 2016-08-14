
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
        "use strict";

        var inst = Game.CreateEntity();
        var bulletCfg = Config.Bullet[bulletId];
        var anim_cfg = Config.Animation[bulletCfg.bodyAnim];
        inst.SetBlackboard(gn.BB.BulletCfg, bulletCfg);

        var agent = inst.AddComponent(gn.ComName.PawnAgent);
        agent.Create(bulletId,false);
        var posCom = inst.AddComponent(gn.ComName.Transform);
        posCom.SetPosition(posx, posy);
        posCom.SetVelocity(0, 0);
        inst.AddComponent(gn.ComName.Render);
        var box = inst.AddComponent(gn.ComName.BoxCollider);
        box.Create(false, 0, 0, bulletCfg.boxWidth, bulletCfg.boxHeight);
        if(gn.Setting.DebugDraw){
            inst.AddComponent(gn.ComName.BulletDebugDraw);
        }


        inst.AddComponent(gn.ComName.BulletDamage);
        inst.AddComponent(gn.ComName.Direction);
        var banim = inst.AddComponent(gn.ComName.BulletAnimArrow);
        banim.Create(anim_cfg.name);
        var bez = inst.AddComponent(gn.ComName.BezierMovement);
        bez.Create(posx, posy, destX, destY, (Math.abs(posx - destX) + Math.abs(posy - destY)) / bulletCfg.flySpeed);


        // js coms


        // events
        inst.ListenForEvent(gn.Event.Arrived,this.OnArrived);
        inst.ListenForEvent(gn.Event.Hit,this.OnHit);


        // tag
        inst.AddTag(tag);


        // end
        inst.OnAwake();
        return inst;
    }


};