#!/usr/bin/lua5.1

require("ltype")

local coroutine_create, type
    = coroutine.create, type

local nil_ = nil
local boolean_ = true
local number_ = 123
local string_ = "abc"
local table_ = { }
local function_ = function() end
local thread_ = coroutine_create(function() end)

assert(type(nil_) == "nil")
assert(type(boolean_) == "boolean")
assert(type(string_) == "string")
assert(type(table_) == "table")
assert(type(function_) == "function")
assert(type(thread_) == "thread")

