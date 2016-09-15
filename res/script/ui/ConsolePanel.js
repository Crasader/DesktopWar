




var ConsolePanel = BasePanel.extend({



    OnInit:function() {
        var root = this.LoadJson(gn.ui.console.file);

        //var x = cc.winSize.width * 0.5;
        //var y = cc.winSize.height * 0.6;

        var listView = ccui.helper.seekWidgetByName(root, "ListView");
        var listSize = listView.getContentSize();
        listView.setPosition(cc.winSize.width - listSize.width, 0);

        var unit = ccui.helper.seekWidgetByName(root, "Unit");
        unit.addTouchEventListener(this.OnCancelButtonTouch, this);

        for(var i = 0; i < 10; i++){
            var copy = unit.clone();
            listView.addNode(copy);
        }

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
                print('unit');
                break;
        }
    },


});
