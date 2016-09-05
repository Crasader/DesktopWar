

var PanelMgr = {

    Show:function(info){
        if(info.inst instanceof BasePanel){
            info.inst.Init();
            info.inst.Show();
        }else{
            print('PanelMgr Show:cannot find '+info);
        }
    },

    Hide:function(info){
        if(info.inst instanceof BasePanel){
            info.inst.Hide();
        }else{
            print('PanelMgr Hide:cannot find '+info);
        }
    },

    Destroy:function(info){
        if(info.inst instanceof BasePanel){
            info.inst.Destroy();
        }else{
            print('PanelMgr Destroy:cannot find '+info);
        }
    },

};








