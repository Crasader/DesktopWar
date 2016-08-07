




var bt = {};


(function() {
    "use strict";

    bt.VERSION   = '0.1.0';

    bt.SUCCESS   = 1;

    bt.FAILURE   = 2;

    bt.RUNNING   = 3;

    bt.ERROR     = 4;

    bt.COMPOSITE = 'composite';

    bt.DECORATOR = 'decorator';

    bt.ACTION    = 'action';

    bt.CONDITION = 'condition';


    bt.createUUID = function() {
        var s = [];
        var hexDigits = "0123456789abcdef";
        for (var i = 0; i < 36; i++) {
            s[i] = hexDigits.substr(Math.floor(Math.random() * 0x10), 1);
        }
        // bits 12-15 of the time_hi_and_version field to 0010
        s[14] = "4";

        // bits 6-7 of the clock_seq_hi_and_reserved to 01
        s[19] = hexDigits.substr((s[19] & 0x3) | 0x8, 1);

        s[8] = s[13] = s[18] = s[23] = "-";

        var uuid = s.join("");
        return uuid;
    };


    bt.Class = function(baseClass) {
        // create a new class
        var cls = function(params) {
            this.initialize(params);
        };

        // if base class is provided, inherit
        if (baseClass) {
            cls.prototype = new baseClass();
            cls.prototype.constructor = cls;
        }

        // create initialize if does not exist on baseClass
        cls.prototype.initialize = cls.prototype.initialize || function() {};

        return cls;
    };

})();




(function() {
    "use strict";

    var Blackboard = bt.Class();

    var p = Blackboard.prototype;


    p.initialize = function() {
        this._baseMemory = {};
        this._treeMemory = {};
    };


    p._getTreeMemory = function(treeScope) {
        if (!this._treeMemory[treeScope]) {
            this._treeMemory[treeScope] = {
                'nodeMemory'         : {},
                'openNodes'          : [],
                'traversalDepth'     : 0,
                'traversalCycle'     : 0,
            };
        }
        return this._treeMemory[treeScope];
    };


    p._getNodeMemory = function(treeMemory, nodeScope) {
        var memory = treeMemory['nodeMemory'];
        if (!memory[nodeScope]) {
            memory[nodeScope] = {};
        }

        return memory[nodeScope];
    };


    p._getMemory = function(treeScope, nodeScope) {
        var memory = this._baseMemory;

        if (treeScope) {
            memory = this._getTreeMemory(treeScope);

            if (nodeScope) {
                memory = this._getNodeMemory(memory, nodeScope);
            }
        }

        return memory;
    };


    p.set = function(key, value, treeScope, nodeScope) {
        var memory = this._getMemory(treeScope, nodeScope);
        memory[key] = value;
    };


    p.get = function(key, treeScope, nodeScope) {
        var memory = this._getMemory(treeScope, nodeScope);
        return memory[key];
    };

    bt.Blackboard = Blackboard;

})();




(function() {
    "use strict";

    var Tick = bt.Class();

    var p = Tick.prototype;


    p.initialize = function() {
        // set by BehaviorTree
        this.tree       = null;
        this.debug      = null;
        this.target     = null;
        this.blackboard = null;

        // updated during the tick signal
        this._openNodes  = [];
        this._nodeCount  = 0;
    };


    p._enterNode = function(node) {
        this._nodeCount++;
        this._openNodes.push(node);

        // TODO: call debug here
    };


    p._openNode = function(node) {
        // TODO: call debug here
    };


    p._tickNode = function(node) {
        // TODO: call debug here
    };


    p._closeNode = function(node) {
        // TODO: call debug here
        this._openNodes.pop();
    };


    p._exitNode = function(node) {
        // TODO: call debug here
    };


    bt.Tick = Tick;

})();




(function() {
    "use strict";


    var BehaviorTree = bt.Class();

    var p = BehaviorTree.prototype;


    p.initialize = function() {
        this.id          = bt.createUUID();
        this.title       = 'The behavior tree';
        this.description = 'Default description';
        this.properties  = {};
        this.root        = null;
        this.debug       = null;
    };


    p.load = function(data, names) {
        names = names || {};

        this.title       = data.title || this.title;
        this.description = data.description || this.description;
        this.properties  = data.properties || this.properties;

        var nodes = {};
        // Create the node list (without connection between them)
        for (var id in data.nodes) {
            var spec = data.nodes[id];

            if (spec.name in names) {
                // Look for the name in custom nodes
                var cls = names[spec.name];
            } else if (spec.name in b3) {
                // Look for the name in default nodes
                var cls = b3[spec.name];
            } else {
                // Invalid node name
                throw EvalError('BehaviorTree.load: Invalid node name + "'+
                    spec.name+'".');
            }

            var node = new cls(spec.parameters);
            node.id = spec.id || node.id;
            node.title = spec.title || node.title;
            node.description = spec.description || node.description;
            node.properties = spec.properties || node.properties;
            node.parameters = spec.parameters || node.parameters;

            nodes[id] = node;
        }

        // Connect the nodes
        for (var id in data.nodes) {
            var spec = data.nodes[id];
            var node = nodes[id];

            if (node.category === bt.COMPOSITE && spec.children) {
                for (var i=0; i<spec.children.length; i++) {
                    var cid = spec.children[i];
                    node.children.push(nodes[cid]);
                }
            } else if (node.category === bt.DECORATOR && spec.child) {
                node.child = nodes[spec.child];
            }
        }

        this.root = nodes[data.root];
    };


    p.dump = function() {
        var data = {};

        data.title       = this.title;
        data.description = this.description;
        data.root        = (this.root)? this.root.id:null;
        data.properties  = this.properties;
        data.nodes       = {};

        if (!this.root) return data;

        var stack = [this.root];
        while (stack.length > 0) {
            var node = stack.pop();

            var spec = {};
            spec.id = node.id;
            spec.name = node.name;
            spec.title = node.title;
            spec.description = node.description;
            spec.properties = node.properties;
            spec.parameters = node.parameters;

            if (node.category === bt.COMPOSITE && node.children) {
                var children = []
                for (var i=node.children.length-1; i>=0; i--) {
                    children.push(node.children[i].id);
                    stack.push(node.children[i]);
                }
                spec.children = children;
            } else if (node.category === bt.DECORATOR && node.child) {
                stack.push(node.child);
                spec.child = node.child.id;
            }

            data.nodes[node.id] = spec;
        }

        return data;
    };


    p.tick = function(target, blackboard) {
        if (!blackboard) {
            throw 'The blackboard parameter is obligatory and must be an ' +
            'instance of bt.Blackboard';
        }

        /* CREATE A TICK OBJECT */
        var tick = new bt.Tick();
        tick.debug      = this.debug;
        tick.target     = target;
        tick.blackboard = blackboard;
        tick.tree       = this;

        /* TICK NODE */
        var state = this.root._execute(tick);

        /* CLOSE NODES FROM LAST TICK, IF NEEDED */
        var lastOpenNodes = blackboard.get('openNodes', this.id);
        var currOpenNodes = tick._openNodes.slice(0);

        // does not close if it is still open in this tick
        var start = 0;
        for (var i=0; i<Math.min(lastOpenNodes.length, currOpenNodes.length); i++) {
            start = i+1;
            if (lastOpenNodes[i] !== currOpenNodes[i]) {
                break;
            }
        }

        // close the nodes
        for (var i=lastOpenNodes.length-1; i>=start; i--) {
            lastOpenNodes[i]._close(tick);
        }

        /* POPULATE BLACKBOARD */
        blackboard.set('openNodes', currOpenNodes, this.id);
        blackboard.set('nodeCount', tick._nodeCount, this.id);

        return state;
    };


    bt.BehaviorTree = BehaviorTree;

})();




bt.BaseNode = Class.extend({
    name:null,
    category:null,
    title:null,
    description:null,
    parameters:null,
    properties:null,

    ctor:function() {
        this.id          = bt.createUUID();
        this.title       = this.title || this.name;
        this.description = '';
        this.parameters  = {};
        this.properties  = {};
    },

    _execute:function(tick) {

        this._enter(tick);

        if (!tick.blackboard.get('isOpen', tick.tree.id, this.id)) {
            this._open(tick);
        }

        var status = this._tick(tick);

        if (status !== bt.RUNNING) {
            this._close(tick);
        }

        this._exit(tick);

        return status;
    },

    _enter:function(tick) {
        tick._enterNode(this);
        this.enter(tick);
    },


    _open :function(tick) {
        tick._openNode(this);
        tick.blackboard.set('isOpen', true, tick.tree.id, this.id);
        this.open(tick);
    },


    _tick :function(tick) {
        tick._tickNode(this);
        return this.tick(tick);
    },


    _close:function(tick) {
        tick._closeNode(this);
        tick.blackboard.set('isOpen', false, tick.tree.id, this.id);
        this.close(tick);
    },


    _exit :function(tick) {
        tick._exitNode(this);
        this.exit(tick);
    },


    enter:function(tick) {},


    open:function(tick) {},


    tick:function(tick) {},


    close:function(tick) {},


    exit:function(tick) {}


});



bt.Action = bt.BaseNode.extend({

    ctor:function()
    {
        this._super();
        this.category = bt.ACTION;
    }

});


bt.Composite = bt.BaseNode.extend({

    children:null,

    ctor:function(settings)
    {
        settings = settings || {};
        this._super();
        this.category = bt.COMPOSITE;
        this.children = (settings.children || []).slice(0);
    }

});

bt.Decorator = bt.BaseNode.extend({

    child:null,

    ctor:function(settings)
    {
        settings = settings || {};
        this._super();
        this.category = bt.DECORATOR;
        this.child = settings.child || null;
    }

});


bt.Condition = bt.BaseNode.extend({

    child:null,

    ctor:function(settings)
    {
        this.category = bt.CONDITION;
        settings = settings || {};
        this._super();
        this.child = settings.child || null;
    }

});



bt.Sequence = bt.Composite.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'Sequence';
    },

    tick:function(tick) {
        for (var i=0; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== bt.SUCCESS) {
                return status;
            }
        }
        return bt.SUCCESS;
    }

});


bt.Priority = bt.Composite.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'Priority';
    },

    tick:function(tick) {
        for (var i=0; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== bt.FAILURE) {
                return status;
            }
        }

        return bt.FAILURE;
    }

});


bt.Parallel = bt.Composite.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'Parallel';
    },

    tick:function(tick) {
        var done = true;
        for (var i=0; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== bt.SUCCESS) {
                done = false;
            }
            if (status === bt.FAILURE) {
                return bt.FAILURE;
            }
        }

        if (done)
            return bt.SUCCESS;
        else
            return bt.RUNNING;
    }

});



bt.MemSequence = bt.Composite.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'MemSequence';
    },

    open:function(tick) {
        tick.blackboard.set('runningChild', 0, tick.tree.id, this.id);
    },

    tick:function(tick) {
        var child = tick.blackboard.get('runningChild', tick.tree.id, this.id);
        for (var i=child; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== bt.SUCCESS) {
                if (status === bt.RUNNING) {
                    tick.blackboard.set('runningChild', i, tick.tree.id, this.id);
                }
                return status;
            }
        }

        return bt.SUCCESS;
    }

});



bt.MemPriority = bt.Composite.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'MemPriority';
    },

    open:function(tick) {
        tick.blackboard.set('runningChild', 0, tick.tree.id, this.id);
    },

    tick:function(tick) {
        var child = tick.blackboard.get('runningChild', tick.tree.id, this.id);
        for (var i=child; i<this.children.length; i++) {
            var status = this.children[i]._execute(tick);

            if (status !== bt.FAILURE) {
                if (status === bt.RUNNING) {
                    tick.blackboard.set('runningChild', i, tick.tree.id, this.id);
                }
                return status;
            }
        }

        return bt.FAILURE;
    }

});



bt.Inverter = bt.Decorator.extend({

    ctor:function(settings)
    {
        this._super(settings);
        this.name = 'Inverter';
    },

    tick:function(tick) {
        if (!this.child) {
            return bt.ERROR;
        }

        var status = this.child._execute(tick);

        if (status == bt.SUCCESS)
            status = bt.FAILURE;
        else if (status == bt.FAILURE)
            status = bt.SUCCESS;

        return status;
    }

});



bt.Limiter = bt.Decorator.extend({

    ctor:function(settings)
    {
        settings = settings || {};

        this._super(settings);
        this.name = 'Limiter';

        if (!settings.maxLoop) {
            throw "maxLoop parameter in Limiter decorator is an obligatory " +
            "parameter";
        }

        this.maxLoop = settings.maxLoop;
    },

    open:function(tick) {
        tick.blackboard.set('i', 0, tick.tree.id, this.id);
    },

    tick:function(tick) {
        if (!this.child) {
            return bt.ERROR;
        }

        var i = tick.blackboard.get('i', tick.tree.id, this.id);

        if (i < this.maxLoop) {
            var status = this.child._execute(tick);

            if (status == bt.SUCCESS || status == bt.FAILURE)
                tick.blackboard.set('i', i+1, tick.tree.id, this.id);

            return status;
        }

        return bt.FAILURE;
    }

});


bt.MaxTime = bt.Decorator.extend({

    maxTime:0,

    ctor:function(settings)
    {
        this.name = 'MaxTime';
        settings = settings || {};
        this._super(settings);
        if (!settings.maxTime) {
            throw "maxTime parameter in MaxTime decorator is an obligatory " +
            "parameter";
        }

        this.maxTime = settings.maxTime;
    },

    open:function(tick) {
        var startTime = (new Date()).getTime();
        tick.blackboard.set('startTime', startTime, tick.tree.id, this.id);
    },

    tick:function(tick) {
        if (!this.child) {
            return bt.ERROR;
        }

        var currTime = (new Date()).getTime();
        var startTime = tick.blackboard.get('startTime', tick.tree.id, this.id);

        var status = this.child._execute(tick);
        if (currTime - startTime > this.maxTime) {
            return bt.FAILURE;
        }

        return status;
    }


});



bt.Repeater = bt.Decorator.extend({

    maxLoop:0,

    ctor:function(settings)
    {
        this.name = 'Repeater';
        settings = settings || {};
        this._super(settings);
        this.maxLoop = settings.maxLoop || -1;
    },

    open:function(tick) {
        tick.blackboard.set('i', 0, tick.tree.id, this.id);
    },

    tick:function(tick) {
        if (!this.child) {
            return bt.ERROR;
        }

        var i = tick.blackboard.get('i', tick.tree.id, this.id);
        var status = bt.SUCCESS;

        while (this.maxLoop < 0 || i < this.maxLoop) {
            status = this.child._execute(tick);

            if (status == bt.SUCCESS || status == bt.FAILURE)
                i++;
            else
                break;
        }

        i = tick.blackboard.set('i', i, tick.tree.id, this.id);
        return status;
    }


});



bt.Wait = bt.Action.extend({

    endTime:0,

    ctor:function(settings)
    {
        this._super();
        this.name = 'Wait';
        settings = settings || {};
        this.endTime = settings.milliseconds || 0;
    },

    open:function(tick) {
        var startTime = (new Date()).getTime();
        tick.blackboard.set('startTime', startTime, tick.tree.id, this.id);
    },

    tick:function(tick) {
        var currTime = (new Date()).getTime();
        var startTime = tick.blackboard.get('startTime', tick.tree.id, this.id);

        if (currTime - startTime > this.endTime) {
            return bt.SUCCESS;
        }

        return bt.RUNNING;
    }


});




