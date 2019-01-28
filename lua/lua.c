//
// Created by koncord on 08.01.19.
//

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <direct.h>
#else
#include <unistd.h>
#endif

#include <ffi.h>
#include <api.h>
#include <Functions/Timer.h>
#include <Functions/Public.h>
#include <Functions/Server.h>
#include <Functions/Miscellaneous.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <luajit.h>
#include <assert.h>

#if LUAJIT_VERSION_NUM != 20100
#error "Minimal LuaJit version is 2.1.0"
#endif

static lua_State *L;

void Log(unsigned short level, const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    int sz = 1 + vsnprintf(NULL, 0, fmt, list);
    char *msg = malloc (sz);

    vsnprintf(msg, sz, fmt, list);
    va_end(list);
    LogMessage(level, msg);
    free(msg);
}

#define GetGlobalOrRef(L, s) \
    static int funcRef = -1;\
    if (funcRef == -1)\
    {\
        lua_getglobal(L, (s));\
        lua_pushvalue(L, 1);\
        funcRef = luaL_ref(L, LUA_REGISTRYINDEX);\
    }\
    else\
        lua_rawgeti(L, LUA_REGISTRYINDEX, funcRef)

void OnServerInit()
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pcall(L, 0, 0, 0);
}

void OnServerPostInit()
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pcall(L, 0, 0, 0);
}

void OnServerExit(bool code)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, code);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerConnect(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerDisconnect(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerDeath(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerResurrect(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerCellChange(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerAttribute(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerSkill(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerLevel(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerBounty(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerReputation(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerEquipment(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerInventory(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerJournal(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerFaction(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerShapeshift(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerQuickKeys(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerTopic(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerDisposition(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerBook(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerItemUse(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerMiscellaneous(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerInput(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnPlayerRest(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnRecordDynamic(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnCellLoad(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnCellUnload(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnCellDeletion(const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 1, 0, 0);
}

void OnContainer(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnDoorState(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectActivate(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectPlace(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectState(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectSpawn(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectDelete(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectLock(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectScale(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnObjectTrap(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnVideoPlay(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorList(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorEquipment(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorAI(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorDeath(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorCellChange(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnActorTest(PlayerId pid, const char *cellDescription)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, cellDescription);
    lua_pcall(L, 2, 0, 0);
}

void OnPlayerSendMessage(PlayerId pid, const char *message)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, message);
    lua_pcall(L, 2, 0, 0);
}

void OnPlayerEndCharGen(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnGUIAction(PlayerId pid, const char *data)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pushstring(L, data);
    lua_pcall(L, 2, 0, 0);
}

void OnWorldKillCount(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnWorldMap(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnWorldWeather(PlayerId pid)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, pid);
    lua_pcall(L, 1, 0, 0);
}

void OnMpNumIncrement(int mpNum)
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pushinteger(L, mpNum);
    lua_pcall(L, 1, 0, 0);
}

void OnRequestPluginList()
{
    GetGlobalOrRef(L, __FUNCTION__);
    lua_pcall(L, 0, 0, 0);
}

typedef struct TPublic
{
    union
    {
        int timerId;
        char *pubname;
    };
    char rettype;
    int refid;
} Public;

Public *timers;
int timersN = 0;

Public *publics;
int publicN = 0;

void push_val(va_list list, char def)
{
    switch (def)
    {
        case 'v':
            break;
        case 's': // const char*
            lua_pushstring(L, va_arg(list, const char*));
            break;
        case 'c':
            lua_pushinteger(L, (int8_t) va_arg(list, int));
            break;
        case 'C':
            lua_pushinteger(L, (uint8_t) va_arg(list, int));
            break;
        case 'h':
            lua_pushinteger(L, (int16_t) va_arg(list, int));
            break;
        case 'H':
            lua_pushinteger(L, (uint16_t) va_arg(list, int));
            break;
        case 'i':
            lua_pushinteger(L, va_arg(list, int32_t));
            break;
        case 'I':
            lua_pushinteger(L, va_arg(list, uint32_t));
            break;
        case 'l':
            lua_pushinteger(L, va_arg(list, int64_t));
            break;
        case 'L':
            lua_pushinteger(L, va_arg(list, uint64_t));
            break;
        case 'f':
        case 'd':
            lua_pushnumber(L, va_arg(list, double));
            break;
        case 'p':
            lua_pushinteger(L, (RetType) va_arg(list, void*));
            break;
        case 'b': // bool
            lua_pushinteger(L, (bool) (va_arg(list, int) == 1));
            break;
        default:
            break;
    }
}

void GetPublicAndDef(Public **public, const char **def)
{
    const char *pubName = GetPublicName();
    if (pubName != NULL)
    {
        for (int i = 0; i < publicN; ++i)
        {
            if (strcmp(publics[i].pubname, pubName) == 0)
            {
                (*public) = &publics[i];
                break;
            }
        }

        if (def != NULL)
            (*def) = GetPublicDefinition(pubName);
    }
    else
    {
        int timerId = GetTimerId();
        if (timerId != -1)
        {
            for (int i = 0; i < timersN; ++i)
            {
                if (timers[i].timerId == timerId)
                {
                    (*public) = &timers[i];
                    break;
                }
            }

            if (def != NULL)
                (*def) = GetTimerDefinition(timerId);
        }
    }
}

void PushValue(lua_State *L, char varType, ptrdiff_t var)
{
    switch (varType)
    {
        case 'v':
            break;
        case 's': // const char*
            lua_pushstring(L, (const char *) var);
            break;
        case 'c':
            lua_pushinteger(L, var);
            break;
        case 'C':
            lua_pushinteger(L, var);
            break;
        case 'h':
            lua_pushinteger(L, var);
            break;
        case 'H':
            lua_pushinteger(L, var);
            break;
        case 'i':
            lua_pushinteger(L, var);
            break;
        case 'I':
            lua_pushinteger(L, var);
            break;
        case 'l':
            lua_pushinteger(L, var);
            break;
        case 'L':
            lua_pushinteger(L, var);
            break;
        case 'f':
        case 'd':
            lua_pushnumber(L, (double) var);
            break;
        case 'p':
            lua_pushinteger(L, var);
            break;
        case 'b': // bool
            lua_pushinteger(L, var);
            break;
        default:
            break;
    }
}

ptrdiff_t GetValue(lua_State *L, char varType, int var)
{
    switch (varType)
    {
        case 'v':
            return 0;
        case 's': // const char*
            return (ptrdiff_t) luaL_checkstring(L, var);
        case 'c':
            return luaL_checkinteger(L, var);
        case 'C':
            return luaL_checkinteger(L, var);
        case 'h':
            return luaL_checkinteger(L, var);
        case 'H':
            return luaL_checkinteger(L, var);
        case 'i':
            return luaL_checkinteger(L, var);
        case 'I':
            return luaL_checkinteger(L, var);
        case 'l':
            return luaL_checkinteger(L, var);
        case 'L':
            return luaL_checkinteger(L, var);
        case 'f':
        case 'd':
            return luaL_checknumber(L, (double) var);
        case 'p':
            return luaL_checkinteger(L, var);
        case 'b': // bool
            return luaL_checkinteger(L, var);
        default:
            return 0;
    }
}

ptrdiff_t CallBackVoid()
{
    Public *public;

    GetPublicAndDef(&public, NULL);

    assert(public != NULL);

    lua_rawgeti(L, LUA_REGISTRYINDEX, public->refid); // get lua function by refId
    if (lua_pcall(L, 0, public->rettype == 'v' ? 0 : 1, 0) != 0)
    {
        Log(3, "CallBackVoid: lua_pcall: %s\n", lua_tostring(L, -1));
        return 0;
    }
    if (public->rettype != 'v')
        return GetValue(L, public->rettype, -1);
    return 0;
}

ptrdiff_t CallBack(ptrdiff_t arg0, ...)
{
    Public *public = NULL;
    const char *def = NULL;

    GetPublicAndDef(&public, &def);

    assert(public != NULL);

    size_t defLen = strlen(def);

    lua_rawgeti(L, LUA_REGISTRYINDEX, public->refid); // get lua function by refId

    if (defLen > 0)
    {
        PushValue(L, def[0], arg0);

        va_list list;
        va_start(list, arg0);
        for (size_t i = 1; i < defLen; ++i)
            push_val(list, def[i]);
        va_end(list);
    }

    int numRets =  public->rettype == 'v' ? 0 : 1;

    if (lua_pcall(L, (int) defLen,numRets, 0) != 0)
    {
        Log(3, "lua_pcall: %s\n", lua_tostring(L, -1));
        return 0;
    }

    if (numRets == 1)
        return GetValue(L, public->rettype, -1);
    return 0;
}

void _InitCBT(int tid, int refid)
{
    int found = 0;
    for (int i = 0; i < timersN; ++i)
    {
        if (timers[i].timerId == -1)
            found = 1;
    }

    if (found == 0)
    {
        timersN++;
        timers = realloc(timers, sizeof(Public) * publicN);
    }

    Public *public = &publics[publicN - 1];

    public->timerId = tid;
    public->refid = refid;
    public->rettype = 'v';
}

void _InitCBP(const char *cbname, char retType, int refid)
{
    publicN++;
    publics = realloc(publics, sizeof(Public) * publicN);
    Public *public = &publics[publicN - 1];

    public->pubname = strdup(cbname);
    public->rettype = retType;
    public->refid = refid;
}

int GetRefId(lua_State *L, int idx, int *refId)
{
    (*refId) = -1;

    if (!(lua_isfunction(L, 1) || lua_isstring(L, 1)))
        return luaL_error(L, "GetRefId: first argument must be string or function, got %s\n", luaL_typename(L, 1));

    if (lua_isstring(L, idx))
    {
        const char *fname = lua_tostring(L, idx);
        lua_getglobal(L, fname);
        if (lua_isnil(L, lua_gettop(L)) != 0)
            return luaL_error(L, "lua_CreateTimer: %s is local or not implemented\n", fname);
    }
    else
        lua_pushvalue(L, idx); // idx = function

    (*refId) = luaL_ref(L, LUA_REGISTRYINDEX); // stack -> registry
    return 0;
}

int lua_CreateTimer(lua_State *L)
{
    int refId;
    int rets = GetRefId(L, 1, &refId);
    if (refId < 0)
        return rets;
    int msec = luaL_checkinteger(L, 2);
    int tid = CreateTimer((ScriptFunc) CallBackVoid, msec);
    _InitCBT(tid, refId);
    lua_pushinteger(L, tid);
    return 1;
}

typedef struct TFFIArgs
{
    uint64_t *ints;
    double *flts;
    void **args;
    ffi_type **types;
} FFIArgs;

void CreateFFIArgs(FFIArgs *a, int nargs)
{
    a->types = malloc(sizeof(ffi_type *) * nargs);
    a->args = malloc(sizeof(void *) * nargs);
}

void FreeFFIArgs(FFIArgs *a)
{
    free(a->flts);
    free(a->ints);
    free(a->types);
    free(a->args);
}

void LuaVarArgsToFFI(const char *def, int nargs, int start, FFIArgs *args)
{
    int intsS = 10, fltsS = 10;
    int intsP = 0, fltsP = 0;
    double *flts = malloc(sizeof(double) * fltsS);
    uint64_t *ints = malloc(sizeof(uint64_t) * intsS);

    for (int i = start; i < nargs; ++i)
    {
        switch (def[i - start])
        {
            case 'v':
                args->types[i] = &ffi_type_void;
                args->args[i] = 0;
                break;
            case 's': // const char*
                args->types[i] = &ffi_type_pointer;
                ints[intsP] = (uint64_t) luaL_checkstring(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'c':
                args->types[i] = &ffi_type_sint8;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'C':
                args->types[i] = &ffi_type_uint8;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'h':
                args->types[i] = &ffi_type_sint16;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'H':
                args->types[i] = &ffi_type_uint16;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'i':
                args->types[i] = &ffi_type_sint32;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'I':
                args->types[i] = &ffi_type_uint32;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'l':
                args->types[i] = &ffi_type_sint64;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'L':
                args->types[i] = &ffi_type_uint64;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'f':
            case 'd':
                args->types[i] = &ffi_type_double;
                flts[fltsP] = luaL_checknumber(L, 1 + i);
                args->args[i] = &(flts[fltsP++]);
                break;
            case 'p':
                args->types[i] = &ffi_type_pointer;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            case 'b': // bool
                args->types[i] = &ffi_type_sint8;
                ints[intsP] = luaL_checkinteger(L, 1 + i);
                args->args[i] = &ints[intsP++];
                break;
            default:
                break;
        }
        if (intsP >= intsS)
        {
            intsS += 10;
            ints = realloc(ints, sizeof(uint64_t) * intsS);
        }
        else if (fltsP >= fltsS)
        {
            fltsS += 10;
            flts = realloc(flts, sizeof(double) * fltsS);
        }
    }
    args->ints = ints;
    args->flts = flts;
}

int lua_CreateTimerEx(lua_State *L)
{
    int refId;
    int rets = GetRefId(L, 1, &refId);
    if (refId < 0)
        return rets;
    int msec = luaL_checkinteger(L, 2);
    const char *def = luaL_checkstring(L, 3);
    size_t defLen = strlen(def);

    int nargs = lua_gettop(L);

    if (nargs - 3 != defLen)
        return -1;

    if (defLen == 0)
        return lua_CreateTimer(L); // timer without args

    FFIArgs a;
    CreateFFIArgs(&a, nargs);

    a.types[0] = &ffi_type_pointer;
    ptrdiff_t cbptr = (ptrdiff_t) &CallBack;
    a.args[0] = &cbptr;
    a.types[1] = &ffi_type_sint32;
    a.args[1] = &msec;
    a.types[2] = &ffi_type_pointer;
    a.args[2] = &def;

    LuaVarArgsToFFI(def, nargs, 3, &a);

    ffi_cif cif;
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, (unsigned int) nargs, &ffi_type_sint32, a.types) != FFI_OK)
    {
        //todo: error
    }

    ffi_arg tid;
    ffi_call(&cif, FFI_FN(CreateTimerEx), &tid, a.args);

    FreeFFIArgs(&a);

    _InitCBT((int) tid, refId);
    lua_pushinteger(L, tid);
    return 1;
}

int lua_StartTimer(lua_State *L)
{
    int tid = luaL_checkinteger(L, 1);
    StartTimer(tid);
    return 0;
}

int lua_StopTimer(lua_State *L)
{
    int tid = luaL_checkinteger(L, 1);
    StopTimer(tid);
    return 0;
}

int lua_RestartTimer(lua_State *L)
{
    int tid = luaL_checkinteger(L, 1);
    int msec = luaL_checkinteger(L, 2);
    RestartTimer(tid, msec);
    return 0;
}

int lua_FreeTimer(lua_State *L)
{
    int tid = luaL_checkinteger(L, 1);

    Public *public = NULL;
    GetPublicAndDef(&public, NULL);

    if (public != NULL)
    {
        free(public->pubname);
        public->pubname = NULL;
        public->timerId = -1;
        luaL_unref(L, LUA_REGISTRYINDEX, public->refid);
    }

    FreeTimer(tid);
    return 0;
}

int lua_IsTimerElapsed(lua_State *L)
{
    int tid = luaL_checkinteger(L, 1);
    bool res = IsTimerElapsed(tid);
    lua_pushboolean(L, res);
    return 1;
}

int lua_GetTimerId(lua_State *L)
{
    int tid = GetTimerId();
    lua_pushinteger(L, tid);
    return 1;
}

int lua_MakePublic(lua_State *L)
{
    int refId;
    int rets = GetRefId(L, 1, &refId);
    if (refId < 0)
        return rets;
    const char *cbname = luaL_checkstring(L, 1);
    char retType = luaL_checkstring(L, 2)[0];
    size_t defLen;
    const char *def = luaL_checklstring(L, 3, &defLen);

    _InitCBP(cbname, retType, refId);
    ScriptFunc cb;
    if (defLen == 0)
        cb = (ScriptFunc) CallBackVoid;
    else
        cb = (ScriptFunc) CallBack;

    MakePublic(cb, cbname, retType, def);
    return 0;
}

int lua_CallPublic(lua_State *L)
{
    const char *cbname = luaL_checkstring(L, 1);
    const char *def = GetPublicDefinition(cbname);
    char retTypeName = GetPublicReturnType(cbname);
    int nargs = lua_gettop(L);

    FFIArgs a;
    CreateFFIArgs(&a, nargs);
    a.types[0] = &ffi_type_pointer;
    a.args[0] = &cbname;
    LuaVarArgsToFFI(def, nargs, 1, &a);

    ffi_type *retType = &ffi_type_void;
    switch (retTypeName)
    {
        case 'v':
            break;
        case 's': // const char*
            retType = &ffi_type_pointer;
            break;
        case 'c':
            retType = &ffi_type_sint8;
            break;
        case 'C':
            retType = &ffi_type_uint8;
            break;
        case 'h':
            retType = &ffi_type_sint16;
            break;
        case 'H':
            retType = &ffi_type_uint16;
            break;
        case 'i':
            retType = &ffi_type_sint32;
            break;
        case 'I':
            retType = &ffi_type_uint32;
            break;
        case 'l':
            retType = &ffi_type_sint64;
            break;
        case 'L':
            retType = &ffi_type_uint64;
            break;
        case 'f':
        case 'd':
            retType = &ffi_type_double;
            break;
        case 'p':
            retType = &ffi_type_pointer;
            break;
        case 'b': // bool
            retType = &ffi_type_sint8;
            break;
        default:
            break;
    }

    ffi_cif cif;
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, (unsigned int) nargs, retType, a.types) != FFI_OK)
    {
        luaL_error(L, "Cannot initializate CIF\n");
        return 1;
    }

    ffi_arg ret;
    ffi_call(&cif, FFI_FN(CallPublic), &ret, a.args);

    FreeFFIArgs(&a);

    if (retTypeName != 'v')
    {
        PushValue(L, retTypeName, ret);
        return 1;
    }
    return 0;
}

static const luaL_Reg mylib[] = {
    {"CreateTimer", lua_CreateTimer},
    {"CreateTimerEx", lua_CreateTimerEx},
    {"MakePublic", lua_MakePublic},
    {"CallPublic", lua_CallPublic},
    {"StartTimer", lua_StartTimer},
    {"StopTimer", lua_StopTimer},
    {"RestartTimer", lua_RestartTimer},
    {"FreeTimer", lua_FreeTimer},
    {"IsTimerElapsed", lua_IsTimerElapsed},
    {"GetTimerId", lua_GetTimerId},
    {NULL, NULL}
};

int LoadLuaScript(const char *scriptPath)
{
    if (luaL_loadfile(L, scriptPath) != 0)
    {

        Log(3, "luaL_loadfile: %s\n", lua_tostring(L, -1));
        return 0;
    }

    if (lua_pcall(L, 0, 0, 0) != 0)
    {
        Log(3, "lua_pcall: %s\n", lua_tostring(L, -1));
        return 0;
    }
    return 1;
}

void setLuaPath(lua_State *L, const char *path, const char *field)
{
    lua_getglobal(L, "package");

    lua_getfield(L, -1, field);
    size_t cur_pathLen;
    const char *curPath = lua_tolstring(L, -1, &cur_pathLen);
    size_t newPathLen = cur_pathLen + strlen(path) + 2;
    char *newPath = malloc(newPathLen);
    snprintf(newPath, newPathLen, "%s;%s", curPath, path);
    lua_pop(L, 1);
    lua_pushstring(L, newPath);
    lua_setfield(L, -2, field);
    lua_pop(L, 1);
    free(newPath);
}

void setPath(const char *path, const char *field, char sep)
{
    char libDir[1024];

    const char *pluginDir = GetPluginDir();
    size_t baseStrSize = strrchr(pluginDir, sep) - pluginDir;
    strncpy(libDir, pluginDir, baseStrSize);
    strncpy(&libDir[baseStrSize], path, strlen(path) + 1);
    setLuaPath(L, libDir, field);
}

int PluginInit()
{
    L = luaL_newstate();
    if (!L)
        return 0;

    luaL_openlibs(L);

#ifdef _WIN32
    setPath("\\scripts\\?.lua;", "path", '\\');
    setPath("\\lib\\lua\\?.lua;", "path", '\\');
    setPath("\\lib\\?.dll", "cpath", '\\');
#else
    setPath("/scripts/?.lua;", "path", '/');
    setPath("/lib/lua/?.lua;", "path", '/');
    setPath("/lib/?.so", "cpath", '/');
#endif

    luaL_register(L, "tes3mp", mylib);
    char path[1024];
    const char *luaScript = "serverCore.lua";
    const char *pluginDir = GetPluginDir();

    snprintf(path, sizeof(path), "%s/%s", pluginDir, luaScript);
    if (LoadLuaScript(path) == 0)
        return 0;

    return 1;
}

void PluginFree()
{
    for (int i = 0; i < publicN; ++i)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, publics[i].refid);
        free(publics[i].pubname);
    }
    free(publics);

    for (int i = 0; i < timersN; ++i)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, publics[i].refid);
        free(timers[i].pubname);
    }
    free(timers);

    Log(0, "PluginFree()");
    lua_close(L);
}
