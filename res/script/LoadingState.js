
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

            var animInfo = Config.anim["Loading_King"]
            if (animInfo != null)
            {
                ccs.ArmatureDataManager.getInstance().addArmatureFileInfo(animInfo.filePath)
                var pArmature = ccs.Armature.create("Loading_King")
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