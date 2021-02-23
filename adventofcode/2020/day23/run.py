
class Node:
    def __init__(self, label):
        self.label = label
        self.next = None

def pick3(node):
   nn = node
   ns = set()
   for i in range(2):
       ns.add(nn.label)
       nn = nn.next
   ns.add(nn.label)
   return ns, node, nn 

def findx(ns, x):
    if x < min_x:
        x = max_x
    while x in ns:
        x -= 1
        if x < min_x:
            x = max_x
    return num_dict[x]

def mprint(nn):
    while nn.label != 1:
        nn = nn.next
    ll = []
    for i in range(len(num_dict)):
        ll.append(nn.label)
        nn = nn.next
    print(''.join(list(map(str, ll))))

num_dict = {}
#nums = '389125467'
nums = '247819356'
head = None
tmp = None
max_x = float('-inf')
min_x = float('inf')
for n in nums:
    n = int(n)
    nn = Node(n)
    if head is None:
        head = nn
    if tmp:
        tmp.next = nn
    num_dict[n] = nn
    if n > max_x:
        max_x = n
    if n < min_x:
        min_x = n
    tmp = nn
print(max_x, min_x)
tmp.next = head

cur = head
for i in range(100):
    ns, p1, p3 = pick3(cur.next)
    dst = findx(ns, cur.label-1)
    cur.next = p3.next
    p3.next = dst.next
    dst.next = p1
    cur = cur.next
mprint(cur)
