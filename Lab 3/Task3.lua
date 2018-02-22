print("Input 2 integers:")
local buf_iter = string.gmatch(io.read(), "%d+")
local a, b = tonumber(buf_iter()), tonumber(buf_iter())

-- "Lua does not have a traditional conditional operator. However, the
-- short-circuit behaviour of its "and" and "or" operators allows the emulation
-- of this behaviour"
--   https://en.wikipedia.org/wiki/%3F:#Lua
-- See also §3.4.5
print(string.format("The bigger one is %d", a >= b and a or b))
