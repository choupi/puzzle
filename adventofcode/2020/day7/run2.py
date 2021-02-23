def dfs(bag):
    if bag in bag_result:
        return bag_result[bag]
    s = 1
    if bag not in bag_dict or not bag_dict[bag]:
        #print(bag)
        bag_result[bag] = s
        return s
    for b,v in bag_dict[bag].items():
        if b in bag_result:
            bs = bag_result[b]
        else:
            bs = dfs(b)
        s += bs * v
    bag_result[bag] = s
    return s

bag_dict = {}
with open('input.txt') as f:
#with open('inp') as f:
    for l in f:
        if 'no other bags.' in l:
            continue
        bag, contains = l.strip().split(' contain ', 1)
        bag = bag[:bag.rindex(' ')]
        #print(bag)
        contain_dict = {}
        for c in contains.split(', '):
            sc = c.split(' ')
            bc = ' '.join(sc[1:-1])
            v = int(sc[0])
            contain_dict[bc] = v
        #print(bag, contains)
        bag_dict[bag] = contain_dict
#print(len(bag_dict))
bag_result = {}
r = dfs('shiny gold')
print(r-1)
