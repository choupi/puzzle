# 93. Restore IP Addresses
# https://leetcode.com/problems/restore-ip-addresses/

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res=[]
        for i in range(1, len(s)):
            #print i, s[:i]
            if int(s[:i])>255: break
            if i>1 and s[0]=='0': break
            for j in range(i+1, len(s)):
                #print i, j, s[i:j]
                if int(s[i:j])>255: break
                if j-i>1 and s[i]=='0': break
                for k in range(j+1, len(s)):
                    #print i, j, k, s[j:k], s[k:]
                    if int(s[j:k])>255: break
                    if k-j>1 and s[j]=='0': break
                    if int(s[k:])>255: continue
                    if len(s)-k>1 and s[k]=='0': continue
                    res.append('.'.join([s[:i], s[i:j], s[j:k], s[k:]]))
                    #print '.'.join([s[:i], s[i:j], s[j:k], s[k:]])
        return res
