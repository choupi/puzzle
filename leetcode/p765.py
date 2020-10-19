# 765. Couples Holding Hands
# https://leetcode.com/problems/couples-holding-hands/


class Solution(object):
    def initSet(self, n):
        return [i for i in range(n)]
    
    def findSet(self, a, i):
        stack=[]
        idx=i
        while True:
            if a[idx]==idx:
                s=idx
                break
            else:
                stack.append(idx)
                idx=a[idx]
        for idx in stack:
            a[idx]=s
        return s
    
    def joinSet(self, a, i, j):
        if i==j: return i
        si=self.findSet(a, i)
        sj=self.findSet(a, j)
        s=min(si, sj)
        sm=max(si, sj)
        a[sm]=s
    
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        n=len(row)
        disjoin=self.initSet(n/2)
        for i in range(0, n, 2):
            i1=row[i]/2
            i2=row[i+1]/2
            self.joinSet(disjoin, i1, i2)
        #print disjoin
        n_dict={}
        for i in range(n/2):
            s=self.findSet(disjoin, i)
            n_dict[s]=n_dict.get(s, 0)+1
        #print n_dict
        ex_cnt=0
        for i in n_dict:
            ex_cnt+=n_dict[i]-1
        return ex_cnt
