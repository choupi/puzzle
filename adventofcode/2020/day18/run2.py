
OPS = ['+', '-', '*']

def oper(n1, n2, op):
    if op == '+':
        return n1+n2
    elif op == '-':
        return n2-n1
    elif op == '*':
        return n1*n2
    return None

def do_op(op_stack, num_stack):
    op = op_stack.pop(-1)
    n1 = num_stack.pop(-1)
    n2 = num_stack.pop(-1)
    num_stack.append(oper(n1, n2, op))

def calc(s):
    i = 0
    num_stack = []
    op_stack = []
    while i < len(s):
        #print(i, op, s[i], res)
        if s[i] == '(':
            n, di = calc(s[i+1:])
            num_stack.append(n)
            #print('(((', di, s[i:i+di+1], '=', n)
            i += di + 1
            continue
        elif s[i] in OPS:
            while op_stack and op_stack[-1] >= s[i]:
                do_op(op_stack, num_stack)
            op_stack.append(s[i])
            i += 1
            continue
        elif '0' <= s[i] <= '9':
            si = i
            while i < len(s) and '0' <= s[i] <= '9':
                i += 1
            n = int(s[si:i])
            #print('nnn', i, op, n)
            num_stack.append(n)
        elif s[i] == ')':
            while op_stack:
                do_op(op_stack, num_stack)
            if len(num_stack)>1:
                print('!!!')
            return num_stack[0], i+1
        else:
            #print('xxx', i, s[i])
            i += 1
    #print(res)
    while op_stack:
        do_op(op_stack, num_stack)
    if len(num_stack)>1:
        print('!!!')
    return num_stack[0], i

#print(calc('9 + 7 + (7 + (3 + 8 + 9)) + 8 * 4'))
#print(calc('1 + 2 * 3 + 4 * 5 + 6'))
#print(calc('1 + (2 * 3) + (4 * (5 + 6))'))
#print(calc('2 * 3 + (4 * 5)'))
#print(calc('5 + (8 * 3 + 9 + 3 * 4 * 3)'))
#print(calc('5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))'))
#print(calc('((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2'))
#exit()
total = 0
with open('input') as f:
    for l in f:
        res, _ = calc(l.strip())
        #print(res, l.strip())
        total += res
print(total)
