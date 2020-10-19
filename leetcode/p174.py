# 174. Dungeon Game
# https://leetcode.com/problems/dungeon-game/


class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m=len(dungeon)
        if dungeon: n=len(dungeon[0])
        else: return 1
        tab=[[0]*n for i in range(m)]
        tab[-1][-1]=max(1, 1-dungeon[-1][-1])
        for i in range(m-2, -1, -1): tab[i][-1]=max(1, tab[i+1][-1]-dungeon[i][-1])
        for j in range(n-2, -1, -1): tab[-1][j]=max(1, tab[-1][j+1]-dungeon[-1][j])
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                m=min(tab[i+1][j], tab[i][j+1])
                tab[i][j]=max(1, m-dungeon[i][j])
        #print tab
        return tab[0][0]
