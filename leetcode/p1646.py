class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0:
            return 0
        nums = [0]*(n+1)
        nums[1] = 1
        for i in range(2, n+1):
            ii = i//2
            if i%2 == 0:
                nums[i] = nums[ii]
            else:
                nums[i] = nums[ii] + nums[ii+1]
        #print(nums)
        return max(nums)
