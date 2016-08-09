
/**
 * Attr component
 * by Locke
 * lololol~
 */



var Attr = BaseComponent.extend({

    name:"Attr",
    attrs:null,

    ctor:function ()
    {
        this.attrs = {};
        this.attrs[Attr.HP] = 0;
        this.attrs[Attr.MP] = 0;
        this.attrs[Attr.AP] = 0;
        this.attrs[Attr.AM] = 0;
        this.attrs[Attr.DP] = 0;
        this.attrs[Attr.DM] = 0;
        this.attrs[Attr.SPD] = 0;
        this.attrs[Attr.DODGE] = 0;
    },

    Get:function(name)
    {
        return this.attrs[name];
    },

    Set:function(name, value)
    {
        this.attrs[name] = value;
    },

    InitWithRoleCfg:function(roleCfg)
    {
        this.attrs[Attr.HP] = roleCfg.baseLife;
        this.attrs[Attr.AP] = 0;
        this.attrs[Attr.AM] = 0;
        if (roleCfg.attackType == gn.AttackType.Physic)
        {
            this.attrs[Attr.AP] = roleCfg.attackValue;
            this.attrs[Attr.AM] = 0;
        }
        else if (roleCfg.attackType == gn.AttackType.Magic)
        {
            this.attrs[Attr.AP] = 0;
            this.attrs[Attr.AM] = roleCfg.attackValue;
        }

        this.attrs[Attr.DP] = roleCfg.antiPhysicValue;
        this.attrs[Attr.DM] = roleCfg.antiMagicValue;

        this.attrs[Attr.SPD] = roleCfg.moveSpeed;

        this.attrs[Attr.DODGE] = roleCfg.dodgeValue;
    },

    InitWithBulletCfg:function(bulletCfg)
    {
        this.attrs[Attr.SPD] = bulletCfg.flySpeed;
    }

});


// enum
Attr.HP = "hp";
Attr.MP = "mp";
Attr.AP = "PhyAtk";
Attr.AM = "MgcAtk";
Attr.DP = "DfsPhy";
Attr.DM = "DfsMgc";
Attr.SPD = "speed";
Attr.DODGE = "dodge";
