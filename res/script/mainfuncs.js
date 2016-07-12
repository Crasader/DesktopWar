
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


var EntityMap = {}
function CreateEntity(entCPP)
{
    var ent = new EntityScript()
    ent.SetEntity(entCPP)
    var guid = entCPP.getId()
    EntityMap[guid] = ent

    return ent
}




