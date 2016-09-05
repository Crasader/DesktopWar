

/**
 * this is where the game status.
 * Author:Locke
 * Date:2016-7-13
 */



//**************************************GameState********************************************

var GameState = Class.extend({
    ctor:function () {},
    OnEnter:function () {},
    OnUpdate:function () {},
    OnExit:function () {},
    ParseResourceList:function(loadMgr) {}
});



//**************************************Loading********************************************

var LoadingState = GameState.extend
({
    prevState:null,
    nextState:null,
    loadingManager:null,
    uiRoot:null,
    percentLabel:null,
    needPreparedForLoading:false,


    ctor:function () {
        this._super();
        this.loadingManager = new LoadingManager()
    },

    OnEnter:function () {
        if (this.uiRoot == null) {
            this.uiRoot = new cc.Node();

            SceneManager.GetSingleton().AddToMapLayer(this.uiRoot, 0, 0, 0);

            var x = cc.winSize.width * 0.5;
            var y = cc.winSize.height * 0.6;

            this.percentLabel = RollNumberLabel.create();
            this.uiRoot.addChild(this.percentLabel);
            this.percentLabel.setStartNumber(0);
            this.percentLabel.setColor(0, 255, 0);
            this.percentLabel.setScale(1.5);
            this.percentLabel.setPosition(x, y - 20);

            var animInfo = Config.Animation["4001"];
            if (animInfo != null) {
                ccs.ArmatureDataManager.getInstance().addArmatureFileInfo(animInfo.filePath);
                var pArmature = ccs.Armature.create(animInfo.name);
                pArmature.setPosition(x, y);
                this.uiRoot.addChild(pArmature);
                pArmature.getAnimation().playWithIndex(0);
            }
        }
    },

    OnUpdate:function () {
        if (this.needPreparedForLoading) {
            this.loadingManager.GenerateUnLoadList();
            this.loadingManager.ClearLoadingList();
            this.nextState.ParseResourceList(this.loadingManager);
            this.loadingManager.StartLoading();
            this.needPreparedForLoading = false;
        }

        this.loadingManager.UpdateLoading();
        var percent = this.loadingManager.GetLoadingPercent();
        this.percentLabel.rollTo(percent);
        if (this.loadingManager.IsLoadingDone() && this.percentLabel.isRollDone()) {
            Game.currentState = this.nextState;
        }

    },

    OnExit:function () {
        if (this.uiRoot != null) {
            this.uiRoot.removeFromParent();
            this.uiRoot = null;
        }
    },


    SetTwoStatus:function(prev,next) {
        this.prevState = prev;
        this.nextState = next;
        this.needPreparedForLoading = true;
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
        PanelMgr.Show(gn.ui.login);
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        PanelMgr.Destroy(gn.ui.login);
    },

    ParseResourceList:function(loadMgr)
    {

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
        //Monster.Create(2012, 700, 133, gn.Tag.Monster);
        NoxiousCreeeper.Create(2009, 1300, 133, gn.Tag.Monster);//mother spider
        //ShadowArcher.Create(2010, 200, 133, gn.Tag.Monster);
        //Monster.Create(2010, 350, 133, gn.Tag.Monster);

        //Juggernaut.Create(2008, 400, 150, gn.Tag.Monster);        //铁人
        //Juggernaut.Create(2008, 1050, 153, gn.Tag.Monster);
        //Juggernaut.Create(2008, 1150, 133, gn.Tag.Monster);

        //Monster.Create(2011, 300, 133, gn.Tag.Monster);
        //Monster.Create(2011, 280, 120, gn.Tag.Monster);
        //Monster.Create(2011, 260, 140, gn.Tag.Monster);

        //HolyKnight.Create(1007, 520, 120, gn.Tag.Soldier);
        //Monster.Create(2004, 570, 120, gn.Tag.Monster);
        //Sheep.Create(1004, 1090, 450, gn.Tag.Monster);
        //Sheep.Create(1004, 1100, 450, gn.Tag.Monster);
        //HolyKnight.Create(1007, 1000, 450, gn.Tag.Soldier);
        /*Soldier.Create(1004, 1020, 450, gn.Tag.Soldier);
         Soldier.Create(1005, 1040, 450, gn.Tag.Soldier);
         Soldier.Create(1006, 1060, 450, gn.Tag.Soldier);
         Soldier.Create(1007, 1080, 450, gn.Tag.Soldier);
         Soldier.Create(1008, 1100, 450, gn.Tag.Soldier);*/


        //Soldier.Create(1001, 400, 550);
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        //print("exit War");
    },

    ParseResourceList:function(loadMgr)
    {
        for(var i = 1001; i <= 1008; ++i){
            loadMgr.AddRole(i);
        }
        for(i = 2001; i <= 2012; ++i){
            loadMgr.AddRole(i);
        }

        loadMgr.AddAnim(3001);
        loadMgr.AddAnim(3002);
        loadMgr.AddAnim(3003);
    }

});









