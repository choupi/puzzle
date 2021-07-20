class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nc = Counter(nums)
        ns = [c for c in nc if nc[c]>1]
        return len(ns)>0
