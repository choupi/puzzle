# 221. Maximal Square
# https://leetcode.com/problems/maximal-square/

class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m=len(matrix)
        if m<1: return 0
        n=len(matrix[0])
        #print m, n
        tab=[[0]*n for i in range(m)]
        max_area=0
        for i in range(m):
            #print matrix[i][0]
            if matrix[i][0]=='1': tab[i][0]=1
            if tab[i][0]>max_area: max_area=tab[i][0]
        for i in range(n):
            if matrix[0][i]=='1': tab[0][i]=1
            if tab[0][i]>max_area: max_area=tab[0][i]
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j]=='1':
                    mm=min(tab[i-1][j-1], tab[i-1][j], tab[i][j-1])
                    tab[i][j]=mm+1
                    if tab[i][j]>max_area: max_area=tab[i][j]
        #print tab
        return max_area*max_area
