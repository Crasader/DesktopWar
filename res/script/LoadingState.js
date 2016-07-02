
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
        this.uiRoot = new cc.Node();
        SceneManager.GetSingleton().AddToMapLayer(this.uiRoot,0,0,0);

        var x = 200;//GameDefine::viewWidth * 0.5f;
        var y = 200;//GameDefine::viewHeight * 0.6f;

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
        percentLabel.setStartNumber(0);
        percentLabel.setColor(cc.Color(0, 255, 0));
        percentLabel.setScale(1.5);
        percentLabel.setPosition(x, y);
        this.uiRoot.addChild(percentLabel);
    },
    
    OnUpdate:function ()
    {
        //Log("update Loading");
        this.loadingManager.UpdateLoading();
        if (this.loadingManager.IsLoadingDone())// && m_percentLabel->isRollDone())
        {
            Game.currentState = this.nextState;
        }
    },
    
    OnExit:function ()
    {
        Log("exit Loading");
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