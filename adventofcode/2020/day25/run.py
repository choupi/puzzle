
def trans(sub, loop):
    n = 1
    for i in range(loop):
        n = (n*sub) % 20201227
    return n

def find_loop(sub, pk1, pk2):
    n = 1
    for i in range(10000000):
        n = (n*sub) % 20201227
        #print(n)
        #if n == 19241437 or n == 17346587:
        if n == pk1 or n == pk2:
            print(i, n)
            return i+1
    return -1
print(trans(17807724, 8))
#trans(7, 10000000)
l = find_loop(7, 19241437, 17346587)
print(l)
print(trans(17346587, l))
#print(trans(19241437, l))
