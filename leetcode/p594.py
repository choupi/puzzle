class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ns = Counter(nums)
        max_len = 0
        for i in ns:
            if i+1 in ns:
                max_len = max(max_len, ns[i]+ns[i+1])
        return max_len
