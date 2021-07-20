import math
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        if target < 2:
            return target
        n = math.sqrt(target*2)
        n = math.floor(n)
        s = n*(n+1)/2
        while s < target:
            n += 1
            s += n
        if (s - target)%2 == 0:
            return n
        else:
            if n % 2 == 0:
                return n+1
            else:
                return n+2
