# 50. Pow(x, n)
# https://leetcode.com/problems/powx-n/

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if x==0 and n>0: return 0
        if x==0 and n<0: return float('inf')
        if n==0: return 1
        sign=1.0
        if x<0: 
            if n%2>0: sign=-1.0
            x=0-x
        inv=False
        if n<0:
            inv=True
            n=0-n
        f=1
        xx=x
        while n>0:
            #print xx, n
            if n%2==1: f*=xx
            n=n/2
            xx=xx*xx
        #print inv, f
        if inv: return sign/f
        return f*sign
