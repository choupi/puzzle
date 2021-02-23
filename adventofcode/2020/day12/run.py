import math

DIRS = [(1, 0), (0, 1), (-1, 0), (0, -1)]
x = 0
y = 0
d = 0
with open('input') as f:
    for l in f:
        #print(x, y, d)
        act = l[0]
        num = int(l.strip()[1:])
        if act == 'N':
            y += num
        elif act == 'S':
            y -= num
        elif act == 'E':
            x += num
        elif act == 'W':
            x -= num
        elif act == 'R':
            d = (d - num//90) % 4
        elif act == 'L':
            d = (d + num//90) % 4
        elif act == 'F':
            #x += math.cos(math.PI*d/360) * num
            #y += math.sin(math.PI*d/360) * num
            x += DIRS[d][0] * num
            y += DIRS[d][1] * num
print(x, y, d)
print(abs(x)+abs(y))
