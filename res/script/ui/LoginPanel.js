
var BasePanel = Class.extend({

    root:null,
    initilised:false,

    Init:function() {
        if(!this.initilised){
            this.initilised = true;
            this.OnInit();
        }
    },

    Show:function() {
        if (this.root != null) {
            this.root.setVisible(true);
        }
        this.OnShow();
    },

    Hide:function() {
        if (this.root != null) {
            this.root.setVisible(false);
        }
        this.OnHide();
    },

    Destroy:function() {
        if (this.root != null) {
            this.root.removeFromParentAndCleanup(true);
        }
        this.initilised = false;
        this.OnDestroy();
    },
    OnInit:function(){},
    OnShow:function(){},
    OnHide:function(){},
    OnDestroy:function(){}

});


var LoginPanel = BasePanel.extend({

    OnInit:function() {
        var root = ccs.load("res/ui/login/LoginPanel.json").node;
        gn.SceneMgr.AddToUILayer(root);

        var startBtn = ccui.helper.seekWidgetByName(root, "StartBtn");
        startBtn.addTouchEventListener(this.OnStartButtonTouch, this);
        var cancelBtn = ccui.helper.seekWidgetByName(root, "BackBtn");
        cancelBtn.addTouchEventListener(this.OnCancelButtonTouch, this);

    },

    OnShow:function(){
        print('on show');
    },

    OnHide:function(){
        print('on hide');
    },

    OnDestroy:function(){
        print('on destory');
    },

    // widget events handlers
    OnStartButtonTouch:function(sender, type) {
        switch (type) {
            case ccui.Widget.TOUCH_BEGAN:
                break;
            case ccui.Widget.TOUCH_MOVED:
                break;
            case ccui.Widget.TOUCH_ENDED:
                Game.ChangeState(Game.warState);
                break;
            case ccui.Widget.TOUCH_CANCELED:
                break;
            default:
                break;
        }
    },

    OnCancelButtonTouch:function(sender, type) {
        switch (type) {
            case ccui.Widget.TOUCH_ENDED:
                Game.ChangeState(Game.warState);
                break;
        }
    },


});



var PanelMgr = {

    panelDic:{
        'login':new LoginPanel(),
    },

    Show:function(name){
        var panel = this.panelDic[name];
        if(panel instanceof BasePanel){
            panel.Init();
            panel.Show();
        }else{
            print('cannot find '+name);
        }
    },

    Hide:function(name){
        var panel = this.panelDic[name];
        if(panel instanceof BasePanel){
            panel.Init();
            panel.Hide();
        }else{
            print('cannot find '+name);
        }
    },

    Destroy:function(name){
        var panel = this.panelDic[name];
        if(panel instanceof BasePanel){
            panel.Init();
            panel.Destroy();
        }else{
            print('cannot find '+name);
        }
    },

};








