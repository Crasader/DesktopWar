
//
//全局重要函数，如各种创建entity
//
//


function print(text)
{
    Log.print(text)
}

function LoadScript(filePath)
{
    require(filePath)
}


function RunScript(filePath)
{
    require(filePath)
}


function ForceGC()
{
    forceGC()
}

function GetWorld()
{
    return World.GetWorld()
}


var Entities = {}
function CreateEntity()
{
    var entCpp = GetWorld().CreateEntity()
    var ent = new EntityScript()
    ent.SetEntity(entCpp)
    var guid = entCpp.GetID()
    Entities[guid] = ent

    return ent
}


/*function SpawnPrefab(name)
{
    var so = new Soldier()
    so.fn()
}*/

function abs(value)
{
    var newValue = value;
    if (value < 0)
    {
        newValue = -value;
    }
    return newValue;
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


