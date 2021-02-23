valid_cnt = 0
with open('input') as f:
    for l in f:
        policy, passwd = l.strip().split(': ', 1)
        limits, ch = policy.split(' ', 1)
        min_c, max_c = limits.split('-', 1)
        min_c = int(min_c)
        max_c = int(max_c)
        cnt = sum([1 if c==ch else 0 for c in passwd])
        if min_c <= cnt <= max_c:
            valid_cnt += 1
print(valid_cnt)
