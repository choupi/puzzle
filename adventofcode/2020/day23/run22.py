
def pick3(n):
   nn = n
   ns = set()
   for i in range(2):
       ns.add(nn)
       nn = num_dict[nn]
   ns.add(nn)
   return ns, n, nn

def findx(ns, x):
    if x < min_x:
        x = max_x
    while x in ns:
        x -= 1
        if x < min_x:
            x = max_x
    return x

def mprint(n):
    n1 = num_dict[n]
    n2 = num_dict[n1]
    print(n1, n2)
    print(n1*n2)

num_dict = {}
#nums = '389125467'
nums = '247819356'
nums = [int(c) for c in nums] + [i for i in range(10, 1000001)]
head = None
tmp = None
max_x = float('-inf')
min_x = float('inf')
for n in nums:
    if head is None:
        head = n
    if tmp:
        num_dict[tmp] = n
    if n > max_x:
        max_x = n
    if n < min_x:
        min_x = n
    tmp = n
print(max_x, min_x)
num_dict[tmp] = head

cur = head
for i in range(10000000):
    ns, p1, p3 = pick3(num_dict[cur])
    dst = findx(ns, cur-1)
    num_dict[cur] = num_dict[p3]
    num_dict[p3] = num_dict[dst]
    num_dict[dst] = p1
    cur = num_dict[cur]
mprint(1)
