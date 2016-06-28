#include "base/ccConfig.h"
#ifndef __app_h__
#define __app_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_app(lua_State* tolua_S);
