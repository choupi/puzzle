x = 3
i = 0
cnt = 0
with open('input') as f:
    for l in f:
        #print(len(l.strip()), i)
        if l[i] == '#':
            cnt += 1
        i = (i+x) % len(l.strip())
print(cnt)
