class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        nc = Counter(nums)
        ns = [c for c in nc if nc[c]==1]
        return ns
