# 321. Create Maximum Number
# https://leetcode.com/problems/create-maximum-number/


class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        self.max_list = []
        for i in range(0, k+1):
            if i>len(nums1) or (k-i)>len(nums2): continue
            p1 = self.findMax(nums1, i)
            p2 = self.findMax(nums2, k-i)
            m = self.merge(p1, p2, k)
            #print(m)
            if m>self.max_list:
                self.max_list=m
        return self.max_list
    
    def findMax(self, nums, k):
        n_list = []
        for i, v in enumerate(nums):
            while n_list and n_list[-1] < v and (len(nums) - i) + len(n_list) > k:
                n_list.pop(-1)
            n_list.append(v)
        #print(n_list)
        #print(k, len(n_list))
        return n_list[:k]

    def merge(self, p1, p2, k):
        n_list = []
        for i in range(k):
            a = max(p1, p2).pop(0)
            n_list.append(a)
        return n_list
