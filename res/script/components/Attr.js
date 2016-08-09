
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
        this.attrs = [];
        this.attrs[gn.Attr.HP] = 0;
        this.attrs[gn.Attr.MP] = 0;
        this.attrs[gn.Attr.AP] = 0;
        this.attrs[gn.Attr.AM] = 0;
        this.attrs[gn.Attr.DP] = 0;
        this.attrs[gn.Attr.DM] = 0;
        this.attrs[gn.Attr.SPD] = 0;
        this.attrs[gn.Attr.DODGE] = 0;
    },

    Get:function(name)
    {
        return this.attrs[name];
    },

    Set:function(name, value)
    {
        if(value<0)value=0;
        this.attrs[name] = value;
    },

    Mod:function(name, vaule)
    {
        var newValue = this.Get(name) + vaule;
        this.Set(name, newValue);
        if(newValue<0)
            return vaule-newValue;
        else
            return vaule;
    },

    InitWithRoleCfg:function(roleCfg)
    {
        this.attrs[gn.Attr.HP] = Number(roleCfg.baseLife);
        this.attrs[gn.Attr.AP] = 0;
        this.attrs[gn.Attr.AM] = 0;
        if (roleCfg.attackType == gn.AttackType.Physic)
        {
            this.attrs[gn.Attr.AP] = Number(roleCfg.attackValue);
            this.attrs[gn.Attr.AM] = 0;
        }
        else if (roleCfg.attackType == gn.AttackType.Magic)
        {
            this.attrs[gn.Attr.AP] = 0;
            this.attrs[gn.Attr.AM] = Number(roleCfg.attackValue);
        }

        this.attrs[gn.Attr.DP] = Number(roleCfg.antiPhysicValue);
        this.attrs[gn.Attr.DM] = Number(roleCfg.antiMagicValue);

        this.attrs[gn.Attr.SPD] = Number(roleCfg.moveSpeed);

        this.attrs[gn.Attr.DODGE] = Number(roleCfg.dodgeValue);
    },

    InitWithBulletCfg:function(bulletCfg)
    {
        this.attrs[gn.Attr.SPD] = bulletCfg.flySpeed;
    }

});

