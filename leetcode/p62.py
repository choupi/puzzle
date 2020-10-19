# 62. Unique Paths
# https://leetcode.com/problems/unique-paths/


class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m==0 or n==0: return 0
        tab=[[0]*n for i in range (m)]
        for i in range(m): tab[i][0]=1
        for j in range(n): tab[0][j]=1
        for i in range(1,m):
            for j in range(1,n):
                tab[i][j]=tab[i][j-1]+tab[i-1][j]
        return tab[-1][-1]
