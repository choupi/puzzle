class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        res = 1
        for i in range(n):
            r = 9
            for j in range(i):
                r *= 9-j
            res += r
        return res
