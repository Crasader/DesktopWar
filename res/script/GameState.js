

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
    
})



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
        print("enter Loading")
        if (this.uiRoot == null)
        {
            this.uiRoot = new cc.Node()

            SceneManager.GetSingleton().AddToMapLayer(this.uiRoot, 0, 0, 0)

            var x = cc.winSize.width * 0.5
            var y = cc.winSize.height * 0.6

            this.percentLabel = RollNumberLabel.create()
            this.uiRoot.addChild(this.percentLabel)
            this.percentLabel.setStartNumber(0)
            this.percentLabel.setColor(0,255,0)
            this.percentLabel.setScale(1.5)
            this.percentLabel.setPosition(x, y-20)

            var animInfo = Config.Animation["4001"]
            if (animInfo != null)
            {
                ccs.ArmatureDataManager.getInstance().addArmatureFileInfo(animInfo.filePath)
                var pArmature = ccs.Armature.create(animInfo.name)
                pArmature.setPosition(x, y)
                this.uiRoot.addChild(pArmature)
                pArmature.getAnimation().playWithIndex(0)
            }
        }
    },

    OnUpdate:function ()
    {
        //print("update Loading")
        this.loadingManager.UpdateLoading()
        var percent = this.loadingManager.GetLoadingPercent()
        this.percentLabel.rollTo(percent)
        if (this.loadingManager.IsLoadingDone() && this.percentLabel.isRollDone())
        {
            Game.currentState = this.nextState
        }

    },

    OnExit:function ()
    {
        print("exit Loading")
        if(this.uiRoot != null)
        {
            this.uiRoot.removeFromParent()
        }
    },


    SetTwoStatus:function(prev,next)
    {
        this.prevState = prev
        this.nextState = next

        this.loadingManager.GenerateUnLoadList()
        this.loadingManager.ClearLoadingList()
        this.nextState.ParseResourceList(this.loadingManager)
        this.loadingManager.StartLoading()
    }

})


//**************************************Launch********************************************

var LaunchState = GameState.extend
({

    ctor:function ()
    {
        this._super()
    },

    OnEnter:function ()
    {
        //EntityCreator.CreatePawn(2012, 700, 133, 2)
        //EntityCreator.CreatePawn(2009, 300, 133, 2)
        EntityCreator.CreatePawn(2011, 300, 133, 2)
        EntityCreator.CreatePawn(2011, 280, 120, 2)
        EntityCreator.CreatePawn(2011, 260, 140, 2)
        EntityCreator.CreatePawn(1007, 500, 133, 1)
        EntityCreator.CreatePawn(1007, 520, 120, 1)
        EntityCreator.CreatePawn(1007, 540, 140, 1)
        //Soldier.Create(2011)
        print("enter Launch")
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        print("exit Launch")
    },

    ParseResourceList:function(loadMgr)
    {
        loadMgr.AddRole(2012)
        loadMgr.AddRole(2011)
        loadMgr.AddRole(2009)
        loadMgr.AddRole(1007)

        loadMgr.AddAnim(3001)
        loadMgr.AddAnim(3002)
        loadMgr.AddAnim(3003)
    }

})



//**************************************WarState********************************************

var WarState = GameState.extend({

    ctor:function ()
    {
        this._super()
    },

    OnEnter:function ()
    {
        print("enter War")
    },

    OnUpdate:function ()
    {

    },

    OnExit:function ()
    {
        print("exit War")
    },

    ParseResourceList:function(loadMgr)
    {
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "HolyKnight")
        //loadMgr.AddResource(LoadingManager.ResourceType.Json, "BigDevil")
    }

})









