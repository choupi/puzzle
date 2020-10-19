# 72. Edit Distance
# https://leetcode.com/problems/edit-distance/


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if len(word1)==0: return len(word2)
        elif len(word2)==0: return len(word1)
        tab=[[0]*(len(word2)+1) for i in range(len(word1)+1)]
        for i in range(len(word1)+1): tab[i][0]=i
        for i in range(len(word2)+1): tab[0][i]=i
        #print tab
        for i in range(len(word1)):
            for j in range(len(word2)):
                #print word1[i], word2[j]
                m=tab[i][j]
                if word1[i]!=word2[j]:
                    m+=1
                tab[i+1][j+1]=min(m, tab[i][j+1]+1, tab[i+1][j]+1)
            #print tab
        return tab[-1][-1]
