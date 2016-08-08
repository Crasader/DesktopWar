

var State = Class.extend({

    name: 'no name',
    onEnter: null,
    onExit: null,
    events: null,

    ctor: function (args) {
        this.name = args.name;
        this.onEnter = args.onenter;
        this.onExit = args.onexit;
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
        if (this.eventHandlers[event] == null)
            this.eventHandlers[event] = Array();
        this.eventHandlers[event].push(handler);
    },

    PushEvent:function(event,data) {
        var handlers = this.eventHandlers[event];
        if (handlers != null) {
            for (var id in handlers) {
                handlers[id](this.entity,data);
            }
        }
    },

    SetAnimPrefixName:function(name) {
        this.lastAnimPrefixName = name;
    },

    GetAnimPrefixName:function() {
        return this.lastAnimPrefixName;
    },

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




