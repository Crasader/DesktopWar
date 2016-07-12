//士兵预制，配置了组件，资源，状态等

var Soldier = Class.extend({

    fn:function(entityCPP)
    {
        var entity = CreateEntity(entityCPP)
        entity.LoadComponent("bev")
    },

})