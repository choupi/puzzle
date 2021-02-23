def dfs(bag):
    if bag == 'shiny gold':
        bag_result[bag] = 1
        return 1
    if bag in bag_result:
        return bag_result[bag]
    if bag not in bag_dict or not bag_dict[bag]:
        #print(bag)
        bag_result[bag] = 0
        return 0
    for b in bag_dict[bag]:
        if b in bag_result and bag_result[b] == 1:
            bag_result[bag] = 1
            return 1
        if dfs(b):
            bag_result[bag] = 1
            return 1
    return 0

bag_dict = {}
with open('input.txt') as f:
#with open('inp') as f:
    for l in f:
        if 'no other bags.' in l:
            continue
        bag, contains = l.strip().split(' contain ', 1)
        bag = bag[:bag.rindex(' ')]
        #print(bag)
        contains = [' '.join(c.split(' ')[1:-1]) for c in contains.split(', ')]
        #print(bag, contains)
        bag_dict[bag] = contains
#print(len(bag_dict))
bag_result = {}
for bag in bag_dict:
    if bag in bag_result:
        continue
    dfs(bag)
print(sum([v for b,v in bag_result.items()])-1)
