
/**
 * Attr component
 * by Locke
 * lololol~
 */



var Attr = BaseComponent.extend({

    name:"Attr",
    attrs:{},

    ctor:function ()
    {
        this.attrs.hp = 0;
    },

    Get:function(name)
    {
        return this.attrs[name];
    },

    Set:function(name, value)
    {
        this.attrs[name] = value;
    },

    Have:function(name)
    {
        for(var id in this.attrs)
        {
            if(id === name)
                return true;
        }
        return false;
    },

});


// enum
Attr.HP = "hp";
Attr.MP = "mp";
Attr.PA = "PhyAtk";
Attr.MA = "MgcAtk";
Attr.DP = "DfsPhy";
Attr.DM = "DfsMgc";
Attr.SPD = "speed";
