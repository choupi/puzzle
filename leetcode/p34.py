# 34. Find First and Last Position of Element in Sorted Array
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        si=0
        ei=len(nums)
        while ei-si>1:
            mid=(si+ei)/2
            if nums[mid]>target:
                ei=mid
            elif nums[mid]<target:
                si=mid+1
            elif nums[mid]==target:
                ei=mid
                si=mid
                break
        pivot=(si+ei)/2
        if pivot>=len(nums) or nums[pivot]!=target:
            return [-1, -1]
        si=0
        ei=pivot
        t=target-0.1
        while ei-si>1:
            mid=(si+ei)/2
            if nums[mid]>t:
                ei=mid
            elif nums[mid]<t:
                si=mid+1
        pivot_l=si if nums[si]==target else si+1
        si=pivot
        ei=len(nums)
        t=target+0.1
        while ei-si>1:
            mid=(si+ei)/2
            if nums[mid]>t:
                ei=mid
            elif nums[mid]<t:
                si=mid+1
        pivot_r=si if si<len(nums) and nums[si]==target else si-1
        return [pivot_l, pivot_r]
