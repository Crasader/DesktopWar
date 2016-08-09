
//
//????
//


function print(text) {
    Log.print(text);
}

function ForceGC() {
    forceGC();
}

function Random(a,b) {
    return a + Math.random() * (b - a);
}

function GetWorld() {
    return World.GetWorld()
}

function SpawnPawn(roleID, x, y, tag) {
    if (tag == gn.Tag.Monster) {
        Monster.Create(roleID, x, y);
    }
    else if (tag == gn.Tag.Soldier) {
        Soldier.Create(roleID, x, y);
    }
}

function SpawnBullet(bulletID, targetEntityID, x, y, tag, destX, destY) {
    Bullet.Create(bulletID, targetEntityID, x, y, tag, destX, destY);
}


function GetPawnAnimName(entity, prefixAnimName) {
    var animName = gn.PawnAnimName.Idle_L;
    var dir = entity.GetComponent(gn.ComName.Transform).GetDir();
    var animCom = entity.GetComponent(gn.ComName.PawnAnim);
    if (prefixAnimName === gn.AnimName.Idle) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Idle_L;
        else
            animName = gn.PawnAnimName.Idle_R;
    }
    else if (prefixAnimName === gn.AnimName.Die) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Die_L;
        else
            animName = gn.PawnAnimName.Die_R;
    }
    else if (prefixAnimName === gn.AnimName.Move) {
        var needAdjust = false;

        if (dir == gn.FaceDir.Left) {
            animName = gn.PawnAnimName.Move_L;
        }
        else if (dir == gn.FaceDir.Right) {
            animName = gn.PawnAnimName.Move_R;
        }
        else if (dir == gn.FaceDir.Up) {
            if (animCom.ContainAnim(gn.PawnAnimName.Move_Up))
                animName = gn.PawnAnimName.Move_Up;
            else
                needAdjust = true;
        }
        else if (dir == gn.FaceDir.Down) {
            if (animCom.ContainAnim(gn.PawnAnimName.Move_Down))
                animName = gn.PawnAnimName.Move_Down;
            else
                needAdjust = true;
        }
        else if (dir & gn.FaceDir.Up) {
            if (animCom.ContainAnim(gn.PawnAnimName.Move_Up))
                animName = gn.PawnAnimName.Move_Up;
            else {
                if (dir & gn.FaceDir.Left)
                    animName = gn.PawnAnimName.Move_L;
                else
                    animName = gn.PawnAnimName.Move_R;
            }
        }
        else if (dir & gn.FaceDir.Down) {
            if (animCom.ContainAnim(gn.PawnAnimName.Move_Down))
                animName = gn.PawnAnimName.Move_Down;
            else {
                if (dir & gn.FaceDir.Right)
                    animName = gn.PawnAnimName.Move_R;
                else
                    animName = gn.PawnAnimName.Move_L;
            }
        }
        // default...
        if (needAdjust) {
            if (dir & gn.FaceDir.Left)
                animName = gn.PawnAnimName.Move_L;
            else
                animName = gn.PawnAnimName.Move_R;
        }
    }
    else if (prefixAnimName === gn.AnimName.Atk1) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Attack1_L;
        else
            animName = gn.PawnAnimName.Attack1_R;
    }
    else if (prefixAnimName === gn.AnimName.Atk2) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Attack2_L;
        else
            animName = gn.PawnAnimName.Attack2_R;
    }
    else if (prefixAnimName === gn.AnimName.Atk3) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Attack3_L;
        else
            animName = gn.PawnAnimName.Attack3_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill1) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Skill1_L;
        else
            animName = gn.PawnAnimName.Skill1_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill2) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Skill2_L;
        else
            animName = gn.PawnAnimName.Skill2_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill3) {
        if (dir & gn.FaceDir.Left)
            animName = gn.PawnAnimName.Skill3_L;
        else
            animName = gn.PawnAnimName.Skill3_R;
    }
    return animName;
}

function PlayPawnAnim(entity, prefixName){
    if(entity instanceof EntityScript) {
        var fullName = GetPawnAnimName(entity, prefixName);
        entity.GetStateGraph().SetAnimPrefixName(prefixName);
        entity.GetComponent(gn.ComName.PawnAnim).PlayAnimation(fullName);
        print("play "+fullName);
    }
}



function HandleArmatureFrameEvent(entity, event){
    if(event === 'attack'){
        entity.PushEvent(gn.Event.FrameAttack1);
    }else if(event === 'attack2'){
        entity.PushEvent(gn.Event.FrameAttack2);
    }else if(event === 'attack3'){
        entity.PushEvent(gn.Event.FrameAttack3);
    }else if(event === 'skill1'){
        entity.PushEvent(gn.Event.FrameSkill1);
    }else if(event === 'skill1'){
        entity.PushEvent(gn.Event.FrameSkill2);
    }else if(event === 'skill2'){
        entity.PushEvent(gn.Event.FrameSkill3);
    }else if(event === 'skill3'){

    }
}

function HandleArmatureMovementEvent(entity, movement, animName){
    var START = 0;
    var COMPLETE = 1;
    var LOOP_COMPLETE = 2;
    if(movement === START){

    }else if(movement === COMPLETE){

    }else if(movement === LOOP_COMPLETE){

    }
}


function ModifyEntityAttr(entity, calType, attrType, value, atkType){
    //
    var attrCom = entity.GetComponent(gn.ComName.Attr);
    if(calType == gn.CalcType.Fixed){
        attrCom.Mod(attrType, value);
    }
    else if(calType == gn.CalcType.Percent){
        var cur = attrCom.Get(attrType);
        var newValue = cur * value * 0.01;
        attrCom.Mod(attrType, newValue);
    }
    else if(calType == gn.CalcType.NPC || calType == gn.CalcType.Bullet){
        var role_cfg = entity.GetBlackboard(gn.BB.RoleCfg);
        var realDecLife = 0;
        if(atkType == gn.HurtType.Physics)
            realDecLife = value * (1.0 - role_cfg.antiPhysicValue*0.01);
        else if(atkType == gn.HurtType.Magic)
            realDecLife = value * (1.0 - role_cfg.antiMagicValue*0.01);
        if(realDecLife<=0)
            realDecLife=1;
        attrCom.Mod(gn.Attr.HP, realDecLife);
    }
    else{
        print('ModifyEntityAttr:invaild param.');
    }
}





