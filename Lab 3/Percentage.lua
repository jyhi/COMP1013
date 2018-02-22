local buf = io.read()

-- XXX: This is tricky.
local buf_iter_num = string.gmatch(buf, "%d+")
local buf_iter_char = string.gmatch(buf, "%a")

local percentage = tonumber(buf_iter_num())
local ch1 = buf_iter_char() -- NOTE: This is a string
local ch2 = buf_iter_char() -- NOTE: This is a string
local x = tonumber(buf_iter_num())

io.write(string.format(
  "%d%% %s%s %d is %f\n",
  percentage, ch1, ch2, x, 1.0 * x * percentage / 100
))
