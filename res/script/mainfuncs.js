
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


var gEntities = {}
function CreateEntity()
{
    var entNative = GetWorld().CreateEntity();
    var ent = new EntityScript();
    ent.SetEntityNative(entNative);
    var guid = entNative.GetID();
    gEntities[guid] = ent;

    return ent;
}

function DestroyEntity(entity)
{
    if (null == entity)
        return;

    GetWorld().DestroyEntity(entity.GetEntityNative())

    for(var id in gEntities)
    {
        if(gEntities[id] == entity)
        {
            gEntities.splice(id, 1);
            break;
        }
    }
}

function UpdateEntities(timeDelta)
{
    for(var id in gEntities)
    {
        var ent = gEntities[id];
        ent.OnUpdate(timeDelta);
    }
}


function LongUpdateEntities(timeDelta)
{
    for(var id in gEntities)
    {
        var ent = gEntities[id];
        ent.OnLongUpdate(timeDelta);
    }
}


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


