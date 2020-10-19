# 41. First Missing Positive
# https://leetcode.com/problems/first-missing-positive/


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        for idx in range(len(nums)):
            while nums[idx]!=idx+1:
                #print nums[idx], idx
                if nums[idx]>0 and nums[idx]<len(nums)+1:
                    #print nums[nums[idx]-1], nums[idx], idx
                    tmp=nums[nums[idx]-1]
                    if tmp==nums[idx]:
                        nums[idx]=0
                        break
                    nums[nums[idx]-1]=nums[idx]
                    nums[idx]=tmp
                else:
                    nums[idx]=0
                    break
        for i in range(len(nums)):
            if nums[i]<1: return i+1
        return len(nums)+1
