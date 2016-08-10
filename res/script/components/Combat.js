
/**
 * Combat component
 * by Locke
 * lololol~
 */



var Combat = BaseComponent.extend({

    name:"Combat",

    ctor:function ()
    {

    },

    OnStart:function(){
        var roleCfg = this.entity.GetBlackboard(gn.BB.RoleCfg);
        gn.SkillMgr.LoadSkill(this.entity.GetID(), roleCfg.normalSkill1);
        gn.SkillMgr.LoadSkill(this.entity.GetID(), roleCfg.normalSkill2);
        gn.SkillMgr.LoadSkill(this.entity.GetID(), roleCfg.specialSkill1);
        gn.SkillMgr.LoadSkill(this.entity.GetID(), roleCfg.specialSkill2);
        gn.SkillMgr.LoadSkill(this.entity.GetID(), roleCfg.specialSkill3);
    },

    OnUpdate:function()
    {

    },

    OnLongUpdate:function()
    {

    },

});
