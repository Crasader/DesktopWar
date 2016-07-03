
var LoadingState = GameState.extend
({
    prevState:null,
    nextState:null,
    loadingManager:null,
    uiRoot:null,
    percentLabel:null,


    ctor:function ()
    {
        this._super();
        this.loadingManager = new LoadingManager();
    },
    
    OnEnter:function ()
    {
        Log("enter Loading");
        if (this.uiRoot == null)
        {
            this.uiRoot = new cc.Node();

            SceneManager.GetSingleton().AddToMapLayer(this.uiRoot, 0, 0, 0);

            var x = cc.winSize.width * 0.5;
            var y = cc.winSize.height * 0.6;

            var animInfoList = AnimDataMgr.FindAnimInfo("Loading_King");
            if (animInfoList != null)
            {
                ccs.ArmatureDataManager.getInstance().addArmatureFileInfo(animInfoList.FilePath());
                var pArmature = ccs.Armature.create("Loading_King");
                pArmature.setPosition(x, y);
                this.uiRoot.addChild(pArmature);
                pArmature.getAnimation().playWithIndex(0);
            }

            percentLabel = RollNumberLabel.create();
            this.uiRoot.addChild(percentLabel);
            percentLabel.setStartNumber(0);
            percentLabel.setColor(0,255,0);
            percentLabel.setScale(1.5);
            percentLabel.setPosition(x, y-20);
        }
    },
    
    OnUpdate:function ()
    {
        //Log("update Loading");
        this.loadingManager.UpdateLoading();
        if (this.loadingManager.IsLoadingDone())// && m_percentLabel->isRollDone())
        {
            Game.currentState = this.nextState;
        }
        var percent = this.loadingManager.GetLoadingPercent();
        percentLabel.rollTo(percent);
    },
    
    OnExit:function ()
    {
        Log("exit Loading");
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