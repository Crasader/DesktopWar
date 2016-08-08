
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

function Random(a,b)
{
    if(typeof(a)==='Number' && typeof(b)==='Number'){
        return a + Math.random()*(b-a);
    }
    else
    {
        print('Random:params must be type of Number.')
    }

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
        //print("play "+fullName);
    }
}


function IsEntityInRange(entity1, entity2, dist){
    var box1 = entity1.GetComponent(ComName.BoxCollider);
    var box2 = entity2.GetComponent(ComName.BoxCollider);
    var tran1 = entity1.GetComponent(ComName.Transform);
    var tran2 = entity1.GetComponent(ComName.Transform);
    var distx = Math.abs(tran1.GetX() - tran2.GetX());
    var disty = Math.abs(tran1.GetY() - tran2.GetY());
    var width = box1.GetWidth()*0.5 + box2.GetWidth()*0.5;
    var height = width*0.5;
    return distx - width < dist && disty - height < dist;
}


