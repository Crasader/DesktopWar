


// Creates a new class inheriting from Action
var Wait = b3.Class(b3.Action);

// Remember to set the name of the node.
Wait.prototype.name = 'Wait';

// Sets the parameters variable to tell editor who they are
Wait.prototype.parameters = {'milliseconds': 0};

// Override the initialize method, remember to call this method on super
Wait.prototype.__Action_initialize = Wait.prototype.initialize;
Wait.prototype.initialize = function(settings) {
    settings = settings || {};

    this.__Action_initialize();
    this.endTime = settings.milliseconds || 0;
};

// Override the open method, so it can store the time when the node was
// open
Wait.prototype.open = function(tick) {
    var startTime = (new Date()).getTime();
    tick.blackboard.set('startTime', startTime, tick.tree.id, this.id);
};

// Override the tick method
Wait.prototype.tick = function(tick) {
    var currTime = (new Date()).getTime();
    var startTime = tick.blackboard.get('startTime', tick.tree.id, this.id);

    if (currTime - startTime > this.endTime) {
        return b3.SUCCESS;
    }

    return b3.RUNNING;
};