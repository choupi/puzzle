def count_trees(x, y):
    i = 0
    j = -1
    cnt = 0
    with open('input') as f:
        for l in f:
            #print(len(l.strip()), i)
            j += 1
            if j % y != 0:
                continue
            if l[i] == '#':
                cnt += 1
            i = (i+x) % len(l.strip())
    return cnt

c1 = count_trees(1, 1)
c2 = count_trees(3, 1)
c3 = count_trees(5, 1)
c4 = count_trees(7, 1)
c5 = count_trees(1, 2)
print(c1, c2, c3, c4, c5, c1*c2*c3*c4*c5)
