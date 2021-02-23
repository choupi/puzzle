RULES = {}
RULE_CACHE = {}

def gen_rule(rule_id):
    if rule_id in RULE_CACHE:
        return RULE_CACHE[rule_id]
    res = set()
    for rule in RULES[rule_id]:
        #print('rule', rule)
        cur_res = []
        for r in rule:
            #print(r, r.isnumeric())
            if r.isnumeric():
                new_res = gen_rule(r)
                #print('new res', r, new_res)
                if len(cur_res) ==0:
                    cur_res = list(new_res)
                else:
                    cur_res = [r0+r1 for r0 in cur_res for r1 in new_res]
                #print('new cur res', cur_res)
            else:
                if len(cur_res) ==0:
                    cur_res.append(r)
                else: print('!!!')
        #print(cur_res)
        for r in cur_res:
            res.add(r)
    RULE_CACHE[rule_id] = res
    return res

with open('input') as f:
    for l in f:
        if l.strip()=='':
            break
        rule_id, sl = l.strip().split(': ', 1)
        rule_list = sl.split(' | ')
        #rules = [r.split() for r in rules]
        rules = []
        for rule in rule_list:
            r = rule.split()
            rules.append([rr.strip('"') for rr in r])
        RULES[rule_id] = rules
    #print(RULES)
    res = gen_rule('0')
    print(len(res))
    total = 0
    for l in f:
        if l.strip() in res:
            total += 1
print(total)
