
不知道为什么js工程里jsb不能导出正确的c++文件，
所以万般无奈下只能使用cocos安装的路径下generator，
导出的cpp hpp js文件仍然会在此js工程cocos2d-x\cocos\scripting\js-bindings\auto。

——！！需要修改！！——
appbind.py 中 MyCocosPath = '你自己安装cocos的路径'