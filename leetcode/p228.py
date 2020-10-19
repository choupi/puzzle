# 228. Summary Ranges
# https://leetcode.com/problems/summary-ranges/


class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        r=[]
        s=0
        for i in xrange(1,len(nums)+1):
            if i==len(nums) or nums[i]!=nums[i-1]+1:
                if s==i-1: r.append(str(nums[s]))
                else: r.append('%d->%d'%(nums[s],nums[i-1]))
                s=i
        return r
