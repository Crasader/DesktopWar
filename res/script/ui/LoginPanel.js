


var LoginPanel = BasePanel.extend({

    OnInit:function() {
        var root = this.LoadJson(gn.ui.login.file);

        var rootsize = root.getContentSize();
        //var x = cc.winSize.width * 0.5 - rootsize.width*0.5;
        //var y = cc.winSize.height * 0.5 - rootsize.height*0.5 + 100;
        var x = cc.winSize.width - rootsize.width - 30;
        var y = 30;
        root.setPosition(x,y);

        var startBtn = ccui.helper.seekWidgetByName(root, "startBtn");
        startBtn.addTouchEventListener(this.OnStartButtonTouch, this);
        var cancelBtn = ccui.helper.seekWidgetByName(root, "closeBtn");
        cancelBtn.addTouchEventListener(this.OnCancelButtonTouch, this);


    },

    OnShow:function(){
        //print('on show');
    },

    OnHide:function(){
        //print('on hide');
    },

    OnDestroy:function(){
       // print('on destory');
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
                //print('back');
                break;
        }
    },




});


