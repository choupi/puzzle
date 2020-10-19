# 165. Compare Version Numbers
# https://leetcode.com/problems/compare-version-numbers/


class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1=[int(i) for i in version1.split('.')]
        v2=[int(i) for i in version2.split('.')]
        if len(v1)<len(v2): v1+=[0 for i in xrange(len(v2)-len(v1))]
        elif len(v1)>len(v2): v2+=[0 for i in xrange(len(v1)-len(v2))]
        for i in xrange(min(len(v1), len(v2))):
            if v1[i]>v2[i]: return 1
            elif v1[i]<v2[i]: return -1
        return 0
