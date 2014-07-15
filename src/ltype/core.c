#include <lua.h>
#include <lauxlib.h>

#include <stddef.h>

#if LUA_VERSION_NUM < 502

#define luaL_newlib(L, l) \
  (lua_newtable((L)),luaL_setfuncs((L), (l), 0))

void luaL_setfuncs (lua_State *L, const luaL_Reg *l, int nup) {
    luaL_checkstack(L, nup+1, "too many upvalues");
    for (; l->name != NULL; l++) { /* fill the table with given functions */
        int i;
        lua_pushstring(L, l->name);
        for (i = 0; i < nup; i++) /* copy upvalues to the top */
            lua_pushvalue(L, -(nup + 1));
        lua_pushcclosure(L, l->func, nup); /* closure with those upvalues */
        lua_settable(L, -(nup + 3)); /* table must be below the upvalues, the name and the closure */
    }
    lua_pop(L, nup); /* remove upvalues */
}

#endif

static int
ltype(lua_State *L) {
	lua_pushvalue(L, lua_upvalueindex(lua_type(L, 1) + 1));
	return 1;
}

static void
typeclosure(lua_State *L) {
	static const char * typename[] = {
		"nil",		// 0
		"boolean",	// 1
		"userdata",	// 2
		"number",	// 3
		"string",	// 4
		"table",	// 5
		"function",	// 6
		"userdata",	// 7
		"thread",   // 8
		"proto",	// 9
	};
	size_t i;
	const size_t n = sizeof(typename) / sizeof(typename[0]);
	for ( i = 0; i < n; i++ ) {
		lua_pushstring(L, typename[i]);
	}
	lua_pushcclosure(L, ltype, n);
}

int
luaopen_ltype_core(lua_State *L) {
	luaL_Reg l[] = {
		{ NULL,  NULL },
	};

	luaL_newlib(L, l);

	typeclosure(L);
	//lua_setglobal(L, "type");
	lua_setfield(L, -2, "ltype");

	return 1;
}
