# 69. Sqrt(x)
# https://leetcode.com/problems/sqrtx/


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0: return 0
        st=1
        ed=x
        while st<ed-1:
            med=(st+ed)/2
            #print st, ed, med
            mm=med*med
            if mm==x: return med
            elif mm>x: ed=med
            elif mm<x: st=med
        return st
