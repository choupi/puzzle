class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        min_nums = []
        for i in range(len(nums)):
            while min_nums and nums[i] < min_nums[-1] and len(nums) - i >= k - len(min_nums) + 1:
                min_nums.pop(-1)
            if len(min_nums) < k:
                min_nums.append(nums[i])
        return min_nums
