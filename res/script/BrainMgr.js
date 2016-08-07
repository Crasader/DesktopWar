
var BrainMgr = null;

(function(){
    'use strict';

    var BrainManager = Class.extend({

        brianList:null,
        updatingBrains:null,

        ctor:function(){
            this.brianList = {};
            this.updatingBrains = {};
        },

        AddBrain:function(entity,brain){
            if(!entity instanceof EntityScript){
                print('BrainMgr.AddBrain: entity is not EntityScript.');
                return;
            }
            if(!brain instanceof Brain){
                print('BrainMgr.AddBrain: brain is not Brain.');
                return;
            }
            this.brianList[entity.GetID()] = brain;
            // temp
            this.updatingBrains[entity.GetID()] = brain;
        },

        RemoveBrain:function(entity,brain){
            if(!entity instanceof EntityScript){
                print('BrainMgr.RemoveBrain: entity is not EntityScript.');
                return;
            }
            if(!brain instanceof Brain){
                print('BrainMgr.RemoveBrain: brain is not Brain.');
                return;
            }
            this.brianList[entity.GetID()] = undefined;
            this.updatingBrains[entity.GetID()] = undefined;
        },

        OnUpdate:function(){
            for(var id in this.updatingBrains){
                this.updatingBrains[id].OnUpdate();
            }
        },

    });

    BrainMgr = new BrainManager();

})();