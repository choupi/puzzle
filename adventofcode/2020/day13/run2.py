
def find_mm(m, n):
    # mm = k*m => mm % n == 1
    # Extended Euclidean algorithm ?
    r0, r1 = m, n
    s0, s1 = 1, 0
    t0, t1 = 0, 1
    while r1 > 1:
        q = r0 // r1
        r0, r1 = r1, r0 - q*r1
        s0, s1 = s1, s0 - q*s1
        t0, t1 = t1, t0 - q*t1
    if s1 < 0:
        mm = (s1+n)*m
    else:
        mm = s1 * m
    print(mm, mm%n)
    return mm

#find_mm(12, 7)
#find_mm(13, 7)
#find_mm(25, 7)
#find_mm(45, 7)
#find_mm(85, 7)
#exit()

nums = []
with open('input') as f:
#with open('inp5') as f:
    l = f.readline()
    ts = int(l)
    l = f.readline()
    sl = l.split(',')
    for i, b in enumerate(sl):
        if b == 'x':
            continue
        bus = int(b)
        a = (bus - i) % bus
        nums.append((int(b), a))
print(nums)
#print(len(nums))
M = 1
for n, a in nums:
    M *= n
print(M)
S = 0
for n, a in nums:
    m = M//n
    print(M, n, m, m % n)
    # mm = k*m => mm % n == 1
    mm = find_mm(m, n)
    S += (mm*a) % M
r = S%M
print(S, r)
for n, a in nums:
    print(n, a, r%n)
print(r)
