valid_cnt = 0
with open('input') as f:
    for l in f:
        policy, passwd = l.strip().split(': ', 1)
        limits, ch = policy.split(' ', 1)
        idx1, idx2 = limits.split('-', 1)
        idx1 = int(idx1)-1
        idx2 = int(idx2)-1
        if (passwd[idx1] == ch or passwd[idx2] == ch) and not (passwd[idx1] == ch and passwd[idx2] == ch):
            valid_cnt += 1
print(valid_cnt)
