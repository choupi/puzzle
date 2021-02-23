from collections import Counter

DF = [-1, 0, 1]
pts = {}
x = 0
y = 0
z = 0
w = 0
with open('input') as f:
#with open('inp') as f:
    for l in f:
        y = 0
        for c in l.strip():
           if c != '#':
               y += 1
               continue
           pts[(x, y, z, w)] = 1
           y += 1
        x += 1
print(len(pts))
print(pts)
for i in range(6):
    ns = Counter([(x+a, y+b, z+c, w+d) for x, y, z, w in pts for a in DF for b in DF for c in DF for d in DF])
    pts = Counter([k for k in ns if (k in pts and 2<ns[k]<5) or (k not in pts and ns[k]==3)])
print(len(pts))
