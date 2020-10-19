# 202. Happy Number
# https://leetcode.com/problems/happy-number/

class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        d={'1':1}
        s=n
        while str(s) not in d:
            d[str(s)]=1
            s=sum([int(i)**2 for i in str(s)])
        return s==1
