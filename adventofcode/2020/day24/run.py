
def go(x, y, d):
    if d == 'e':
        return x+1, y
    elif d == 'w':
        return x-1, y
    elif d == 'nw':
        if y%2 == 1:
            return x, y+1
        else:
            return x-1, y+1
    elif d == 'ne':
        return x + (y%2), y+1
    elif d == 'sw':
        if y%2 == 1:
            return x, y-1
        else:
            return x-1, y-1
    elif d == 'se':
        return x + (y%2), y-1

def parse(s):
    if s[0] == 'e' or s[0] == 'w':
        return s[0], s[1:]
    elif s[0] == 'n' or s[0] == 's':
        return s[:2], s[2:]

tile_dict = {}
#with open('inp') as f:
with open('input') as f:
    for l in f:
        l = l.strip()
        x, y = 0, 0
        while l:
            d, l = parse(l)
            x, y = go(x, y, d)
        tile_dict[(x, y)] = tile_dict.get((x, y), 0) + 1
        #print(x, y)
total = 0
for v in tile_dict.values():
    if v%2 == 1:
        total += 1
print(total)
