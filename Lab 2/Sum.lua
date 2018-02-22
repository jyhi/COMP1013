-- "Any variable name is assumed to be global unless explicitly declared as a
-- local." (§3.2)
local value1, value2 = 50.0, 25.0
local sum = value1 + value2

-- "The format string follows the same rules as the ISO C function sprintf."
--   https://www.lua.org/manual/5.3/manual.html#pdf-string.format
print(string.format("The sum of %.1f and %f is %f", value1, value2, sum))
