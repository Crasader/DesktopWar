

var State = Class.extend({

    name: 'no name',
    onEnter: null,
    onExit: null,
    eventHandlers: null,

    ctor: function (args) {
        this.name = args.name;
        this.onEnter = args.onenter;
        this.onExit = args.onexit;
        this.eventHandlers = {};
        for(var id in args.events){
            var evt = args.events[id];
            if (evt instanceof EventHandler) {
                this.ListenForEvent(evt.getName(),evt.getFn());
            }
            else {
                print('not a EventHandler');
            }
        }
    },

    OnEnter: function (entity) {
        if (this.onenter != null) {
            this.onenter();
        }
    },

    OnExit: function (entity) {
        if (this.onexit != null) {
            this.onexit();
        }
    },

    getName: function () {
        return this.name;
    },

    ListenForEvent:function(event, handler) {
        if (typeof(event) != 'string') {
            print('State.ListenForEvent: event is not a string.@'+this.getName());
            return;
        }
        if (typeof(handler) != 'function') {
            print('State.ListenForEvent: handler is not a function.@'+this.getName());
            return;
        }
        if(this.eventHandlers[event] != null){
            print('State.ListenForEvent: override event @event:'+event+'@State:'+this.getName());
        }

        this.eventHandlers[event] = handler;
    },

    HandleEvent:function(event,entity){
        if(this.eventHandlers[event] != null){
            this.eventHandlers[event](entity);
        }
    }

});



var StateGraph = Class.extend({

    entity:null,
    stateList:null,
    currentState:null,
    lastState:null,
    eventHandlers:null,
    defaultState:'',
    lastAnimPrefixName:'',


    ctor:function(entity, states, events, defaultState) {
        this.entity = entity;
        this.defaultState = defaultState;
        if (!entity instanceof EntityScript) {
            print('StateMachine : entitiy is not EntityScript.');
        }

        this.stateList = {};
        this.eventHandlers = {};

        for (var id in states) {
            var state = states[id];
            if (state instanceof State) {
                if (this.stateList[state.getName()] != null) {
                    print('repeated state ' + state.getName());
                }
                this.stateList[state.getName()] = state;
            }
            else {
                print('not a State ' + state);
            }
        }

        for (var id in events) {
            var evt = events[id];
            if (evt instanceof EventHandler) {
                this.ListenForEvent(evt.getName(),evt.getFn());
            }
            else {
                print('not a EventHandler');
            }
        }

    },

    Start:function(){
        this.lastState = null;
        this.currentState = this.stateList[this.defaultState];
        if (this.currentState != null) {
            this.currentState.onEnter(this.entity);
        }
        else {
            print("default state is invalid " + this.defaultState);
        }
    },

    gotoState:function(stateName) {
        var newState = this.stateList[stateName];
        if (null == newState) {
            print('invalid state name:' + stateName);
            return;
        }
        this.lastState = this.currentState;
        this.currentState = newState;
        if (this.lastState != null) {
            this.lastState.onExit(this.entity);
        }
        this.currentState.onEnter(this.entity);
    },

    //event
    ListenForEvent:function(event, handler) {
        if (typeof(event) != 'string') {
            print('EntityScript.ListenForEvent: event is not a string.');
            return;
        }
        if (typeof(handler) != 'function') {
            print('EntityScript.ListenForEvent: handler is not a function.');
            return;
        }
        this.eventHandlers[event] = handler;
    },

    PushEvent:function(event,data) {
        var handlers = this.eventHandlers[event];
        if (handlers != null) {
            handlers(this.entity,data);
        }
        if(this.currentState != null){
            this.currentState.HandleEvent(event,this.entity);
        }

    },

    SetAnimPrefixName:function(name) {
        this.lastAnimPrefixName = name;
    },

    GetAnimPrefixName:function() {
        return this.lastAnimPrefixName;
    },

    GetCurrentState:function(){
        return this.currentState;
    }

});


var EventHandler = Class.extend({
    name:'',
    fn:null,
    ctor:function(_name, _fn){
        this.name = _name;
        this.fn = _fn;
    },
    getName:function(){
        return this.name;
    },
    getFn:function() {
        return this.fn;
    },
});




