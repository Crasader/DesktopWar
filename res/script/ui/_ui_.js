


require("res/script/ui/BasePanel.js");
require("res/script/ui/LoginPanel.js");
require("res/script/ui/PanelMgr.js");


gn.ui = {
    login:{
        file:'res/ui/LoginPanel.json',
        inst:new LoginPanel()
    },
    Console:{
        file:'res/ui/ConsolePanel.json',
        inst:null
    }
};

