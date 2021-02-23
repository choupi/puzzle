instructions = []
with open('input') as f:
    for l in f:
        ins, num = l.strip().split(' ', 1)
        instructions.append((ins, int(num)))
i = 0
a = 0
jmp_set = set()
while True:
    if i in jmp_set:
        break
    jmp_set.add(i)
    ins, num = instructions[i]
    if ins == 'nop':
        i += 1
    elif ins == 'acc':
        a += num
        i += 1
    elif ins == 'jmp':
        i += num
print(a)
