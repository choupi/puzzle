class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ns1 = set(nums1)
        ns2 = set(nums2)
        return list(ns1 & ns2)
