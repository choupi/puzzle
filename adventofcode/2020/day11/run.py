import copy

def occupied(seat_map, i, j):
    return seat_map[i][j] == '#'

def check_occupied(seat_map, i, j, nr, nc):
    for ti in range(max(0, i-1), min(i+2, nr)):
        for tj in range(max(0, j-1), min(j+2, nc)):
            if ti == i and tj == j:
                continue
            #print(ti, tj)
            if occupied(seat_map, ti, tj):
                return True
    return False

def check_adjacent(seat_map, i, j, nr, nc):
    cnt = 0
    for ti in range(max(0, i-1), min(i+2, nr)):
        for tj in range(max(0, j-1), min(j+2, nc)):
            if ti == i and tj == j:
                continue
            if occupied(seat_map, ti, tj):
                cnt += 1
    return cnt > 3

seat_map = []
#with open('inp') as f:
with open('input') as f:
    for l in f:
        ll = [c for c in l.strip()]
        seat_map.append(ll)
nr = len(seat_map)
nc = len(seat_map[0])

chg = 1
while chg > 0:
    chg = 0
    new_seat_map = copy.deepcopy(seat_map)
    #for s in new_seat_map: print(''.join(s))
    #print('------------------')
    for i in range(nr):
        for j in range(nc):
            if seat_map[i][j] == '.':
                new_seat_map[i][j] = '.'
            elif seat_map[i][j] == 'L':
                if not check_occupied(seat_map, i, j, nr, nc):
                    new_seat_map[i][j] = '#'
                    chg += 1
            elif seat_map[i][j] == '#':
                if check_adjacent(seat_map, i, j, nr, nc):
                    new_seat_map[i][j] = 'L'
                    chg += 1
    seat_map = new_seat_map
cnt = 0
for i in range(nr):
    for j in range(nc):
        if seat_map[i][j] == '#':
            cnt += 1
print(cnt)
