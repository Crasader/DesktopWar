/*
 * Copyright (c) 2013-2014 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//
// Javascript Bindigns helper file
//

// DO NOT ALTER THE ORDER
require('res/script/ccs/jsb_cocos2d_constants.js');
require('res/script/ccs/jsb_cocos2d.js');
require('res/script/ccs/jsb_common.js');
require('res/script/ccs/jsb_property_impls.js');
require('res/script/ccs/jsb_property_apis.js');
require('res/script/ccs/jsb_create_apis.js');

if (window.ccs) {
    require('res/script/ccs/studio/jsb_studio_boot.js');
    require('res/script/ccs/studio/jsb_cocos2d_studio.js');
    require('res/script/ccs/studio/jsb_studio_property_apis.js');
    require('res/script/ccs/studio/jsb_studio_create_apis.js');

    require('res/script/ccs/studio/jsb_studio_load.js');
    require('res/script/ccs/studio/parsers/action-1.x.js');
    require('res/script/ccs/studio/parsers/action-2.x.js');
    require('res/script/ccs/studio/parsers/scene-1.x.js');
    require('res/script/ccs/studio/parsers/timelineParser-1.x.js');
    require('res/script/ccs/studio/parsers/timelineParser-2.x.js');
    require('res/script/ccs/studio/parsers/uiParser-1.x.js');
    require('res/script/ccs/studio/parsers/compatible.js');
}

if (window.ccui) {
    require('res/script/ccs/ccui/jsb_cocos2d_ui.js');
    require('res/script/ccs/ccui/jsb_ccui_property_impls.js');
    require('res/script/ccs/ccui/jsb_ccui_property_apis.js');
    require('res/script/ccs/ccui/jsb_ccui_create_apis.js');
    require('res/script/ccs/ccui/jsb_ccui_deprecated.js');
}

if (cc.ControlButton) {
    require('res/script/ccs/extension/jsb_cocos2d_extension.js');
    require('res/script/ccs/extension/jsb_ext_property_apis.js');
    require('res/script/ccs/extension/jsb_ext_create_apis.js');
}

if (cc.PhysicsSprite) {
    require('res/script/ccs/physicsSprite/jsb_physicsSprite.js');
}

if (window.cp) {
    // chipmunk
    require('res/script/ccs/chipmunk/jsb_chipmunk_constants.js');
    require('res/script/ccs/chipmunk/jsb_chipmunk.js');
}

require('res/script/ccs/jsb_opengl_constants.js');
require('res/script/ccs/jsb_opengl.js');

if (cc.BuilderAnimationManager) {
    require('res/script/ccs/jsb_cocosbuilder.js');
}

if (jsb.fileUtils.isFileExist('jsb_pluginx.js') || jsb.fileUtils.isFileExist('jsb_pluginx.jsc')) {
    if (cc.sys.os == cc.sys.OS_IOS || cc.sys.os == cc.sys.OS_ANDROID) {
        require('jsb_pluginx.js');
    }
}

if (window.sp) {
    require('res/script/ccs/jsb_spine.js');
}

if (jsb.Sprite3D){
    require('res/script/ccs/3d/jsb_cocos2d_3d.js');
}

if (jsb.ParticleSystem3D) {
    require('res/script/ccs/3d/jsb_cocos2d_3d_ext.js');
}

if (jsb.Physics3DObject) {
    require("res/script/ccs/physics3d/jsb_physics3d.js");
}

if (jsb.NavMeshAgent) {
    require("res/script/ccs/navmesh/jsb_navmesh.js");
}

require("res/script/ccs/jsb_audioengine.js");

require('res/script/ccs/jsb_loaders.js');
require('res/script/ccs/jsb_pool.js');
require('res/script/ccs/jsb_deprecated.js');
