def run(instructions):
    i = 0
    a = 0
    jmp_set = set()
    loop = False
    while i < len(instructions):
        if i in jmp_set:
            loop = True
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
    return a, loop

instructions = []
with open('input') as f:
    for l in f:
        ins, num = l.strip().split(' ', 1)
        instructions.append((ins, int(num)))
jmps = []
for i, v in enumerate(instructions):
    ins, num = v
    if ins == 'jmp' or ins == 'nop':
        jmps.append(i)
#print(len(jmps))
for i in jmps:
    ins, num = instructions[i]
    if ins == 'jmp':
        instructions[i] = ('nop', num)
    elif ins == 'nop':
        instructions[i] = ('jmp', num)
    a, loop = run(instructions)
    if not loop:
        print(i, ins, num)
        print(a)
        break
    instructions[i] = (ins, num)
