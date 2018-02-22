print("Input 2 integers:")
local buf_iter = string.gmatch(io.read(), "%d+")
local a, b = tonumber(buf_iter()), tonumber(buf_iter())

if b == 0 then
  print("b can't be 0.")
  return 1
end

io.write(string.format(
  "%d+%d=%d\n"..
  "%d-%d=%d\n"..
  "%d*%d=%d\n"..
  "%d/%d=%d\n"..
  "%d%%%d=%d\n",
  a, b, a + b,
  a, b, a - b,
  a, b, a * b,
  a, b, a // b, -- floor division
  a, b, a % b
))
