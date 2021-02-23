
OPS = ['+', '-', '*']

def do_op(res, n, op):
    if op == '+':
        return res+n
    elif op == '-':
        return res-n
    elif op == '*':
        return res*n
    return None

def calc(s):
    i = 0
    res = 0
    op = '+'
    while i < len(s):
        #print(i, op, s[i], res)
        if s[i] == '(':
            n, di = calc(s[i+1:])
            #print('(((', di, s[i+di+1])
            res = do_op(res, n, op)
            i += di + 2
            op = ''
            continue
        elif s[i] in OPS:
            op = s[i]
            i += 1
            continue
        elif '0' <= s[i] <= '9':
            si = i
            while i < len(s) and '0' <= s[i] <= '9':
                i += 1
            n = int(s[si:i])
            #print('nnn', i, op, n)
            res = do_op(res, n, op)
            op = ''
        elif s[i] == ')':
            return res, i
        else:
            #print('xxx', i, s[i])
            i += 1
    #print(res)
    return res, i

#print(calc('1 + 2 * 3 + 4 * 5 + 6'))
#print(calc('1 + (2 * 3) + (4 * (5 + 6))'))
#print(calc('2 * 3 + (4 * 5)'))
#print(calc('5 + (8 * 3 + 9 + 3 * 4 * 3)'))
#print(calc('5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))'))
#print(calc('((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2'))
total = 0
with open('input') as f:
    for l in f:
        res, _ = calc(l.strip())
        total += res
print(total)
