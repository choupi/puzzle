class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s = str(n)
        min_i = None
        for t in itertools.permutations(s):
            #print(t)
            i = int(''.join(t))
            if i > n and i < 2**31:
                if min_i is None:
                    min_i = i
                elif i < min_i:
                    min_i = i
        if min_i is None:
            return -1
        return min_i
