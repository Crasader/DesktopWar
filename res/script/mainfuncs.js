
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
    if (tag == Tag.Monster) {
        Monster.Create(roleID, x, y);
    }
    else if (tag == Tag.Soldier) {
        Soldier.Create(roleID, x, y);
    }
}

function SpawnBullet(bulletID, targetEntityID, x, y, tag, destX, destY) {
    Bullet.Create(bulletID, targetEntityID, x, y, tag, destX, destY);
}


function GetPawnAnimName(entity, prefixAnimName) {
    var animName = PawnAnimName.Idle_L;
    var dir = entity.GetComponent(ComName.Transform).GetDir();
    var animCom = entity.GetComponent(ComName.PawnAnim);
    if (prefixAnimName === AnimName.Idle) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Idle_L;
        else
            animName = PawnAnimName.Idle_R;
    }
    else if (prefixAnimName === AnimName.Die) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Die_L;
        else
            animName = PawnAnimName.Die_R;
    }
    else if (prefixAnimName === AnimName.Move) {
        var needAdjust = false;

        if (dir == FaceDir.Left) {
            animName = PawnAnimName.Move_L;
        }
        else if (dir == FaceDir.Right) {
            animName = PawnAnimName.Move_R;
        }
        else if (dir == FaceDir.Up) {
            if (animCom.ContainAnim(PawnAnimName.Move_Up))
                animName = PawnAnimName.Move_Up;
            else
                needAdjust = true;
        }
        else if (dir == FaceDir.Down) {
            if (animCom.ContainAnim(PawnAnimName.Move_Down))
                animName = PawnAnimName.Move_Down;
            else
                needAdjust = true;
        }
        else if (dir & FaceDir.Up) {
            if (animCom.ContainAnim(PawnAnimName.Move_Up))
                animName = PawnAnimName.Move_Up;
            else {
                if (dir & FaceDir.Left)
                    animName = PawnAnimName.Move_L;
                else
                    animName = PawnAnimName.Move_R;
            }
        }
        else if (dir & FaceDir.Down) {
            if (animCom.ContainAnim(PawnAnimName.Move_Down))
                animName = PawnAnimName.Move_Down;
            else {
                if (dir & FaceDir.Right)
                    animName = PawnAnimName.Move_R;
                else
                    animName = PawnAnimName.Move_L;
            }
        }
        // default...
        if (needAdjust) {
            if (dir & FaceDir.Left)
                animName = PawnAnimName.Move_L;
            else
                animName = PawnAnimName.Move_R;
        }
    }
    else if (prefixAnimName === AnimName.Atk1) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Attack1_L;
        else
            animName = PawnAnimName.Attack1_R;
    }
    else if (prefixAnimName === AnimName.Atk2) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Attack2_L;
        else
            animName = PawnAnimName.Attack2_R;
    }
    else if (prefixAnimName === AnimName.Atk3) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Attack3_L;
        else
            animName = PawnAnimName.Attack3_R;
    }
    else if (prefixAnimName === AnimName.Skill1) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Skill1_L;
        else
            animName = PawnAnimName.Skill1_R;
    }
    else if (prefixAnimName === AnimName.Skill2) {
        if (dir & FaceDir.Left)
            animName = PawnAnimName.Skill2_L;
        else
            animName = PawnAnimName.Skill2_R;
    }
    else if (prefixAnimName === AnimName.Skill3) {
        if (dir & FaceDir.Left)
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
        entity.GetComponent(ComName.PawnAnim).PlayAnimation(fullName);
        print("play "+fullName);
    }
}





