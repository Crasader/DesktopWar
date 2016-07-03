
/**
 * Using "extend" subclassing
 * Simple JavaScript Inheritance By John Resig http://ejohn.org/
 * lololol~
 */


Class = function(){}
Class.extend = function (prop) {
    var _super = this.prototype,
        prototype, Class, classId,
        className = prop._className || "",
        name, desc

    // Instantiate a base class (but only create the instance,
    // don't run the init constructor)
    initializing = true
    prototype = Object.create(_super)
    initializing = false
    fnTest = /xyz/.test(function(){xyz}) ? /\b_super\b/ : /.*/

    // Copy the properties over onto the new prototype
    for (name in prop) {
        // Check if we're overwriting an existing function
        prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
            (function (name, fn) {
                return function () {
                    var tmp = this._super

                    // Add a new ._super() method that is the same method
                    // but on the super-class
                    this._super = _super[name]

                    // The method only need to be bound temporarily, so we
                    // remove it when we're done executing
                    var ret = fn.apply(this, arguments)
                    this._super = tmp

                    return ret
                }
            })(name, prop[name]) :
            prop[name]
    }

    Class = function () {
        if (!initializing) {
            this.__instanceId = ClassManager.getNewInstanceId()
            this.ctor && this.ctor.apply(this, arguments)
        }
    }
    // Populate our constructed prototype object
    Class.prototype = prototype
    // Enforce the constructor to be what we expect
    Class.prototype.constructor = Class
    // And make this class extendable
    Class.extend = cc.Class.extend

    classId = ClassManager.getNewID()
    ClassManager[classId] = _super
    desc = { writable: true, enumerable: false, configurable: true }
    Class.id = classId
    desc.value = classId
    Object.defineProperty(prototype, '__pid', desc)

    return Class
}
