
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


var Entities = {}
function CreateEntity()
{
    var entCpp = World.CreateEntity()
    var ent = new EntityScript()
    ent.SetEntity(entCpp)
    var guid = entCpp.getId()
    Entities[guid] = ent

    return ent
}


function SpawnPrefab(name)
{
    var so = new Soldier()
    so.fn()
}

