

/**
 * this is where the journey starts.
 * Author:Locke
 * Date:2016-7-2
 */


require("res/script/Game.js");


//print("lololol JS bang!")

Game.Start();



/*cc.game.onStart = function(){
 if(!cc.sys.isNative && document.getElementById("cocosLoading")) //If referenced loading.js, please remove it
 document.body.removeChild(document.getElementById("cocosLoading"))

 cc.view.enableRetina(cc.sys.os === cc.sys.OS_IOS ? true : false)
 cc.view.adjustViewPort(true)
 cc.view.setDesignResolutionSize(960, 640, cc.ResolutionPolicy.SHOW_ALL)
 cc.view.resizeWithBrowserSize(true)
 cc.LoaderScene.preload(g_resources, function () {
 cc.director.runScene(new HelloWorldScene())
 }, this)
 }
 cc.game.run()*/

