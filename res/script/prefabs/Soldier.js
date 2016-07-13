//士兵预制，配置了组件，资源，状态等

var Soldier = Class.extend({

    fn:function()
    {
        var entity = CreateEntity()
        var entCpp = entity.GetEntity()
        entCpp.AddComponent("Position")
        entCpp.AddComponent("PawnAnim")

        entity.LoadComponent("bev")
    },

})