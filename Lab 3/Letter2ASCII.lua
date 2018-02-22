print("Please input an English letter:")
local c = string.byte(io.read())
io.write(string.format(
    "\"%c\" and its neighbors in ASCII:\n"..
    "%d\t%d\t%d\n"..
    "%c\t%c\t%c\n",
    c,
    c - 1, c, c + 1,
    c - 1, c, c + 1
))
