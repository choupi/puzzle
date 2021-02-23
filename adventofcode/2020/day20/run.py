
edges = {}
tile_edges = {}

def set_edge(e, t):
    if e not in edges:
        edges[e] = []
    edges[e].append(t)

def set_edges(e, t):
    #print(e)
    set_edge(e, t)
    e = e[::-1]
    #print(e)
    set_edge(e, t)

def set_all_edge(tile, tid):
    set_edge(tile[0], tid+'0')
    #print(tid+'0', tile[0])
    set_edge(tile[0][::-1], tid+'0r')
    #print(tid+'0r', tile[0][::-1])
    set_edge(tile[-1], tid+'1')
    set_edge(tile[-1][::-1], tid+'1r')
    e = [s[0] for s in tile]
    #print(tid+'2', ''.join(e))
    set_edge(''.join(e), tid+'2')
    e = e[::-1]
    #print(tid+'2r', ''.join(e))
    set_edge(''.join(e), tid+'2r')
    e = [s[-1] for s in tile]
    set_edge(''.join(e), tid+'3')
    e = e[::-1]
    set_edge(''.join(e), tid+'3r')

with open('input') as f:
#with open('inp') as f:
    tid = ''
    l = f.readline()
    while l:
        if l.strip() == '':
            set_all_edge(tile, tid)
        elif l.startswith('Tile'):
            tile = []
            _, tid = l.strip().split(' ', 1)
        else:
            tile.append(l.strip())
        l = f.readline()
set_all_edge(tile, tid)
print(edges)
nums = {}
for e, v in edges.items():
    #print(e, len(v), v)
    if len(v) ==1:
    #    print(e, v)
        for n in v:
            print(n)
            nn = int(n[:n.find(':')])
            nums[nn] = nums.get(nn, 0)+1
total = 1
for nn in nums:
    if nums[nn] > 2:
        print(nn)
        total *= nn
print(total)
