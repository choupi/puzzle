import re

FIELDS = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']
ECLS = ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
PID = re.compile('^[0-9]{9}$')
HCL = re.compile('^#[0-9a-f]{6}')

def check_yr(dt, min_y, max_y):
    if len(dt) != 4:
        return False
    return min_y <= int(dt) <= max_y

def check_ecl(ecl):
    return ecl in ECLS

def check_hgt(hgt):
    if 'cm' in hgt:
        return 150 <= int(hgt[:-2]) <= 193
    elif 'in' in hgt:
        return 59 <= int(hgt[:-2]) <= 76
    return False

def check(data):
    valid = True
    for fd in FIELDS:
        if fd not in data:
            return False
    if not check_yr(data['byr'], 1920, 2002):
        return False
    if not check_yr(data['iyr'], 2010, 2020):
        return False
    if not check_yr(data['eyr'], 2020, 2030):
        return False
    if not check_hgt(data['hgt']):
        return False
    if not HCL.match(data['hcl']):
        return False
    if not check_ecl(data['ecl']):
        return False
    if not PID.match(data['pid']):
        return False
    return True

total = 0
data = {}
with open('input') as f:
    for l in f:
        if l.strip() == '':
            if check(data):
                total += 1
            data = {}
            continue
        sl = l.strip().split(' ')
        for ent in sl:
            fd, dt = ent.split(':', 1)
            data[fd] = dt

if check(data):
    total += 1
print(total)
