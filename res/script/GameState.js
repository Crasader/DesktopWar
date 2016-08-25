

/**
 * this is where the game status.
 * Author:Locke
 * Date:2016-7-13
 */



//**************************************GameState********************************************

var GameState = Class.extend({
    
    ctor:function ()
    {
        
    },
    
    OnEnter:function ()
    {
        
    },
    
    OnUpdate:function ()
    {
        
    },
    
    OnExit:function ()
    {
        
    },

    ParseResourceList:function(loadMgr)
    {

    }
    
});



//**************************************Loading********************************************

var LoadingState = GameState.extend
({
    prevState:null,
    nextState:null,
    loadingManager:null,
    uiRoot:null,
    percentLabel:null,


    ctor:function ()
    {
        this._super()
        this.loadingManager = new LoadingManager()
    },

    OnEnter:function ()
    {
        //print("enter Loading");
        if (this.uiRoot == null)
        {
            this.uiRoot = new cc.Node();

            SceneManager.GetSingleton().AddToMapLayer(this.uiRoot, 0, 0, 0);

            var x = cc.winSize.width * 0.5;
            var y = cc.winSize.height * 0.6;

            this.percentLabel = RollNumberLabel.create();
            this.uiRoot.addChild(this.percentLabel);
            this.percentLabel.setStartNumber(0);
            this.percentLabel.setColor(0,255,0);
            this.percentLabel.setScale(1.5);
            this.percentLabel.setPosition(x, y-20);

            var animInfo = Config.Animation["4001"];
            if (animInfo != null)
            {
                ccs.ArmatureDataManager.getInstance().addArmatureFileInfo(animInfo.filePath);
                var pArmature = ccs.Armature.create(animInfo.name);
                pArmature.setPosition(x, y);
                this.uiRoot.addChild(pArmature);
                pArmature.getAnimation().playWithIndex(0);
            }
        }
    },

    OnUpdate:function ()
    {
        //print("update Loading")
        this.loadingManager.UpdateLoading();
        var percent = this.loadingManager.GetLoadingPercent();
        this.percentLabel.rollTo(percent);
        if (this.loadingManager.IsLoadingDone() && this.percentLabel.isRollDone())
        {
            Game.currentState = this.nextState;
        }

    },

    OnExit:function ()
    {
        //print("exit Loading");
        if(this.uiRoot != null)
        {
            this.uiRoot.removeFromParent();
        }
    },


    SetTwoStatus:function(prev,next)
    {
        this.prevState = prev;
        this.nextState = next;

        this.loadingManager.GenerateUnLoadList();
        this.loadingManager.ClearLoadingList();
        this.nextState.ParseResourceList(this.loadingManager);
        this.loadingManager.StartLoading();
    }

});


//**************************************Launch********************************************

var LaunchState = GameState.extend
({

    ctor:function ()
    {
        this._super()
    },

    OnEnter:function ()
    {

        //Monster.Create(2012, 700, 133, gn.Tag.Monster);
        //NoxiousCreeeper.Create(2009, 1300, 133, gn.Tag.Monster);//mother spider
        //ShadowArcher.Create(2010, 200, 133, gn.Tag.Monster);
        //Monster.Create(2010, 350, 133, gn.Tag.Monster);

        //Juggernaut.Create(2008, 400, 150, gn.Tag.Monster);        //铁人
        //Juggernaut.Create(2008, 1050, 153, gn.Tag.Monster);
        //Juggernaut.Create(2008, 1150, 133, gn.Tag.Monster);

        //Monster.Create(2011, 300, 133, gn.Tag.Monster);
        //Monster.Create(2011, 280, 120, gn.Tag.Monster);
        //Monster.Create(2011, 260, 140, gn.Tag.Monster);

        HolyKnight.Create(1007, 520, 120, gn.Tag.Soldier);
        Monster.Create(2004, 570, 120, gn.Tag.Monster);

        /*Soldier.Create(1001, 1000, 450, gn.Tag.Soldier);
        Soldier.Create(1004, 1020, 450, gn.Tag.Soldier);
        Soldier.Create(1005, 1040, 450, gn.Tag.Soldier);
        Soldier.Create(1006, 1060, 450, gn.Tag.Soldier);
        Soldier.Create(1007, 1080, 450, gn.Tag.Soldier);
        Soldier.Create(1008, 1100, 450, gn.Tag.Soldier);*/


        //Soldier.Create(1001, 400, 550);

        //print("enter Launch");
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        //print("exit Launch");
    },

    ParseResourceList:function(loadMgr)
    {
        loadMgr.AddRole(1001);
        loadMgr.AddRole(1002);
        loadMgr.AddRole(1003);
        loadMgr.AddRole(1004);
        loadMgr.AddRole(1005);
        loadMgr.AddRole(1006);
        loadMgr.AddRole(1007);
        loadMgr.AddRole(1008);

        loadMgr.AddRole(2001);
        loadMgr.AddRole(2002);
        loadMgr.AddRole(2003);
        loadMgr.AddRole(2004);
        loadMgr.AddRole(2005);
        loadMgr.AddRole(2006);
        loadMgr.AddRole(2007);
        loadMgr.AddRole(2008);
        loadMgr.AddRole(2009);
        loadMgr.AddRole(2010);
        loadMgr.AddRole(2009);
        loadMgr.AddRole(2008);
        loadMgr.AddRole(2012);
        loadMgr.AddRole(2011);


        loadMgr.AddAnim(3001);
        loadMgr.AddAnim(3002);
        loadMgr.AddAnim(3003);
    }

});



//**************************************WarState********************************************

var WarState = GameState.extend({

    ctor:function ()
    {
        this._super();
    },

    OnEnter:function ()
    {
        print("enter War");
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        print("exit War");
    },

    ParseResourceList:function(loadMgr)
    {
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "HolyKnight")
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "BigDevil")
    }

});









