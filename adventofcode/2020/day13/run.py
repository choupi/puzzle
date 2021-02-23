min_d = float('inf')
min_b = 0
with open('input') as f:
    l = f.readline()
    ts = int(l)
    l = f.readline()
    sl = l.split(',')
    for b in sl:
        if b == 'x':
            continue
        bus = int(b)
        d = bus - (ts % bus)
        print(ts, bus, ts%bus, d)
        if d < min_d:
            min_d = d
            min_b = bus
print(min_d, min_b, min_d*min_b)
