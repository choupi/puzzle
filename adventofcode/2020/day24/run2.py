from collections import Counter

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
pts = Counter([k for k in tile_dict if tile_dict[k]%2 == 1])
print(len(pts))
#print(pts)
for i in range(100):
    ns = []
    for x, y in pts:
        #print(x, y)
        ns += [go(x, y, 'e'), go(x, y, 'w'), go(x, y, 'ne'), go(x, y, 'nw'),
               go(x, y, 'sw'), go(x, y, 'se'), (x, y)]
        #print(ns)
    ns = Counter(ns)
    #print(ns)
    pts = Counter([p for p in ns if (p in pts and (1<ns[p]<4)) or (p not in pts and ns[p]==2)])
    print(i+1, len(pts))
print(len(pts))
