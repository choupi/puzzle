import math
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        for i in range(1, n):
            if n % i == 0:
                k -= 1
            if k == 0:
                return i
        if k == 1:
            return n
        return -1
