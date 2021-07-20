class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n < 0:
            return False
        c = 1
        while c <= n:
            if c == n:
                return True
            c *= 3
        return False
