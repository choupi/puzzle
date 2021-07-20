class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        j = len(nums) - 1
        while i > 0 and nums[i-1] >= nums[i]:
            i -= 1
        if i<=0:
            #print('restart')
            nums.reverse()
            return
        while nums[j] <= nums[i-1]:
            j -= 1
        nums[i-1], nums[j] = nums[j], nums[i-1]
        nums[i:] = nums[len(nums)-1:i-1:-1]
        return
