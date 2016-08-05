

var State = Class.extend({

    name: 'no name',
    onEnter: null,
    onExit: null,
    events: null,

    ctor: function (args) {
        this.name = args.name;
        this.onEnter = args.onenter;
        this.onExit = args.Onexit;
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
    stateList:{},
    currentState:null,
    lastState:null,
    eventHandlers:{},


    ctor:function(entity, states, events, defaultState) {
        this.entity = entity;
        if (!entity instanceof EntityScript) {
            print('StateMachine : entitiy is not EntityScript.');
        }

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
                this.eventHandlers[evt.getName()] = evt.getFn();
            }
            else {
                print('not a EventHandler');
            }
        }

        this.lastState = null;
        this.currentState = this.stateList[defaultState];
        if (this.currentState != null) {
            this.currentState.onEnter(this.entity);
        }
        else {
            print("default state is invalid " + defaultState);
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

    PushEvent:function(event) {
        var handlers = this.eventHandlers[event];
        if (handlers != null) {
            for (var id in handlers) {
                handlers[id](this.entity);
            }
        }
    }

});


var EventHandler = function(name, fn)
{
    this.name = name;
    this.fn = fn;
    this.getName = function()
    {
        return name;
    }
    this.getFn = function()
    {
        return fn;
    }
};




