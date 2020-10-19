# 231. Power of Two
# https://leetcode.com/problems/power-of-two/


class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        p = 1
        while p < n:
            p = p << 1
        return p==n
