FIELDS = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

def check(data):
    valid = True
    for fd in FIELDS:
        if fd not in data:
            valid = False
    return valid

total = 0
data = set()
with open('input') as f:
    for l in f:
        if l.strip() == '':
            if check(data):
                total += 1
            data = set()
            continue
        sl = l.strip().split(' ')
        for ent in sl:
            fd, _ = ent.split(':', 1)
            data.add(fd)

if check(data):
    total += 1
print(total)
