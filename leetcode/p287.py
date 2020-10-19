# 287. Find the Duplicate Number
# https://leetcode.com/problems/find-the-duplicate-number/


class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        sn=1
        en=n-1
        while en-sn>0:
            lc=0
            gc=0
            ec=0
            pivot=(en+sn)/2.0
            #print sn, en, pivot
            for v in nums:
                if v>pivot and v<=en: gc+=1
                elif v<pivot and v>=sn: lc+=1
                elif v==pivot: ec+=1
                if ec>1: return int(pivot)
            #print lc, gc
            if lc>gc: en=int(pivot)
            elif lc<gc: 
                sn=int(pivot+1)
        return en
