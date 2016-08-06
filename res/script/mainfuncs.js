
//
//????
//


function print(text)
{
    Log.print(text)
}

function ForceGC()
{
    forceGC()
}

function GetWorld()
{
    return World.GetWorld()
}

function SpawnPawn(roleID, x, y, tag)
{
    if (tag == Tag.Monster)
    {
        Monster.Create(roleID, x, y);
    }
    else if(tag == Tag.Soldier)
    {
        Soldier.Create(roleID, x, y);
    }
}

function SpawnBullet(bulletID, targetEntityID, x, y, tag, destX, destY)
{
    Bullet.Create(bulletID, targetEntityID, x, y, tag, destX, destY);
}


function GetPawnAnimName(entity, prefixAnimName) {
    var animName = PawnAnimName.Idle_L;
    var dir = entity.GetComponent(ComName.Transform).GetDir();
    print('dir is '+dir);
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
        // 没有对应动画，也没播放替代动作。
        if (needAdjust) {
            if (dir & FaceDir.Left)
                animName = PawnAnimName.Move_L;
            else
                animName = PawnAnimName.Move_R;
        }
    }
    return animName;
}

function PlayPawnAnim(entity, prefixName){
    if(entity instanceof EntityScript) {
        var fullName = GetPawnAnimName(entity, prefixName);
        entity.GetComponent(ComName.PawnAnim).PlayAnimation(fullName);
        print("play "+fullName);
    }
}