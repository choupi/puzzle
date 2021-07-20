class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        res = []
        kk = k - n
        for i in range(n):
            kk += 1
            if kk > 26:
                res.append('z')
                kk -= 26
            else:
                res.append(chr(96+kk))
                kk = 0
        res.reverse()
        return ''.join(res)
