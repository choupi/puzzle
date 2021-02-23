
edges = {}
tile_edges = {}

def print_adj(t):
    #print(tile_edges[t])
    #print(t)
    adj_t = []
    for e in tile_edges[t]:
        if len(e)<3: continue
        #if len(edges[e])<2: continue
        print(e, edges[e])
        for tt in edges[e]:
            if t in tt: continue
            adj_t.append(tt)
    #print(adj_t)
    ts = set([tt.split(':')[0] for tt in adj_t])
    return ts

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

def set_tile_edge(e, t, eg):
    if t not in tile_edges:
        tile_edges[t] = {}
    tile_edges[t][eg] = e
    tile_edges[t][e] = eg

def set_all_edge(tile, tid):
    set_edge(tile[0], tid+':0')
    set_tile_edge(tile[0], tid, '0')
    #print(tid+'0', tile[0])
    set_edge(tile[0][::-1], tid+':0r')
    set_tile_edge(tile[0][::-1], tid, '0r')
    #print(tid+'0r', tile[0][::-1])
    set_edge(tile[-1], tid+':2')
    set_tile_edge(tile[-1], tid, '2')
    set_edge(tile[-1][::-1], tid+':2r')
    set_tile_edge(tile[-1][::-1], tid, '2r')
    e = [s[0] for s in tile]
    #print(tid+'2', ''.join(e))
    set_edge(''.join(e), tid+':3')
    set_tile_edge(''.join(e), tid, '3')
    e = e[::-1]
    #print(tid+'2r', ''.join(e))
    set_edge(''.join(e), tid+':3r')
    set_tile_edge(''.join(e), tid, '3r')
    e = [s[-1] for s in tile]
    set_edge(''.join(e), tid+':1')
    set_tile_edge(''.join(e), tid, '1')
    e = e[::-1]
    set_edge(''.join(e), tid+':1r')
    set_tile_edge(''.join(e), tid, '1r')

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
            tid = tid.strip(':')
        else:
            tile.append(l.strip())
        l = f.readline()
set_all_edge(tile, tid)
#print(edges)
#for k in tile_edges:
#    print(k, tile_edges[k])
'''
1621
3547
3389
1657
'''
#ts = print_adj('1621')
#ts = print_adj('3547')
#ts = print_adj('3389')
#ts = print_adj('1657')
tile_map = [['']*12 for i in range(12)]
tile_set = set()
t = '1621'
e = '2'
e = str((int(e[:1])+2)%4)
tile_map[0][0] = t
tile_set.add(t)
ts = print_adj(t)
print(t, ts - tile_set)
#t = '2963'
#tile_map[0][1] = t
#e = '1'
for i in range(1, 12):
    tile_set.add(t)
    ts = print_adj(t)
    print(t, ts - tile_set)
    for te in edges[tile_edges[t][e]]:
        if t in te: continue
        print(te)
        t, e = te.split(':', 1)
        e = str((int(e[:1])+2)%4)
        break
    print(t, e[:1])
    tile_map[i][0] = t
print([tile_map[i][0] for i in range(12)])
t = '1621'
e = '3'
e = str((int(e[:1])+2)%4)
#t = '3793'
#e = '1'
#tile_map[1][0] = t
for i in range(1, 12):
    tile_set.add(t)
    ts = print_adj(t)
    print(t, ts - tile_set)
    for te in edges[tile_edges[t][e]]:
        if t in te: continue
        print(te)
        t, e = te.split(':', 1)
        e = str((int(e[:1])+2)%4)
        break
    print(t, e[:1])
    tile_map[0][i] = t
print(tile_map[0])
exit()
tile_set.add(t)
ts = print_adj(t)
print(t, ts - tile_set)
t = '2767'
tile_set.add(t)
ts = print_adj(t)
print(t, ts - tile_set)
t = '2113'
tile_set.add(t)
ts = print_adj(t)
print(t, ts - tile_set)
t = '1879'
tile_set.add(t)
ts = print_adj(t)
print(t, ts - tile_set)
exit()
#for i in range(12):
#    for j in range(12):
        
#nums = {}
#for e, v in edges.items():
#    #print(e, len(v), v)
#    if len(v) ==1:
#    #    print(e, v)
#        for n in v:
#            print(n)
#            nn = int(n[:n.find(':')])
#            nums[nn] = nums.get(nn, 0)+1
##total = 1
##for nn in nums:
##    if nums[nn] > 2:
##        print(nn)
##        total *= nn
##print(total)

