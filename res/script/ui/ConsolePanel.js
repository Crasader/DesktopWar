




var ConsolePanel = BasePanel.extend({

    roleList:{},

    OnInit:function() {
        var root = this.LoadJson(gn.ui.console.file);

        //var x = cc.winSize.width * 0.5;
        //var y = cc.winSize.height * 0.6;

        var listView = ccui.helper.seekWidgetByName(root, "ListView");
        var listSize = listView.getContentSize();
        listView.setPosition(cc.winSize.width - listSize.width, 0);

        var unit = ccui.helper.seekWidgetByName(root, "Unit");
        unit.addTouchEventListener(this.OnUnitTouch, this);

        this.roleList = {};

        for(var i = 1001; i < 1008; i++){
            var copy = unit.clone();
            copy.setName(""+i);
            listView.addNode(copy);
            var roleCfg = Config.Role[i];
            this.roleList[i] = {};
            this.roleList[i].root = copy;
            var icon = ccui.helper.seekWidgetByName(copy, "Icon");
            this.roleList[i].icon = icon;
            icon.loadTexture("icon/"+roleCfg.icon+".png", 1);
        }

    },

    OnShow:function(){
        //print('on show');
    },

    OnHide:function(){
        //print('on hide');
    },

    OnDestroy:function(){
        //print('on destory');
    },

    OnUnitTouch:function(sender, type) {
        switch (type) {
            case ccui.Widget.TOUCH_ENDED:
                print('unit');
                break;
        }
    },


});
