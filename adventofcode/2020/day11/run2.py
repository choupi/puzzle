import copy

def occupied(seat_map, i, j):
    return seat_map[i][j] == '#'

def check_occupied(seat_map, i, j, nr, nc):
    cnt = 0
    for ti in range(i-1, -1, -1):
        if seat_map[ti][j] == 'L':
            break
        if occupied(seat_map, ti, j):
            cnt += 1
            break
    for ti in range(i+1, nr):
        if seat_map[ti][j] == 'L':
            break
        if occupied(seat_map, ti, j):
            cnt += 1
            break
    for tj in range(j-1, -1, -1):
        if seat_map[i][tj] == 'L':
            break
        if occupied(seat_map, i, tj):
            cnt += 1
            break
    for tj in range(j+1, nc):
        if seat_map[i][tj] == 'L':
            break
        if occupied(seat_map, i, tj):
            cnt += 1
            break
    ti = i-1
    tj = j-1
    while ti>=0 and tj>=0:
        if seat_map[ti][tj] == 'L':
            break
        if occupied(seat_map, ti, tj):
            cnt += 1
            break
        ti = ti-1
        tj = tj-1
    ti = i+1
    tj = j+1
    while ti<nr and tj<nc:
        if seat_map[ti][tj] == 'L':
            break
        if occupied(seat_map, ti, tj):
            cnt += 1
            break
        ti = ti+1
        tj = tj+1
    ti = i-1
    tj = j+1
    while ti>=0 and tj<nc:
        if seat_map[ti][tj] == 'L':
            break
        if occupied(seat_map, ti, tj):
            cnt += 1
            break
        ti = ti-1
        tj = tj+1
    ti = i+1
    tj = j-1
    while ti<nr and tj>=0:
        if seat_map[ti][tj] == 'L':
            break
        if occupied(seat_map, ti, tj):
            cnt += 1
            break
        ti = ti+1
        tj = tj-1
    return cnt

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

count_map = [[0]*nc for i in range(nr)]
count_map[0][0] = 1
chg = 1
while chg > 0:
    chg = 0
    for i in range(nr):
        for j in range(nc):
            #print(i, j, seat_map[i][j])
            if seat_map[i][j] == '.':
                count_map[i][j] = -1
            #elif seat_map[i][j] == 'L' or seat_map[i][j] == '#':
            else:
                count_map[i][j] = check_occupied(seat_map, i, j, nr, nc)
    #print(count_map)
    for i in range(nr):
        for j in range(nc):
            if seat_map[i][j] == '#':
                if count_map[i][j] > 4:
                    seat_map[i][j] = 'L'
                    chg += 1
            elif seat_map[i][j] == 'L':
                if count_map[i][j] == 0:
                    seat_map[i][j] = '#'
                    chg += 1
    #print(seat_map)
cnt = 0
for i in range(nr):
    for j in range(nc):
        if seat_map[i][j] == '#':
            cnt += 1
print(cnt)
