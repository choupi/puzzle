

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n<=0: return False
        nb=bin(n)
        if nb.count('1')<2: return True
        else: return False
