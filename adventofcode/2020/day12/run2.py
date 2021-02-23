import math

def rotate(wx, wy, act):
#R90/L270: x=y, y=-x
#R180/L180: x=-x, y=-y
#L90/R270: x=-y, y=x
    if act == 'R90' or act == 'L270':
        x, y = wy, -wx
    elif act == 'R180' or act == 'L180':
        x, y = -wx, -wy
    elif act == 'L90' or act == 'R270':
        x, y = -wy, wx
    return x, y

x = 0
y = 0
wx = 10
wy = 1
with open('input') as f:
    for l in f:
        #print(x, y, wx, wy)
        act = l[0]
        num = int(l.strip()[1:])
        if act == 'N':
            wy += num
        elif act == 'S':
            wy -= num
        elif act == 'E':
            wx += num
        elif act == 'W':
            wx -= num
        elif act == 'R':
            wx, wy = rotate(wx, wy, l.strip())
        elif act == 'L':
            wx, wy = rotate(wx, wy, l.strip())
        elif act == 'F':
            x += wx * num
            y += wy * num
print(x, y, wx, wy)
print(abs(x)+abs(y))
