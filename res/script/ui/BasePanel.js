

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
            this.root.removeFromParent();
        }
        this.initilised = false;
        this.OnDestroy();
    },
    OnInit:function(){},
    OnShow:function(){},
    OnHide:function(){},
    OnDestroy:function(){},

    LoadJson:function(json){
        var root = ccs.load(json).node;
        gn.SceneMgr.AddToUILayer(root);
        this.root = root;
        return root;
    }

});


var EntrancePanel = BasePanel.extend({

    uiVisible:false,

    OnInit:function() {
        var root = ccs.load(gn.ui.entrance.file).node;
        gn.SceneMgr.AddToRoot(root);
        var x = cc.winSize.width - 32;
        var y = 0;
        root.setPosition(x,y);
        var enterBtn = ccui.helper.seekWidgetByName(root, "Button_1");
        enterBtn.addTouchEventListener(this.OnButtonTouch, this);
    },

    OnButtonTouch:function(sender, type) {
        switch (type) {
            case ccui.Widget.TOUCH_ENDED:
                this.uiVisible = !this.uiVisible;
                gn.SceneMgr.GetUILayer().setVisible(this.uiVisible);
                break;
        }
    },


});
