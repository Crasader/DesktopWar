
//
//????
//
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


