
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
            //print('add brain');
        },

        RemoveBrain:function(entity){
            if(!entity instanceof EntityScript){
                print('BrainMgr.RemoveBrain: entity is not EntityScript.');
                return;
            }
            delete this.brianList[entity.GetID()];
            delete this.updatingBrains[entity.GetID()];
        },

        OnUpdate:function(){
            for(var id in this.updatingBrains){
                this.updatingBrains[id].OnUpdate();
            }
        },

        OnLongUpdate:function(){
            //for(var id in this.brianList){
            //    this.brianList[id].OnLongUpdate();
            //}
        }

    });

    BrainMgr = new BrainManager();

})();