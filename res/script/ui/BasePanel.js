

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
