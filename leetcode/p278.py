# 278. First Bad Version
# https://leetcode.com/problems/first-bad-version/

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):


class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = 1
        e = n
        p = (s+e)/2
        while s!=e:
            if isBadVersion(p): e = p
            else: s = p + 1
            p = (s+e)/2
        return p
