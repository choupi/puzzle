class Solution:
    def checkRecord(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 3
        M = 10**9 + 7
        tab = [[0]*3 for i in range(n)]
        tab[0] = [1, 1, 0]
        for i in range(1, n):
            # P
            tab[i][0] = sum(tab[i-1]) % M
            # PL
            tab[i][1] = tab[i-1][0]
            # LL
            tab[i][2] = tab[i-1][1]
        total = 0
        for i in range(n):
            if i == 0:
                total += sum(tab[n-2])
            elif i == n-1:
                total += sum(tab[n-2])
            else:
                total += (sum(tab[i-1])%M) * (sum(tab[n-i-2])%M)
            total = total % M
        #print(tab)
        total += sum(tab[n-1])%M
        return total%M
