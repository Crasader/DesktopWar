
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
    var animName = PawnAnimName.Idle_L;
    var dir = entity.GetComponent(gn.ComName.Transform).GetDir();
    var animCom = entity.GetComponent(gn.ComName.PawnAnim);
    if (prefixAnimName === gn.AnimName.Idle) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Idle_L;
        else
            animName = PawnAnimName.Idle_R;
    }
    else if (prefixAnimName === gn.AnimName.Die) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Die_L;
        else
            animName = PawnAnimName.Die_R;
    }
    else if (prefixAnimName === gn.AnimName.Move) {
        var needAdjust = false;

        if (dir == gn.FaceDir.Left) {
            animName = PawnAnimName.Move_L;
        }
        else if (dir == gn.FaceDir.Right) {
            animName = PawnAnimName.Move_R;
        }
        else if (dir == gn.FaceDir.Up) {
            if (animCom.ContainAnim(PawnAnimName.Move_Up))
                animName = PawnAnimName.Move_Up;
            else
                needAdjust = true;
        }
        else if (dir == gn.FaceDir.Down) {
            if (animCom.ContainAnim(PawnAnimName.Move_Down))
                animName = PawnAnimName.Move_Down;
            else
                needAdjust = true;
        }
        else if (dir & gn.FaceDir.Up) {
            if (animCom.ContainAnim(PawnAnimName.Move_Up))
                animName = PawnAnimName.Move_Up;
            else {
                if (dir & gn.FaceDir.Left)
                    animName = PawnAnimName.Move_L;
                else
                    animName = PawnAnimName.Move_R;
            }
        }
        else if (dir & gn.FaceDir.Down) {
            if (animCom.ContainAnim(PawnAnimName.Move_Down))
                animName = PawnAnimName.Move_Down;
            else {
                if (dir & gn.FaceDir.Right)
                    animName = PawnAnimName.Move_R;
                else
                    animName = PawnAnimName.Move_L;
            }
        }
        // default...
        if (needAdjust) {
            if (dir & gn.FaceDir.Left)
                animName = PawnAnimName.Move_L;
            else
                animName = PawnAnimName.Move_R;
        }
    }
    else if (prefixAnimName === gn.AnimName.Atk1) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Attack1_L;
        else
            animName = PawnAnimName.Attack1_R;
    }
    else if (prefixAnimName === gn.AnimName.Atk2) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Attack2_L;
        else
            animName = PawnAnimName.Attack2_R;
    }
    else if (prefixAnimName === gn.AnimName.Atk3) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Attack3_L;
        else
            animName = PawnAnimName.Attack3_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill1) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Skill1_L;
        else
            animName = PawnAnimName.Skill1_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill2) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Skill2_L;
        else
            animName = PawnAnimName.Skill2_R;
    }
    else if (prefixAnimName === gn.AnimName.Skill3) {
        if (dir & gn.FaceDir.Left)
            animName = PawnAnimName.Skill3_L;
        else
            animName = PawnAnimName.Skill3_R;
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

    }else if(event === 'attack2'){

    }else if(event === 'attack3'){

    }else if(event === 'skill1'){

    }else if(event === 'skill1'){

    }else if(event === 'skill2'){

    }else if(event === 'skill3'){

    }
}

function HandleArmatureMovementEvent(entity, movement, animName){
    if(movement === 0){

    }else if(movement === 0){

    }else if(movement === 0){

    }
}





