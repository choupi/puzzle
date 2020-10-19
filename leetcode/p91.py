# 91. Decode Ways
# https://leetcode.com/problems/decode-ways/

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        na=[0 for i in xrange(len(s)+1)]
        na[0]=1
        for i in xrange(1, len(s)+1):
            if int(s[i-1])>0: na[i]+=na[i-1]
            if i>1 and int(s[i-2:i])<27 and int(s[i-2:i])>9: na[i]+=na[i-2]
        return na[-1]
