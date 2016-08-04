

var State = Class.extend({

    name:'no name',
    onenter:null,
    onexit:null,
    events:null,

    ctor:function(args)
    {
        this.name = args.name;
        this.onenter = args.onEnter;
        this.onexit = args.OnExit;
    },

    OnEnter:function(entity)
    {
        if (this.onenter!=null)
        {
            this.onenter();
        }
    },

    OnExit:function(entity)
    {
        if (this.onexit!=null)
        {
            this.onexit();
        }
    },

    getName:function()
    {
        return this.name;
    }

});



var StateGraph = Class.extend({

    entity:null,
    stateList:null,
    currentState:null,
    lastState:null,


    ctor:function(entity, states, defaultState)
    {
        this.entity = entity;
        if (!entity instanceof EntityScript)
        {
            print('StateMachine : entitiy is not EntityScript.');
        }

        for(var id in states)
        {
            var state = states[id];
            if (state instanceof State)
            {
                if (this.stateList[state.getName()]!=null)
                {
                    print('repeated state '+state.getName());
                }

                this.stateList[state.getName()] = state;
            }
            else
            {
                print('not a State '+state);
            }
        }

        this.lastState = null;
        this.currentState = this.stateList[defaultState];
        if (this.currentState!=null)
        {
            this.currentState.onEnter();
        }
        else
        {
            print("default state is invalid "+defaultState);
        }

    },

    gotoState:function(stateName)
    {
        var newState = this.stateList[stateName];
        if (null == newState)
        {
            print('invalid state name:'+stateName);
            return;
        }
        this.lastState = this.currentState;
        this.currentState = newState;
        if(this.lastState != null)
        {
            this.lastState.onExit(this.entity);
        }
        this.currentState.onEnter();
    },

});